/**
 * @file GrossProffit.cpp
 * @author Clayton Seelenmayer
 * @date May 1st 2017
 * @brief Proffit calculation routines.
 */

//Libraries
#include <iostream>
#include "src.h"
using namespace std;
using namespace oracle::occi;

//Calculate Gross Proffit
void GrossProffit(Connection *Conn){

	//Initialize
	string Query;
	Statement *stmt;
	ResultSet *rs;
	int GrossProffit;

	//Calculate Total Weight
	Query = "SELECT sum(Price) FROM Orders";
	stmt = Conn->createStatement();
	rs = stmt->executeQuery(Query);
	for (int i=0 ; rs->next() ; i++){
		GrossProffit = GrossProffit + rs->getFloat(1);
	}
	cout << "   Total gross proffit of all orders: $" << GrossProffit << endl << endl;
}
