/**
 * @file Help.cpp
 * @author Clayton Seelenmayer
 * @date May 1st 2017
 * @brief Help instruction menu.
 */

//Libraries
#include <iostream>
#include "src.h"
using namespace std;
using namespace oracle::occi;

//Help Menu
void Help(){
	cout << "   Details about each command:" << endl
		 << "   A will create the database table by table." << endl
		 << "   B will delete the database table by table." << endl
		 << "   C will insert new data into the database." << endl
		 << "   D will insert the typical everyday-use data into the database." << endl
		 << "   E will create a file containing a customers invoice information." << endl
		 << "   F will calculate the total weight of all orders." << endl
		 << "   G will calculate the total gross proffit of all orders." << endl
		 << "   H displays this help menu." << endl
		 << endl;
}
