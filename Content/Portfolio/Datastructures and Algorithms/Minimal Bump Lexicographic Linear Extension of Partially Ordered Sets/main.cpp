/**
 * @file main.cpp
 * @brief Serves as a main interface routine to test posetRead.
 * @author Clayton Seelenmayer
 * @date May 1st 2019
 */

//Includes
#include "poset.h"
#include <iostream>
#include <fstream>
using namespace std;

//Main Service Routine
int main(int argc, char* argv[]){
	if (argc == 2){
		char* File = argv[1];
		poset P;
		P.posetRead(File);
	}
	else{
		cout << "Wrong command. Use \"./bump file-name\"" << endl;
	}
}
