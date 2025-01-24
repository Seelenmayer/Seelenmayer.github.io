/************************************************************************************
*     File: tesselation.cpp
*     Author: Clayton Seelenmayer
*     Date: Sept 29th 2017
*     Behavior:
*        This file contains the implementations for the tesselation class.
************************************************************************************/

//Includes
#include "tesselation.h"
#include <cmath>
#include <iostream>
using namespace std;



//Constructor
tesselation::tesselation(int dim, int m1, int m2){

	//Get Dimensions
	numRows = pow(2, dim);
	numCols = pow(2, dim);

	//Initialize 2D Array
	board = new char* [numRows];
	for(int i=0 ; i<numRows ; i++){
		board[i] = new char [numCols];
		for(int j=0 ; j<numCols ; j++)
			board[i][j] = '!';
	}

	//Initialalize the arbitrary missing entry of the 2d array.
	board[m1][m2] = 'X';

	//Initialize the first ASCII character used to populate the tiling.
	next = 'a';

	//Private method construction.
	tile(0, 0, dim, m1, m2);
}



//Destructor
tesselation::~tesselation(){
	for (int i=0 ; i<numRows ; i++)
		delete []board[i];
	delete []board;
}



//Display
void tesselation::printBoard(){
	for (int i=0 ; i<numRows ; i++){
		for (int j=0 ; j<numCols ; j++)
			cout << board[i][j];
		cout << endl;
	}
}



//Tile
//This method recursively populates the tesselation 2d array table.
//Starting with the initially defined character 'a' we populate the table
//with L-trominos, advancing to the next ASCII character afterwards.
void tesselation::tile(int rowBeg, int colBeg, int dim, int m1, int m2){

	//Recursive Return
	if (dim == 0)
		return;

	//Character Wrap
	if (next == '{')
		next = '0';

	//Quadrant Seperators.
	int size = (int) pow(2, dim);
	int halfSize = size/2;
	int rowMid = rowBeg + halfSize;
	int colMid = colBeg + halfSize;

	//Assign the L-Trominos
	if (dim == 1){
		//Find 2x2 Section
		for (int i=rowBeg ; i<=rowMid ; i++)
			for (int j=colBeg ; j<=colMid ; j++){
				//Avoid Missing Entry
				if ((i != m1) || (j != m2))
					//Populate Character
					board[i][j] = next;
			}
		//Character Update
		next++;
		return;
	}

	//1st Quadrant (Top-Left)
	if((m1 < rowMid) && (m2 < colMid)){
		board[rowMid-1][colMid] = next;
		board[rowMid][colMid-1] = next;
		board[rowMid][colMid]   = next;
		next++;
		tile(rowBeg, colBeg, dim-1, m1,       m2);       //1st Sub-Quadrant (Top-Left).
		tile(rowBeg, colMid, dim-1, rowMid-1, colMid);   //2nd Sub-Quadrant (Top-Right).
		tile(rowMid, colBeg, dim-1, rowMid,   colMid-1); //3rd Sub-Quadrant (Bottom-Left).
		tile(rowMid, colMid, dim-1, rowMid,   colMid);   //4th Sub-Quadrant (Bottom-Right).
	}

	//2nd Quadrant (Top-Right)
	if((m1 < rowMid) && (m2 >= colMid)){
		board[rowMid-1][colMid-1] = next;
		board[rowMid][colMid-1] = next;
		board[rowMid][colMid]   = next;
		next++;
		tile(rowBeg, colBeg, dim-1, rowMid-1, colMid-1); //1st Sub-Quadrant (Top-Left).
		tile(rowBeg, colMid, dim-1, m1,       m2);       //2nd Sub-Quadrant (Top-Right).
		tile(rowMid, colBeg, dim-1, rowMid,   colMid-1); //3rd Sub-Quadrant (Bottom-Left).
		tile(rowMid, colMid, dim-1, rowMid,   colMid);   //4th Sub-Quadrant (Bottom-Right).
	}

	//3rd Quadrant (Bottom-Left)
	if((m1 >= rowMid) && (m2 < colMid)){
		board[rowMid-1][colMid-1] = next;
		board[rowMid-1][colMid]   = next;
		board[rowMid][colMid]     = next;
		next++;
		tile(rowBeg, colBeg, dim-1, rowMid-1, colMid-1); //1st Sub-Quadrant (Top-Left).
		tile(rowBeg, colMid, dim-1, rowMid-1, colMid);   //2nd Sub-Quadrant (Top-Right).
		tile(rowMid, colBeg, dim-1, m1,       m2);       //3rd Sub-Quadrant (Bottom-Left).
		tile(rowMid, colMid, dim-1, rowMid,   colMid);   //4th Sub-Quadrant (Bottom-Right).
	}

	//4th Quadrant (Bottom-Right)
	if((m1 >= rowMid) && (m2 >= colMid)){
		board[rowMid-1][colMid-1] = next;
		board[rowMid-1][colMid]   = next;
		board[rowMid][colMid-1]   = next;
		next++;
		tile(rowBeg, colBeg, dim-1, rowMid-1, colMid-1); //1st Sub-Quadrant (Top-Left).
		tile(rowBeg, colMid, dim-1, rowMid-1, colMid);   //2nd Sub-Quadrant (Top-Right).
		tile(rowMid, colBeg, dim-1, rowMid,   colMid-1); //3rd Sub-Quadrant (Bottom-Left).
		tile(rowMid, colMid, dim-1, m1,       m2);       //4th Sub-Quadrant (Bottom-Right).
	}
}
