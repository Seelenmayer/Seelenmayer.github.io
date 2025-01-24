/**
 * @file NetWeight.cpp
 * @author Clayton Seelenmayer
 * @date May 1st 2017
 * @brief Calculates product order weights.
 */

//Libraries
#include <iostream>
#include "src.h"
using namespace std;
using namespace oracle::occi;

//Calculate Order Weight
void NetWeight(Connection *Conn){

	//Initialize
	string Query;
	Statement *stmt;
	ResultSet *rs;
	int NetWeight;

	//Calculate Total Weight
	Query = "SELECT sum(Weight) FROM Orders";
	stmt = Conn->createStatement();
	rs = stmt->executeQuery(Query);
	for (int i=0 ; rs->next() ; i++){
		NetWeight = NetWeight + rs->getInt(1);
	}
	cout << "   Total weight of all orders: " << NetWeight << " lbs" << endl << endl;
}
