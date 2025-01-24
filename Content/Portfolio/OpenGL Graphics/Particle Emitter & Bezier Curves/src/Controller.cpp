/**
 * @file Controller.h
 * @brief This header contains the implementations needed for detecting user input for rendering the scene.
 * @author Clayton Seelenmayer
 * @date Dec 1st 2018
 */

//Includes
#include "Controller.h"

//Variables
	//Camera
	float EyeX = 0.0f;
	float EyeY = 0.0f;
	float EyeZ = 1.0f;
	float ArrowKeySens = 0.05f;
	float MouseWheelSens = 0.01;
	//Time
	bool  Animate = false;
	float Time = 0.0f;
	float PathTime = 0.0f;
	float Step = 0.05f;
	float VelocityScale = 0.15f;
	float EmissionRate = 0.5f;
	float MotionSpeed = 1.0f;
	//Debug
	bool DebugMode = false;

/*******************************************************
This section contains the Keyboard and Mouse menus.
*******************************************************/

//Keyboard Input
void Keyboard(unsigned char Key, int X, int Y){

	//Render Scene
	if(Key == 'r' || Key == 'R')
		Animate = true;

	//Emission Rate
	if(isdigit(Key))
		EmissionSpeed(Key);

	//Curve Speed
	if(Key == '+' || Key == '=' || Key == '-')
		PathSpeed(Key);

	//Debug Status
	if(Key == 'd' || Key == 'D')
		DebugMode = !DebugMode;
}

//Special Keyboard Input
void KeyboardSpecial(int Key, int X, int Y){

	//Close Window
	if(Key == GLUT_KEY_END)
		exit(0);

	//Pan Left
	if (Key == GLUT_KEY_LEFT)				//Key Left
		EyeX = EyeX + ArrowKeySens;

	//Pan Up
	else if (Key == GLUT_KEY_UP)		//Key Up
		EyeY = EyeY - ArrowKeySens;

	//Pan Right
	else if (Key == GLUT_KEY_RIGHT)	//Key Right
		EyeX = EyeX - ArrowKeySens;

	//Pan Down
	else if (Key == GLUT_KEY_DOWN)	//Key Down
		EyeY = EyeY + ArrowKeySens;
}

//Mouse Controls
void Mouse(int Button, int State, int X, int Y)
{
	//Zoom In
	if (Button == 3)								//Mouse Wheel Up
		EyeZ = EyeZ + MouseWheelSens;

	//Zoom Out
	else if (Button == 4)						//Mouse Wheel Down
		EyeZ = EyeZ - MouseWheelSens;
}

/*******************************************************
This section contains Keyboard functionality.
*******************************************************/

//Emission Rate
void EmissionSpeed(unsigned char Key){
	switch(Key){
		case '1': EmissionRate = 4.5f; break;
		case '2': EmissionRate = 4.0f; break;
		case '3': EmissionRate = 3.5f; break;
		case '4': EmissionRate = 3.0f; break;
		case '5': EmissionRate = 2.5f; break;
		case '6': EmissionRate = 2.0f; break;
		case '7': EmissionRate = 1.5f; break;
		case '8': EmissionRate = 1.0f; break;
		case '9': EmissionRate = 0.5f; break;
		case '0': EmissionRate = 0.0f; break;
	}
}

//Particle Motion Speed
void PathSpeed(unsigned char Key){

	//Increase
	if (Key == '+' || Key == '=') MotionSpeed += 0.2f;

	//Decrease
	if (Key == '-') MotionSpeed -= 0.2f;

	//Clamp
	if (MotionSpeed <= 0.4f) MotionSpeed = 0.4f;
	if (MotionSpeed >= 2.4f) MotionSpeed = 2.4f;
}
