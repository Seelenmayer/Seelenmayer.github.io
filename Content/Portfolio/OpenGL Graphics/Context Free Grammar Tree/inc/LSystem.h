/**
 * @file LSystem.h
 * @brief This file contains the LSystem class prototypes for constructing grammars.
 * @author Clayton Seelenmayer
 * @date Dec 1st 2018
 */

#ifndef PARTICLE_H
#define PARTICLE_H

//Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/glut.h"
#include "mathvector.h"
#include "Matrix.h"

//Constants
const float PI = 3.141592653589f;
const float Error = 0.001f;
const std::string FileStart = "~~Begin~~";
extern const float Scale;
extern const int CylinderSidePolyCount;

//Classes
class LSystem{

	private:

		//Angles
		struct Angles{
			char Name;
			char Axis;
			int  Data;
		};
		Angles Angle;
		std::vector<Angles> AngleList;

		//Rules
		struct Rules{
			char Name;
			int  Length;
			std::string Data;
		};
		Rules Rule;
		std::vector<Rules> RuleList;

		//Tree
		std::string Seed;
		std::string Tree;
		int Depth;
		int MinDepth;
		int MaxDepth;

		//Points
		struct Point{
			vector3 Position;
			vector3 Direction;
			int     Depth;
		};
		std::vector<Point> PointList;
		const vector3 DefaultPosition  = {0.0f, 0.0f, 0.0f};
		const vector3 DefaultDirection = {0.0f, 1.0f, 0.0f};
		const int     DefaultDepth     = 1;

		//Pairs
		struct Pair{
			Point Point1;
			Point Point2;
			int Depth;
		};
		std::vector<Pair> PairList;

		//Girth
		const float StartRadius   = 0.5f * Scale;
		const float EndRadius     = 0.1f * Scale;
		Matrix CylinderRotationMatrix;

	public:

		//Constructors
		LSystem(int Min, int Max){MinDepth = Min; MaxDepth = Max; Depth = MinDepth;}
		~LSystem(){}

		//Depth
		int getDepth()						{return Depth;}
		void setDepth(int D)			{Depth = D;}
		int getMinDepth()					{return MinDepth;}
		int getMaxDepth()					{return MaxDepth;}

		//Functions
		bool LoadSystem(std::string Path);
		void Display();
		void Update();
		void BuildSystem();
		void DrawSystem(bool Spine, bool Girth);
		void DrawSpine();
		void DrawGirth();
		std::vector<vector3> FindCylinderBase(vector3 Origin, vector3 Normal, float Radius);
		void DrawCylinderBase(std::vector<vector3> Vertices);
		std::vector<vector3> FindCylinderSide(std::vector<vector3> TopVertices, std::vector<vector3> BottomVertices);
		void DrawCylinderSide(std::vector<vector3> Vertices);
};

#endif
