#Instructions for compilation.

bump:	bump.o poset.o
	g++ -o bump bump.o poset.o

bump.o:	poset.h main.cpp
	g++ -c main.cpp

poset2.o: poset.h poset.cpp
	g++ -c poset.cpp