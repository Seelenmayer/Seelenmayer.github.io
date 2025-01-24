/**
 * @file LoadObj.h
 * @brief This file contains the implementations needed for detecting user input.
 * @author Clayton Seelenmayer
 * @date Dec 1st 2018
 */

//Libraries
#include "Controller.h"
using namespace std;

//Variables
Matrix RotationMat;
bool mouseDown;
int prevMX;
int prevMY;

//Keyboard Input
void Keyboard(unsigned char Key, int X, int Y)
{
	//Render Spine
	if (Key == 's')
		Spine = !Spine;

	//Render Girth
	if (Key == 'g')
		Girth = !Girth;

	//Render Arena
	if (Key == 'a')
		Arena = !Arena;

	//Pan Object Left
	if (Key == '4')
		EyeX = EyeX - ArrowKeySens;

	//Pan Object Up
	else if (Key == '8')
		EyeY = EyeY + ArrowKeySens;

	//Pan Object Right
	else if (Key == '6')
		EyeX = EyeX + ArrowKeySens;

	//Pan Object Down
	else if (Key == '5')
		EyeY = EyeY - ArrowKeySens;

	//Toggle Lights
	if (Key > '0' && Key < '4')
		ToggleLights[Key-'1'] = !ToggleLights[Key-'1'];
	if (Key == '0')
	{
		ToggleLights[3] = !ToggleLights[3];
		ToggleLights[4] = !ToggleLights[4];
		ToggleLights[5] = !ToggleLights[5];
	}
}

//Special Keyboard Input
void KeyboardSpecial(int Key, int X, int Y)
{
	//Close Window
	if(Key == GLUT_KEY_END)
		exit(0);

	//Display if Tree Changed
	bool Display=true;

	//Increase TreeDepth
	if (Key == GLUT_KEY_RIGHT){
		int Depth = System.getDepth();
		Depth++;
		if (Depth > System.getMaxDepth()){
			System.setDepth(System.getMaxDepth());
			Display = false;
		}
		else
			System.setDepth(Depth);
	}

	//Decrease Depth
	if (Key == GLUT_KEY_LEFT){
		int Depth = System.getDepth();
		Depth--;
		if (Depth < System.getMinDepth()){
			System.setDepth(System.getMinDepth());
			Display = false;
		}
		else
			System.setDepth(Depth);
	}

	//Update
	System.Update();
	System.BuildSystem();
	if (Display)
		System.Display();
}

//Mouse Button Input
void Mouse(int Button, int State, int X, int Y){

	//Left Click Down
	if(Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN){
		//Track Coordinates
		mouseDown = true;
		prevMX = X;
		prevMY = Y;
	}
	else
		//Stop Tracking
		mouseDown = false;

	//Mouse Wheel Down
	if (Button == 4)
		EyeZ = EyeZ + MouseWheelSens;

	//Mouse Wheel Up
	else if (Button == 3)
		EyeZ = EyeZ - MouseWheelSens;
}

//Mouse Motion
void MouseMotion(int X, int Y){

	//If Left Click is Pushed
	if (mouseDown){

		//Get Mouse Position Vectors
		vector3 vectorA = getArcVector(prevMX, prevMY);
		vector3 vectorB = getArcVector(X, Y);

		//Find Angle
		float Angle = acos(min(vector3::DotProduct(vectorA, vectorB), 1.0f));

		//Find Rotation Axis
		vector3 RotationAxis = vector3::CrossProduct(vectorA, vectorB);
		if (RotationAxis.Length() == 0) return;
		RotationAxis.Normalize();

		//Find Rotation Matrix
		Matrix NewRotation;
		NewRotation.setRotationMatrix(Angle, RotationAxis);
		RotationMatrix.MatrixMultiply(RotationMatrix, NewRotation);

		//Reset Mouse Position
		prevMX = X;
		prevMY = Y;
	}
}

//Calculate Vector on the Arcball
vector3 getArcVector(int x, int y){

	//Allign (x,y) to [-1,1]
	vector3 Point = vector3((float)x/ScreenWidth*2-1, (float)y/ScreenHeight*2-1, 0);

	//Negate the Y-axis for OpenGL
	Point.Y(-Point.Y());

	//If point is off of sphere, return nearest point.
	float Psquared = Point.X() * Point.X() + Point.Y() * Point.Y();

	//On the circle:
	if (Psquared <= 1)
		Point.Z(sqrt(1 - Psquared));

	//Off of the circle:
	else
		Point.Normalize();
	return Point;
}