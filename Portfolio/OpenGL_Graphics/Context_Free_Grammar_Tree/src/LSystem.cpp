/**
 * @file LoadObj.h
 * @brief This file contains the implementations needed for generating the LSystem context free grammar.
 * @author Clayton Seelenmayer
 * @date Dec 1st 2018
 */

//Libraries
#include "LSystem.h"
using namespace std;

//Load L System
bool LSystem::LoadSystem(string Path){

	//Open File
	ifstream File ("Data/LSystem.txt"); //(Path)
	if (!File)
		return false;

	//Ignore Comments
	bool Begin = false;
	while (Begin == false){
		string Comment;
		getline(File, Comment);
		if (Comment == FileStart)
			Begin = true;
	}

	//Get Data
	string Data;
	while (getline(File, Data)){

		//If File has content
		if (!File.eof()){

			//Find Command by copying non-space contents before delimeter
			string Command;
			int i;
			for (i=0 ; Data[i]!=':' ; i++)
				if (Data[i] != ' '){
					Command.append(1, Data[i]);
				}

			//Find Specifications by copying the rest of the line
			string Temp;
			string Details;
			Temp = Data.substr(i+2);
			//Clean Spaces
			for (int j=0 ; j<Temp.size() ; j++)
				if (Temp[j] != ' '){
					Details.append(1, Temp[j]);
				}

			//Seed
			//Format is "SEED::DATA"
			if (Command == "Seed")
				Seed = Details;

			//Angle
			//Format is "ANGLE::AXIS::NAME=DATA"
			//Store Data into a string before converting to int
			if (Command == "Angle"){
				Angles NewAngle;
				//Name
				NewAngle.Name = Details[3];
				//Axis
				NewAngle.Axis = Details[0];
				//Data
				string AngleString;
				AngleString.append(1, Details[5]);
				AngleString.append(1, Details[6]);
				AngleString.append(1, Details[7]);
				NewAngle.Data = stoi(AngleString);
				//Push
				AngleList.push_back(NewAngle);
			}

			//Rule
			//Format is "RULE::LENGTH::NAME=DATA"
			//Append from Data to the Rule
			if (Command == "Rule"){
				Rules NewRule;
				//Name
				NewRule.Name = Details[4];
				//Length
				string LengthString;
				LengthString.append(1, Details[0]);
				LengthString.append(1, Details[1]);
				NewRule.Length = stoi(LengthString);
				//Data
				for (int j=6 ; j<Details.size() ; j++)
					NewRule.Data.append(1, Details[j]);
				RuleList.push_back(NewRule);
			}
		}
	}
	Tree = Seed;
	return true;
}

//Display
void LSystem::Display(){

	//Trees
	cout   << endl << endl;
	cout   << "**********************************************" << endl;
	cout   << "*   Tree is: " << endl << "*      " << Tree << endl;
	cout   << "*" << endl;
	cout   << "*   Seed is: " << endl << "*      " << Seed << endl;
	cout   << "*" << endl;
	cout   << "*   Depth is: " << Depth << endl;
	cout   << "*" << endl;
	cout   << "*   New branch is denoted by \"(\"" << endl;
	cout   << "*   Return from branch denoted by \")\"" << endl;
	cout   << "*" << endl;

	//Angles
	for (int i=0 ; i<AngleList.size() ; i++){
		cout << "*   Angle " << i+1 << " is: " << endl;
		cout << "*      " << AngleList[i].Name << " = " << AngleList[i].Data
				 << " degrees on axis " << AngleList[i].Axis << "." << endl;
	}
	cout << "*" << endl;

	//Rules
	for (int i=0 ; i<RuleList.size() ; i++){
		cout << "*   Rule " << i+1 << " is: " << endl;
		cout << "*      Draw Length: " << RuleList[i].Length << endl;
		cout << "*      " << RuleList[i].Name << " = " << RuleList[i].Data << endl;
	}
	cout   << "**********************************************" << endl;
}

//Update
void LSystem::Update(){

	//Base
	Tree = Seed;

	//For each Depth
	for(int i=1 ; i<Depth ; i++){

		//For each element in the tree
		int Size = Tree.size();
		string Temp;
		for (int j=0 ; j<Size ; j++){

			//For each rule in the list
			bool FoundRule = false;
			for (int k=0 ; k<RuleList.size() ; k++){

				//Insert new data
				if(Tree[j] == RuleList[k].Name){
					Temp.append(RuleList[k].Data);
					FoundRule = true;
				}
			}
			if (!FoundRule){
				Temp.append(1, Tree[j]);
			}
		}

		//Update
		Tree = Temp;
	}
}

