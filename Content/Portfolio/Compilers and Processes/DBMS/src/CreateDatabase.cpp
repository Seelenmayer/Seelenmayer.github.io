/**
 * @file CreateDatabase.cpp
 * @author Clayton Seelenmayer
 * @date May 1st 2017
 * @brief Database creation routines.
 */

//Includes
#include <iostream>
#include "src.h"
using namespace std;
using namespace oracle::occi;

//Create New Database
void CreateDatabase(oracle::occi::Connection *Conn){

	//Initialize
	string Query;
	Statement *stmt;
	cout << "   Creating tables..." << endl;

	//Create Has
	Query = "CREATE TABLE Has ("
	"OID Integer NOT NULL, "
	"PID Integer NOT NULL, "
	"Quantity Integer NOT NULL, "
	"PRIMARY KEY (OID, PID)"
	")";
	cout << "   Has";
	stmt = Conn->createStatement();
	stmt->executeQuery(Query);
	cout << " - Created" << endl;

	//Create Client
	Query = "CREATE TABLE Client ("
	"CID Integer NOT NULL, "
	"Name VARCHAR(64) NOT NULL, "
	"Address VARCHAR(64) NOT NULL, "
	"Phone VARCHAR(64) NOT NULL, "
	"Email VARCHAR(64) NOT NULL, "
	"PRIMARY KEY (CID)"
	")";
	cout << "   Client";
	stmt = Conn->createStatement();
	stmt->executeQuery(Query);
	cout << " - Created" << endl;

	//Create Orders
	Query = "CREATE TABLE Orders ("
	"OID Integer NOT NULL, "
	"CID Integer NOT NULL, "
	"Price Float NOT NULL, "
	"Weight Float NOT NULL, "
	"PRIMARY KEY (OID), "
	"FOREIGN KEY (CID) REFERENCES Client(CID)"
	")";
	cout << "   Orders";
	stmt = Conn->createStatement();
	stmt->executeQuery(Query);
	cout << " - Created" << endl;

	//Create Products
	Query = "CREATE TABLE Products ("
	"PID Integer NOT NULL, "
	"OID Integer NOT NULL, "
	"ItemName VARCHAR(64) NOT NULL, "
	"ItemPrice Float NOT NULL, "
	"ItemWeight Float NOT NULL, "
	"PRIMARY KEY (PID), "
	"FOREIGN KEY (OID) REFERENCES Orders(OID)"
	")";
	cout << "   Products";
	stmt = Conn->createStatement();
	stmt->executeQuery(Query);
	cout << " - Created" << endl;

	//Create Units
	Query = "CREATE TABLE Units ("
	"\"UID\" Integer NOT NULL, "
	"UnitName VARCHAR(64) NOT NULL, "
	"UnitCount Integer NOT NULL, "
	"PRIMARY KEY (\"UID\")"
	")";
	cout << "   Units";
	stmt = Conn->createStatement();
	stmt->executeQuery(Query);
	cout << " - Created" << endl;

	//Cleanup
	cout << "   Tables created." << endl << endl;
}
