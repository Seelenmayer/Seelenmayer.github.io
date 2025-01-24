/**
 * @file poset.cpp
 * @brief Implementations for the poset class.
 * @author Clayton Seelenmayer
 * @date May 1st 2019
 */

//Includes
#include "poset.h"

//Constants
int NO_VERTEX=-1;

//Default Constructor
poset::poset(): n(0){
	n = 0;
}

//Constructor
poset::poset(int num): n(num){}

//Poset Read + Assign Lex Labeling + Print Linear Extension
int poset::posetRead(char *fn){

	/*******************************************************************************
	*                                                                              *
	*   Read in poset data and store it into the appropriate containers.           *
	*                                                                              *
	*******************************************************************************/

	//Open File
	ifstream f;
	f.open(fn);
	if (!f){
		cerr << "File not openable." << endl;
		return 0;
	}

	//Number of Elements
	f >> n;
	cout << "Reading " << n <<  " nodes..." << endl;
	if (n > 100000){
		cerr << "n too large: " << n << endl;
		return 0;
	}

	//Initialize Vertex Storage
	LowerCover = new vector<int>[n]; //All elements covering indexed element.
	UpperCover = new vector<int>[n]; //All elements that cover indexed element.

	//Read Vertices for Cover Relations.
	int u;
	int v;
	f >> u;
	while (u<n && f){
		f >> v; 
		while (v<n && f){
			LowerCover[v].push_back(u);
			UpperCover[u].push_back(v);
			f >> v;
		}
		f >> u;
	}
	f.close();

	/*******************************************************************************
	*                                                                              *
	*   Initialize and assign lexicographic labeling to vertices.                  *
	*                                                                              *
	*******************************************************************************/

	//Assign Upper Cover based on Lex Orderings to Vertices with no Upper Covers
		//Priority Queue of pairs of multisets and vertex names. The multisets store upper cover lex labels.
	priority_queue<pair<multiset<int>,int>> VerticesOfNoUpperCovers;
	multiset<int> EmptySet;
	for (int i=0 ; i<n ; ++i){
		if (UpperCover[i].size() == 0){
			//Push onto the priority queue pairs of empty multisets and the vertex names.
			VerticesOfNoUpperCovers.push(make_pair(EmptySet, i));
		}
	}

	//Assign Lexicographic Labeling
	int LexNumbers[n];										//Lex numbers for each vertex
	int CurrentLexNumber = 1;								//Initial lex number
	multiset<int> PreviousUpperCoversSet;					//Previously shelled upper cover lex label set
	vector<multiset<int>> VerticesUpperCoversLexNumbers;	//Lex numbers for the upper covers of a Vertex
	for (int i=0 ; i<n ; ++i){
		VerticesUpperCoversLexNumbers.push_back(EmptySet);
	}

	//While there exists a vertex with no upper covers
	while (!VerticesOfNoUpperCovers.empty()){

		//Consider the top vertex of the PQ with an upper cover lex labeling.
		pair<multiset<int>,int> VerticesAndTheirUpperCoversLexLabels = VerticesOfNoUpperCovers.top();
		int Vertex = VerticesAndTheirUpperCoversLexLabels.second;
		VerticesOfNoUpperCovers.pop();

		//Increment this vertex's lex number if its different from the buffer.
		if (VerticesAndTheirUpperCoversLexLabels.first == PreviousUpperCoversSet)
			LexNumbers[Vertex] = CurrentLexNumber;
		else
			LexNumbers[Vertex] = ++CurrentLexNumber;

		//Update the previous upper covers set.
		PreviousUpperCoversSet = VerticesAndTheirUpperCoversLexLabels.first;

		//Look at this Vertex' lower covers.
		for (int it : LowerCover[Vertex]){

			//Insert the current lexicographic number into each of the lower cover vertices' set of upper cover lexicographic numbers.
			VerticesUpperCoversLexNumbers[it].insert(CurrentLexNumber);

			//Once the set of upper lex numbers has been filled...
			if (VerticesUpperCoversLexNumbers[it].size() == UpperCover[it].size()){

				//Insert into PQ, the vertices with no unshelled upper cover.
				VerticesOfNoUpperCovers.push(make_pair(VerticesUpperCoversLexNumbers[it], it));
			}
		}
	}

	//Calculate Number of Lower Covers
	int numLowerCovers[n];

	//Priority Queue of Lex Numbers, Vertex Numbers
	priority_queue<pair<int,int>> VerticesOfNoLowerCovers;

	//For each vertex remember the number of lower covers and insert it into the PQ if it has no lower covers.
	for (int i=0 ; i<n ; ++i){
		numLowerCovers[i] = LowerCover[i].size();
		if (numLowerCovers[i] == 0){
			VerticesOfNoLowerCovers.push(make_pair(LexNumbers[i], i));
		}
	}

	/*******************************************************************************
	*                                                                              *
	*   Construct and print the poset's linear extension based on its lex labeling *
	*                                                                              *
	*******************************************************************************/

	//Linear Extension
	int Vertex;
	int BumpNumber = 0;

	//Previously shelled buffer's parents used to avoid bumps.
	vector<pair<int,int>> PreviousVertexUpperCovers;

	//While the priority queue of vertices with lex numbers is non empty...
	while (!VerticesOfNoLowerCovers.empty()){

		//Insert top Vertex of PQ into Linear Extension
		Vertex = VerticesOfNoLowerCovers.top().second;
		VerticesOfNoLowerCovers.pop();

		//Insert the buffer vertices into the PQ and clear the buffer.
		for (auto it : PreviousVertexUpperCovers){
			VerticesOfNoLowerCovers.push(it);
		}

		//Clear Buffer
		PreviousVertexUpperCovers.clear();

		//Print the Linear Extension for this Vertex
		cout << Vertex << "(" << LexNumbers[Vertex] << ")";

		//Print Bump
		if (VerticesOfNoLowerCovers.empty() && !UpperCover[Vertex].empty()){
			cout << "--";
			++BumpNumber;
		}
		else{
			cout << " ";
		}

		//If the PQ is empty and a bump will occur...
		if (VerticesOfNoLowerCovers.empty()){

			//For each parent of this vertex...
			for (auto it : UpperCover[Vertex]){

				//Decrement Parent's Lower Covers
				--numLowerCovers[it];

				//When the parents are free from their children.
				if (numLowerCovers[it] == 0){

					//Store parents in PQ
					VerticesOfNoLowerCovers.push(make_pair(LexNumbers[it],it));
				}
			}
		}

		//If PQ isn't empty, then we won't have a bump.
		else{

			//For each parent of this vertex...
			for (auto it : UpperCover[Vertex]){

				//Decrement Parent's Lower Covers
				--numLowerCovers[it];

				//When the parents are free from their children.
				if (numLowerCovers[it] == 0){

					//Store parents in buffer.
					PreviousVertexUpperCovers.push_back(make_pair(LexNumbers[it], it));
				}
			}
		}
	}

	//Display Bumps
	cout << endl;
	cout << "bump number is " << BumpNumber << endl;

	//Display Time
	clock_t start;
	start = clock();
	cout << "Time: "<<(clock()-start)/(double(CLOCKS_PER_SEC/1000))<< endl;
	return 1;
}

//Destructor
poset::~poset(){
	for (int i=0  ; i<n ; ++i){
		vector<int>().swap(LowerCover[i]);
		vector<int>().swap(UpperCover[i]);
	}
	delete[] LowerCover;
	delete[] UpperCover;
}