//Draw System
void LSystem::BuildSystem(){

	//Reset
	PointList.clear();
	PairList.clear();
	stack<Point> PointStack;
	vector3 Position     = DefaultPosition;
	vector3 Direction    = DefaultDirection;
	int     CurrentDepth = DefaultDepth;

	//Base
	Point InitialPoint;
	InitialPoint.Position  = Position;
	InitialPoint.Direction = Direction;
	InitialPoint.Depth     = CurrentDepth;
	PointList.push_back(InitialPoint);

	//For Each Instruction
	for (int i=0 ; i<Tree.size() ; i++){

		//New Branch
		if (Tree[i] == '('){
			//Save Branch Point and Depth
			PointStack.push(PointList[PointList.size()-1]);
		}

		//Return Branch
		else if (Tree[i] == ')'){

			//Return Branch Point
			Point ReturnPoint = PointStack.top();
			PointStack.pop();
			Position     = ReturnPoint.Position;
			Direction    = ReturnPoint.Direction;
			CurrentDepth = ReturnPoint.Depth;
			PointList.push_back(ReturnPoint);
		}

		//Angle Instruction
		for (int j=0 ; j<AngleList.size() ; j++){

			//Which Angle?
			if (Tree[i] == AngleList[j].Name){

				//Rotation Direction
				char Axis = AngleList[j].Axis;
				float Angle = AngleList[j].Data * PI / 180;

				//X Axis
				if (Axis == 'x'){
					float y = Direction.Y()*cos(Angle) - Direction.Z()*sin(Angle);
					float z = Direction.Y()*sin(Angle) + Direction.Z()*cos(Angle);
					Direction.Y(y);
					Direction.Z(z);
				}

				//Y Axis
				else if (Axis == 'y'){
					float x = Direction.X()*cos(Angle) + Direction.Z()*sin(Angle);
					float z = -1*Direction.X()*sin(Angle) + Direction.Z()*cos(Angle);
					Direction.X(x);
					Direction.Z(z);
				}

				//Z Axis
				else if (Axis == 'z'){
					float x = Direction.X()*cos(Angle) - Direction.Y()*sin(Angle);
					float y = Direction.X()*sin(Angle) + Direction.Y()*cos(Angle);
					Direction.X(x);
					Direction.Y(y);
				}

				//Normalize
				Direction.Normalize();
			}
		}

		//Rule Instruction
		for (int j=0 ; j<RuleList.size() ; j++){

			//Which Rule?
			if (Tree[i] == RuleList[j].Name){

				//Next Point
				Point NextPoint;
				Position = Position + Direction * RuleList[j].Length * Scale;
				CurrentDepth++;
				NextPoint.Position  = Position;
				NextPoint.Direction = Direction;
				NextPoint.Depth     = CurrentDepth;
				PointList.push_back(NextPoint);

				//Update Pair List
				Pair NewPair;
				NewPair.Point1.Position  = PointList[PointList.size()-2].Position;
				NewPair.Point1.Direction = PointList[PointList.size()-2].Direction;
				NewPair.Point1.Depth     = PointList[PointList.size()-2].Depth;
				NewPair.Point2.Position  = PointList[PointList.size()-1].Position;
				NewPair.Point2.Direction = PointList[PointList.size()-1].Direction;
				NewPair.Point2.Depth     = PointList[PointList.size()-1].Depth;
				NewPair.Depth = NewPair.Point1.Depth;
				PairList.push_back(NewPair);
			}
		}
	}
}

//Draw System
void LSystem::DrawSystem(bool Spine, bool Girth){

	//Draw Spine
	if(Spine)
		DrawSpine();

	//Draw Girth
	if(Girth)
		DrawGirth();
}

//Draw Spine
void LSystem::DrawSpine(){

	//Draw Points
	glPointSize(2.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_POINTS);
	for (int i=0 ; i<PointList.size() ; i++){
		glVertex3f(PointList[i].Position.X(),
							 PointList[i].Position.Y(),
							 PointList[i].Position.Z());
	}
	glEnd();

	//Draw Spine
	glLineWidth(0.2f);
	glColor3f(0.0f, 0.6f, 0.0f);
	glBegin(GL_LINES);
	for (int i=0 ; i<PairList.size() ; i++){
		glVertex3f(PairList[i].Point1.Position.X(),
							 PairList[i].Point1.Position.Y(),
							 PairList[i].Point1.Position.Z());
		glVertex3f(PairList[i].Point2.Position.X(),
							 PairList[i].Point2.Position.Y(),
							 PairList[i].Point2.Position.Z());
	}
	glEnd();
}

