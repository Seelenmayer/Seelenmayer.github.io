/**
 * @file Controller.h
 * @brief This header contains the implementations for setting up the glut window and rendering the scene.
 * @author Clayton Seelenmayer
 * @date Dec 1st 2018
 */

//Includes
#include "Main.h"

//Globals
float CircuitDuration = 30.0f;
float CurveProgress = 0.0f;
Emitter Source;
vector<Particle> ParticleList;
vector<vector3> ControlPoints;
vector<vector3> FirstSubPoints;
vector<vector3> SecondSubPoints;
vector<vector3> MidPoints;



//Main Routine
int main(int argc, char* argv[]){

	//Initialize GLUT library and display.
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(WindowPositionX,WindowPositionY);
	glutInitWindowSize(Screenwidth, Screenheight);
	glutCreateWindow("Assignment 3");

	//Initialize viewport, display callback, and scene.
	glViewport(0, 0, Screenwidth, Screenheight);
	glutDisplayFunc(RenderScene);
	glutIdleFunc(RenderScene);
	Initialize();

	//Controller
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(KeyboardSpecial);
	glutMouseFunc(Mouse);

	//GLUT Main Loop
	glutMainLoop();

	return(0);
}



//Initialize Scene
void Initialize()
{
	//Control Points
	vector3 Point;
	Point = {-0.4f, 0.0f, 0.0f};		//Left
	ControlPoints.push_back(Point);
	Point = {-0.8f, 0.8f, 0.0f};		//Top Left
	ControlPoints.push_back(Point);
	Point = {0.0f, 0.4f, 0.0f};			//Top
	ControlPoints.push_back(Point);
	Point = {0.8f, 0.8f, 0.0f};			//Top Right
	ControlPoints.push_back(Point);
	Point = {0.4f, 0.0f, 0.0f};			//Right
	ControlPoints.push_back(Point);
	Point = {0.8f, -0.8f, 0.0f};		//Bottom Right
	ControlPoints.push_back(Point);
	Point = {0.0f, -0.4f, 0.0f};		//Bottom
	ControlPoints.push_back(Point);
	Point = {-0.8f, -0.8f, 0.0f};		//Bottom Left
	ControlPoints.push_back(Point);

	//Sub Points
	for (int i=0 ; i<ControlPoints.size() ; i++){

		//Index Wrapping
		int j=(i+1)%ControlPoints.size();

		//FirstSubPoints
		Point.X((2*ControlPoints[i].X() + ControlPoints[j].X())/3);
		Point.Y((2*ControlPoints[i].Y() + ControlPoints[j].Y())/3);
		Point.Z((2*ControlPoints[i].Z() + ControlPoints[j].Z())/3);
		FirstSubPoints.push_back(Point);

		//SecondSubPoints
		Point.X((ControlPoints[i].X() + 2*ControlPoints[j].X())/3);
		Point.Y((ControlPoints[i].Y() + 2*ControlPoints[j].Y())/3);
		Point.Z((ControlPoints[i].Z() + 2*ControlPoints[j].Z())/3);
		SecondSubPoints.push_back(Point);
	}

	//Mid Points
	for (int i=0 ; i<ControlPoints.size() ; i++){

		//Indrex Wrapping
		int k=((i-1)+ControlPoints.size())%ControlPoints.size();

		//MidPoints
		Point.X((FirstSubPoints[i].X() + SecondSubPoints[k].X())/2);
		Point.Y((FirstSubPoints[i].Y() + SecondSubPoints[k].Y())/2);
		Point.Z((FirstSubPoints[i].Z() + SecondSubPoints[k].Z())/2);
		MidPoints.push_back(Point);
	}

	//Emitter
	EmitterProperties Properties;
	Properties.Position   = MidPoints[0];
	Properties.Colour     = {0.0f, 1.0f, 1.0f};
	Properties.Size       = 10.0f;
	Properties.SpawnCount = 100;
	Source.setProperties(Properties);
}



//Render Scene
void RenderScene(){

	//Clear Colour/Depth Buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Camera
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		EyeX, EyeY, EyeZ,		//Eye Position
		EyeX, EyeY, 0.0f,		//Lookat Position
		0.0f, 1.0f, 0.0f);	//Up Vector

	//Curves
	if (DebugMode){
		//Bezier Curves
		DrawCurves();
		//Control Points
		DrawPoints();
	}

	//Animation
	if (Animate){
		//Time
		Time += Step;
		PathTime += Step*MotionSpeed;
		//Emitter
		DrawEmitter();
		//Particles
		DrawParticles();
	}

	//Cleanup
	glFlush();
	glPopMatrix();
	glutSwapBuffers();
}



//Draw Emitter
void DrawEmitter(){

	//Find Position
	FindEmitter();

	//Properties
	EmitterProperties Properties = Source.getProperties();

	//Draw
	glPointSize(Properties.Size);
	glColor3f(Properties.Colour.X(),
						Properties.Colour.Y(),
						Properties.Colour.Z());
	glBegin(GL_POINTS);
	glVertex3f(Properties.Position.X(),
						 Properties.Position.Y(),
						 Properties.Position.Z());
	glEnd();
}



