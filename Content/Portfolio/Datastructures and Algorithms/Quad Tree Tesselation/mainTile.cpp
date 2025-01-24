/************************************************************************************
*		File: mainTile.cpp
*		Author: Clayton Seelenmayer
*		Date: Sept 29th 2017
*		Behavior:
*			This file serves as the interface for the tesselation class.
************************************************************************************/

//Includes
#include "tesselation.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){

	//Data
	int missrow, misscol, k;
	cout << "Enter the power k, making a chessboard of dimensions 2^k x 2^k: " << endl;
	cin >> k;
	cout << "Enter the row of the missing square: " << endl;
	cin >> missrow;
	cout << "Enter the column of the missing square: " << endl;
	cin >> misscol;

	//Board
	tesselation b(k,missrow,misscol);
	b.printBoard();
}
