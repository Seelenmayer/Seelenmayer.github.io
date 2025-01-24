/**
 * @file Controller.h
 * @brief This file contains the header information for reading in user input.
 * @author Clayton Seelenmayer
 * @date Dec 1st 2018
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

//Libraries
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/glut.h"
#include "LSystem.h"
#include "Matrix.h"

//Constants
extern const int ScreenWidth;
extern const int ScreenHeight;
extern const float ArrowKeySens;
extern const float MouseWheelSens;

//Variables
extern bool Spine;
extern bool Girth;
extern bool Arena;
extern LSystem System;
extern float EyeX;
extern float EyeY;
extern float EyeZ;
extern bool ToggleLights[6];
extern Matrix RotationMatrix;

//Prototypes
void Keyboard(unsigned char Key, int X, int Y);
void KeyboardSpecial(int Key, int X, int Y);
void Mouse(int Button, int State, int X, int Y);
void MouseMotion(int X, int Y);
vector3 getArcVector(int x, int y);

#endif