void FindEmitter(){

	//Current Lap Time
	float CircuitTime = fmod(PathTime, CircuitDuration);

	//Duration Between MidPoint Sections
	float SectionDuration = CircuitDuration / MidPoints.size();

	//Current MidPoint Section
	int CurrSection = CircuitTime / SectionDuration;

	//Section Wrapping
	int NextSection = CurrSection + 1;
	if (NextSection >= MidPoints.size())
		NextSection = 0;

	//Section Progress
	float SectionTime = fmod(CircuitTime, SectionDuration);
	float t = SectionTime / SectionDuration;
	CurveProgress = (t + CurrSection) / (MidPoints.size());

	//Control Points
	vector3 Point1 = MidPoints[CurrSection];
	vector3 Point2 = FirstSubPoints[CurrSection];
	vector3 Point3 = SecondSubPoints[CurrSection];
	vector3 Point4 = MidPoints[NextSection];

	//Curve Point
	vector3 Point = BLerp(Point1, Point2, Point3, Point4, t);

	//Update Emitter
	EmitterProperties Properties = Source.getProperties();
	Properties.Position = Point;
	Source.setProperties(Properties);
}



//Draw Cubic Bezier Curves
void DrawCurves(){

	//Draw Curves
	glLineWidth(3.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINE_STRIP);
	for (int i=0 ; i<MidPoints.size()+1 ; i++)
	{
		//Index Wrapping
		int j=i;
		if (j==MidPoints.size())
			j=0;
		int k=(i+1)%MidPoints.size();

		//Control Points
		vector3 Point1 = MidPoints[j];
		vector3 Point2 = FirstSubPoints[j];
		vector3 Point3 = SecondSubPoints[j];
		vector3 Point4 = MidPoints[k];

		for (int CurSegment=0 ; CurSegment<NumSegments ; CurSegment++)
		{
			//Parameter
			float t = (CurSegment / (float)NumSegments);

			//Bezier Curve
			vector3 Point = BLerp(Point1, Point2, Point3, Point4, t);
			glVertex3f(Point.X(), Point.Y(), Point.Z());
		}
	}
	glEnd();
}



//Draw Control Points
void DrawPoints(){

	//Draw Control Points
	glPointSize(10.0f);
	float t = 0;
	glBegin(GL_POINTS);
	for (int i=0 ; i<ControlPoints.size() ; i++)
	{
		t = (i/(float)ControlPoints.size());
		glColor3f((1-t), 0.0f, t);
		glVertex3f(ControlPoints[i].X(),
							 ControlPoints[i].Y(),
							 ControlPoints[i].Z());
	}
	glEnd();

	//Draw First Sub Points
	glPointSize(6.0f);
	glColor3f(0.4f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
	for (int i=0 ; i<FirstSubPoints.size() ; i++){
		glVertex3f(FirstSubPoints[i].X(),
							 FirstSubPoints[i].Y(),
							 FirstSubPoints[i].Z());
	}
	glEnd();

	//Draw Second Sub Points
	glPointSize(6.0f);
	glColor3f(1.0f, 0.3f, 0.3f);
	glBegin(GL_POINTS);
	for (int i=0 ; i<SecondSubPoints.size() ; i++){
		glVertex3f(SecondSubPoints[i].X(),
							 SecondSubPoints[i].Y(),
							 SecondSubPoints[i].Z());
	}
	glEnd();

	//Draw Mid Points
	glPointSize(6.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_POINTS);
	for (int i=0 ; i<MidPoints.size() ; i++){
		glVertex3f(MidPoints[i].X(),
							 MidPoints[i].Y(),
							 MidPoints[i].Z());
	}
	glEnd();
}



//Draw Particles
void DrawParticles(){

	//Trigger Explosion
	if (fmod(Time, EmissionRate) < 0.15f){
		vector<Particle> NewInstances = Source.Populate();
		for (int i=0 ; i<NewInstances.size() ; i++)
			ParticleList.push_back(NewInstances[i]);
	}

	//Particle Behavior
	for (int i=0 ; i<ParticleList.size(); i++){

		//Get Properties
		ParticleProperties Properties = ParticleList[i].getProperties();

		//New Position
		vector3 NewPosition;
		NewPosition.X(Properties.Position.X() + Properties.Velocity.X() * VelocityScale * (Time - Properties.StartTime));
		NewPosition.Y(Properties.Position.Y() + Properties.Velocity.Y() * VelocityScale * (Time - Properties.StartTime));
		NewPosition.Z(Properties.Position.Z() + Properties.Velocity.Z() * VelocityScale * (Time - Properties.StartTime));

		//Age
		ParticleList[i].Age();

		//Death
		if(Time > Properties.EndTime)
			ParticleList.erase(ParticleList.begin()+i);

		//Draw
		glColor3f(Properties.Colour.X(),
							Properties.Colour.Y(),
							Properties.Colour.Z());
		glBegin(GL_QUADS);
		vector3 NewPoint = NewPosition;
		float Delta = 0.01;
		glVertex3f(NewPoint.X()+Delta,
							 NewPoint.Y()+Delta,
							 NewPoint.Z());
		glVertex3f(NewPoint.X()-Delta,
							 NewPoint.Y()+Delta,
							 NewPoint.Z());
		glVertex3f(NewPoint.X()-Delta,
							 NewPoint.Y()-Delta,
							 NewPoint.Z());
		glVertex3f(NewPoint.X()+Delta,
							 NewPoint.Y()-Delta,
							 NewPoint.Z());
		glEnd();
	}
}



//Bezier Quadratic Linear Interpolation Function
vector3 BLerp(vector3 Point1, vector3 Point2, vector3 Point3, vector3 Point4, float t){
	//Interpolated Point between 4 Control Points
	vector3 InterpolatedPoint = (1-t)*(1-t)*(1-t)*Point1 +
															3*(1-t)*(1-t)*t*Point2 +
															3*(1-t)*t*t*Point3 +
															t*t*t*Point4;
	return InterpolatedPoint;
}