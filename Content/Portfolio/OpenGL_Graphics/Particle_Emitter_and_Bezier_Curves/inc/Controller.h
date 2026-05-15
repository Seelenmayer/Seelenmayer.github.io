/**
 * @file Controller.h
 * @brief This header contains the information needed for detecting user input for rendering the scene.
 * @author Clayton Seelenmayer
 * @date Dec 1st 2018
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

//Includes
#include "Main.h"

//Prototypes
void Keyboard(unsigned char Key, int X, int Y);
void KeyboardSpecial(int Key, int X, int Y);
void Mouse(int Button, int State, int X, int Y);
void ResetScene();
void EmissionSpeed(unsigned char Key);
void PathSpeed(unsigned char Key);

//Variables
	//Camera
	extern float EyeX, EyeY, EyeZ;
	extern float ArrowKeySens;
	extern float MouseWheelSens;
	//Time
	extern bool  Animate;
	extern float Time, PathTime;
	extern float Step;
	extern float VelocityScale;
	extern float EmissionRate;
	extern float MotionSpeed;
	//Debug
	extern bool  DebugMode;

#endif