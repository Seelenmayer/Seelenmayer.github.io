/**
 * @file Main.h
 * @brief This file contains the prototypes needed for setting up the glut window, and user interface main routines.
 * @author Clayton Seelenmayer
 * @date Dec 1st 2018
 */

#ifndef MAIN_H
#define MAIN_H

//Libraries
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/glut.h"
#include "bitmap.h"
#include "mathvector.h"
#include "LoadObj.h"
#include "Controller.h"
#include "LSystem.h"
using namespace std;

//Constants
const int ScreenWidth  = 1264;
const int ScreenHeight = 1012;
const int WindowPositionX = 0;
const int WindowPositionY = 0;
const int MinDepth = 1;
const int MaxDepth = 10;
const float ArrowKeySens = 0.05f;
const float MouseWheelSens = 0.05;
const float Scale = 0.06f;
const int CylinderSidePolyCount = 6;

//Variables
bool Spine = false;
bool Girth = false;
bool Arena = true;
float EyeX = 0.0f;
float EyeY = 1.2f;
float EyeZ = 4.0f;
bool ToggleLights[6];
Matrix RotationMatrix;
static GLuint textureHandle;
string SystemPath		= "data/";
string TextureName		= "arass.bmp";
string TextureDirectory	= "./textures/";
string ModelName		= "arena.obj";
string ModelPath		= "./models/";
static float *Positions;
static float *Normals;
static float *UVs;
int numPositions;
int numNormals;
int numUVs;

//Prototypes
void Initialize();
void RenderScene();
LSystem System(MinDepth, MaxDepth);
GLuint LoadImage(string &ImageName, const string &ImagePath);

#endif