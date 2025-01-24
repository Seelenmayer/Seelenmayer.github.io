/************************************************************************************
*     File: tesselation.h
*     Author: Clayton Seelenmayer
*     Date: Sept 29th 2017
*     Behavior:
*        This file serves as the header for the tesselation class.
************************************************************************************/

//Includes
#include <math.h>
#include <climits>
#include <iostream>
using namespace std;

class tesselation{

	public:
		tesselation(int dim, int m1, int m2);
		~tesselation(void);
		void printBoard();

	private: 
		int k;
		int numRows, numCols;
		int missR, missC;
		char** board;
		char next;
		void tile(int rowBeg, int colBeg, int dim, int m1, int m2);
};
