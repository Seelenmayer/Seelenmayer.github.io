//	File:
//		Doubling.cpp
//
//	Author:
//		Clayton Seelenmayer
//
//	Date:
//		Oct 10th 2018
//
//	Behavior:
//		- Doubling.cpp is a c++ executible
//			designed to compute 2^n.
//		- Main reads in user input and calls the subroutine "f".
//		- Subroutine "f" evaluates 2^n through recursive calls.
//
//	Assumptions:
//		Compiled using g++.

//Libraries
#include <iostream>
using namespace std;

//Prototypes
int f(int n);

//Main
int main()
{
	int n;
	cin >> n;
	cout << f(n) << endl;
	return 0;
}

//Subroutine
int f(int n)
{
	if (n==0)
		return 1;
	else
		return f(n-1) * 2; 
}
