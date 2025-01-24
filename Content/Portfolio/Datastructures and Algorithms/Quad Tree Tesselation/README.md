Program: tilex\
Author: Clayton Seelenmayer\
Date: Sept 29th 2017

This program demonstrates the use of the "tesselation" class which constructs a 2^n by 2^n table such that given a particular missing entry, the rest of the table is populated with L-trominos. This program demonstrates the use of recursion to generate a space-filling tile about a missing entry.

- mainTile.cpp serves as a user-interface to create the tesselation.

- tesselation.cpp and tesselation.h contain the imeplementations for the tesselation construction.

For compilation, simply type "make" into the terminal with a g++ compilor on a Linux Debian machine.