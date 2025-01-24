/**
 * @file Controller.h
 * @brief This header contains the prototypes for setting up the glut window and rendering the scene.
 * @author Clayton Seelenmayer
 * @date Dec 1st 2018
 */

#ifndef MAIN_H
#define MAIN_H

//Includes
#include <iostream>
#include <cmath>
#include <vector>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/glut.h"
#include "mathvector.h"
#include "Controller.h"
#include "Particle.h"
using namespace std;

//Prototypes
void Initialize();
void RenderScene();
void DrawEmitter();
void FindEmitter();
void DrawCurves();
void DrawPoints();
void DrawParticles();
vector3 BLerp(vector3 Point1, vector3 Point2, vector3 Point3, vector3 Point4, float t);

//Constants
const int Screenwidth  = 800;
const int Screenheight = 800;
const int WindowPositionX = 100;
const int WindowPositionY = 100;
const int NumSegments = 50;

#endif