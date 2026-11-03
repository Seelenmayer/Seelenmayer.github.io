/**
 * @file poset.h
 * @brief Reads transitive reduction and total order of a command line poset
 *    before printing the minimal bump linear extension with parsimonious
 *    lexicographic labeling.
 * @author Clayton Seelenmayer
 * @date May 1st 2019
 */

//Includes
#include <string>
#include <fstream>
#include <iostream>
#include <values.h>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;

//Globals
const int NO_EDGE=0;

class poset{

	private:
		int n;									//Number of Vertices in the Poset
		vector<int> *LowerCover;			//Vector of Vertex Lower Covers
		vector<int> *UpperCover;			//Vector of Vertex Upper Covers
		bool **Less;							//n*n Array of Less-Than Relations From the Data File
		bool **Covers;							//n*n Array of Lower Cover relations. Covers[i][j]==1 means i covers j
		vector<int> VertexLexNumbers;		//Lexicographic Orderings for Vertices

	public: 
	  poset();									//Default Constructor
	  poset(int num);							//Constructor
	  int posetRead(char *fn);				//Read Poset + Print Linear Extension
	  ~poset();									//Destructor
	  int numElements() {return n;}		//Number of Elements in the Poset
	  int addCover(int u, int v);			//Vertex u Covers v
	  int removeCover(int u, int v);		//Vertex u Doesn't Cover Vertex v
};
