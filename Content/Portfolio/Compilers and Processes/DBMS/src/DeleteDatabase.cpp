/**
 * @file DeleteDatabase.cpp
 * @author Clayton Seelenmayer
 * @date May 1st 2017
 * @brief Database deletion routines.
 */

//Libraries
#include <iostream>
#include "src.h"
using namespace std;
using namespace oracle::occi;

//B Delete Database
void DeleteDatabase(Connection *Conn){

	//Initialize
	string Query;
	Statement *stmt;
	cout << "   Dropping existing tables..." << endl;

	//Drop Has
	Query = "DROP TABLE Has";
	cout << "   Has";
	stmt = Conn->createStatement();
	stmt->executeQuery(Query);
	cout << " - Deleted" << endl;

	//Drop Products
	Query = "DROP TABLE Products";
	cout << "   Products";
	stmt = Conn->createStatement();
	stmt->executeQuery(Query);
	cout << " - Deleted" << endl;

	//Drop Orders
	cout << "   Orders";
	Query = "DROP TABLE Orders";
	stmt = Conn->createStatement();
	stmt->executeQuery(Query);
	cout << " - Deleted" << endl;

	//Drop Client
	cout << "   Client";
	Query = "DROP TABLE Client";
	stmt = Conn->createStatement();
	stmt->executeQuery(Query);
	cout << " - Deleted" << endl;

	//Drop Units
	Query = "DROP TABLE Units";
	cout << "   Units";
	stmt = Conn->createStatement();
	stmt->executeQuery(Query);
	cout << " - Deleted" << endl;

	//Cleanup
	cout << "   Tables dropped." << endl << endl;
}