//Draw Girth
void LSystem::DrawGirth(){

	//Max Depth
	int MaxPointDepth = 1;
	for (int i=0 ; i<PairList.size() ; i++){
		if (PairList[i].Depth > MaxPointDepth){
			MaxPointDepth = PairList[i].Depth;
		}
	}

	//Draw Cylinders
	for (int i=0 ; i<PairList.size() ; i++){

		//Radius: Variables
		float s;
		float t;
		float RadiusTop;
		float RadiusBottom;

		//Radius: Base Case. If the tree has only 1 depth.
		if (Depth == 1){
			//Draw Cone
			RadiusTop    = EndRadius;
			RadiusBottom = StartRadius;
		}

		//Radius: If the tree has more than 1 depth
		else{

			//If this pair is the tree's base
			if (i-1 < 0){

				//Draw Cylinder
				s = (float)(((float)PairList[i].Depth)/((float)MaxPointDepth));
				t = (float)(((float)PairList[i].Depth)/((float)MaxPointDepth));
			}

			//If this pair is not the tree's base then interpolate each radius of
			//  each cylinder based on the current pair's depth from the origin to
			//  the max depth. Only the furthest branches will achieve EndRadius.
			else{
				s = (float)(((float)PairList[i-1].Depth)/((float)MaxPointDepth));
				t = (float)(((float)PairList[i].Depth)/((float)MaxPointDepth));
			}
			t = (float)(((float)PairList[i].Depth)/((float)MaxPointDepth));
			RadiusTop    = StartRadius + (EndRadius - StartRadius) * s;
			RadiusBottom = StartRadius + (EndRadius - StartRadius) * t;

			//Hacky fix to make sure that gurantees the furthest branch is a cone pointed up.
			if (PairList[i].Depth >= MaxPointDepth){
				RadiusTop = EndRadius;
				t = (float)(((float)PairList[i-1].Depth)/((float)MaxPointDepth));
				RadiusBottom = StartRadius + (EndRadius - StartRadius) * t;
			}
		}

		//Top Normal
		vector3 Normal = PairList[i].Point2.Position - PairList[i].Point1.Position;
		Normal.Normalize();

		//Cylinder Top
		vector<vector3> TopVertices = FindCylinderBase(PairList[i].Point2.Position, Normal, RadiusTop);
		DrawCylinderBase(TopVertices);

		//Cylinder Bottom
		vector<vector3> BottomVertices = FindCylinderBase(PairList[i].Point1.Position, Normal, RadiusBottom);
		DrawCylinderBase(BottomVertices);

		//Cylinder Side
		vector<vector3> SideVertices = FindCylinderSide(TopVertices, BottomVertices);
		DrawCylinderSide(SideVertices);
	}
}

//Find Cylinder Base Vertices
vector<vector3> LSystem::FindCylinderBase(vector3 Origin, vector3 Normal, float Radius){

	//Find Angles in Circle
	vector<double> CircleAngles;
	double CircleAngle = 2*PI/CylinderSidePolyCount;
	for (int i=0 ; i<CylinderSidePolyCount ; i++){
		CircleAngles.push_back(i*CircleAngle);
	}

	//Find Vertices in Circle in the XZ plane
	vector<vector3> Vertices;
	vector3 Center = {0.0f, 0.0f, 0.0f};
	Vertices.push_back(Center);
	vector3 Vertex;
	for (int i=0 ; i<CircleAngles.size() ; i++){
		Vertex.X(Radius*cos(CircleAngles[i]));
		Vertex.Y(0.0f);
		Vertex.Z(Radius*sin(CircleAngles[i]));
		Vertices.push_back(Vertex);
	}

	//Rotate and Translate Circle
	for (int i=0 ; i<Vertices.size() ; i++){
		Vertices[i] += Origin;
	}

	return Vertices;
}

//Draw Cylinder Base
void LSystem::DrawCylinderBase(vector<vector3> Vertices){
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
	for (int i=0 ; i<Vertices.size() ; i++){
		glVertex3f(Vertices[i].X(),
							 Vertices[i].Y(),
							 Vertices[i].Z());
	}
	glVertex3f(Vertices[1].X(),
						 Vertices[1].Y(),
						 Vertices[1].Z());
	glEnd();
}

//Find Cylinder Side Vertices
vector<vector3> LSystem::FindCylinderSide(vector<vector3> TopVertices, vector<vector3> BottomVertices){
	vector<vector3> Vertices;
	for (int i=0 ; i<CylinderSidePolyCount ; i++){
		Vertices.push_back(TopVertices[i+1]);
		Vertices.push_back(BottomVertices[i+1]);
	}
	Vertices.push_back(TopVertices[1]);
	Vertices.push_back(BottomVertices[1]);
	return Vertices;
}

//Draw Cylinder Side
void LSystem::DrawCylinderSide(vector<vector3> Vertices){
	glColor3f(0.0f, 0.6f, 0.0f);
	glBegin(GL_TRIANGLE_STRIP);
	for (int i=0 ; i<Vertices.size() ; i++){
		glVertex3f(Vertices[i].X(),
							 Vertices[i].Y(),
							 Vertices[i].Z());
	}
	glEnd();
}
