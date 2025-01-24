/**
 * @file Populate.cpp
 * @author Clayton Seelenmayer
 * @date May 1st 2017
 * @brief Insert data into database with prepared statement routines.
 */

//Libraries
#include <iostream>
#include "src.h"
using namespace std;
using namespace oracle::occi;

//D Populate Database With Common Data
void Populate(Connection *Conn){

	//Initialize
	string Query;
	Statement *stmt;
	cout << "   Your Queries are:" << endl << endl;

	//Insert Client Data
	cout << "   Client ('CID', 'Name', 'Street', 'Phone', 'Email')" << endl;
	//AAA Restaurant Client
	Query = "INSERT INTO Client VALUES ('1001', 'AAA Restaurant', '101 Victoria Street', '2501001001', 'AAARestaurant@Email.com')";
	cout << "   " << Query << endl;
	stmt = Conn->createStatement(Query);
	stmt->executeQuery();
	//AAA Grocer Client
	Query = "INSERT INTO Client VALUES ('1002', 'AAA Grocer', '102 Victoria Street', '2501001002', 'AAAGrocer@Email.com')";
	cout << "   " << Query << endl;
	stmt = Conn->createStatement(Query);
	stmt->executeQuery();
	//AAA Market Client
	Query = "INSERT INTO Client VALUES ('1003', 'AAA Market', '103 Victoria Street', '2501001003', 'AAAMarket@Email.com')";
	cout << "   " << Query << endl;
	stmt = Conn->createStatement(Query);
	stmt->executeQuery();

	cout << "   Client insertions complete." << endl << endl;

	//Insert Order Data
	cout << "   Orders ('OID', 'CID', 'Price', 'Weight)" << endl;
	//AAA Restaurant Order
	Query = "INSERT INTO Orders VALUES ('1001', '1001', '125', '20')";
	cout << "   " << Query << endl;
	stmt = Conn->createStatement(Query);
	stmt->executeQuery();
	//AAA Grocer Order
	Query = "INSERT INTO Orders VALUES ('1002', '1002', '100', '15')";
	cout << "   " << Query << endl;
	stmt = Conn->createStatement(Query);
	stmt->executeQuery();
	//AAA Market Order
	Query = "INSERT INTO Orders VALUES ('1003', '1003', '90', '20')";
	cout << "   " << Query << endl;
	stmt = Conn->createStatement(Query);
	stmt->executeQuery();

	cout << "   Order insertions complete." << endl << endl;

	//Insert Product Data
	cout << "   Products ('PID', 'OID', 'ItemName', 'ItemPrice', 'ItemWeight')" << endl;
	//Mushroom Product
	Query = "INSERT INTO Products VALUES ('1001', '1001', 'Mushrooms', '10', '5')";
	cout << "   " << Query << endl;
	stmt = Conn->createStatement(Query);
	stmt->executeQuery();
	//Pepper Product
	Query = "INSERT INTO Products VALUES ('1002', '1003', 'Peppers', '20', '10')";
	cout << "   " << Query << endl;
	stmt = Conn->createStatement(Query);
	stmt->executeQuery();
	//Tomatoe Product
	Query = "INSERT INTO Products VALUES ('1003', '1003', 'Tomatoes', '30', '15')";
	cout << "   " << Query << endl;
	stmt = Conn->createStatement(Query);
	stmt->executeQuery();

	cout << "   Product insertions complete." << endl << endl;

	//Insert Unit Data
	cout << "   Unit ('UID', 'UnitName', 'UnitCount')" << endl;
	//Mushroom Unit
	Query = "INSERT INTO Units VALUES ('1001', 'Mushroom', '100')";
	cout << "   " << Query << endl;
	stmt = Conn->createStatement(Query);
	stmt->executeQuery();
	//Pepper Unit
	Query = "INSERT INTO Units VALUES ('1002', 'Pepper', '20')";
	cout << "   " << Query << endl;
	stmt = Conn->createStatement(Query);
	stmt->executeQuery();
	//Tomatoe Unit
	Query = "INSERT INTO Units VALUES ('1003', 'Tomatoes', '15')";
	cout << "   " << Query << endl;
	stmt = Conn->createStatement(Query);
	stmt->executeQuery();

	cout << "   Unit insertions complete." << endl << endl;

	//Insert Has Data
	cout << "   Has ('OID', 'PID', 'Quantity')" << endl;
	//Client (1001), Order (1001)
	Query = "INSERT INTO Has VALUES ('1001', '1001', '3')";
	cout << "   " << Query << endl;
	stmt = Conn->createStatement(Query);
	stmt->executeQuery();
	//Client (1002), Order (1002)
	Query = "INSERT INTO Has VALUES ('1002', '1002', '5')";
	cout << "   " << Query << endl;
	stmt = Conn->createStatement(Query);
	stmt->executeQuery();
	//Client (1003), Order (1003)
	Query = "INSERT INTO Has VALUES ('1003', '1003', '7')";
	cout << "   " << Query << endl;
	stmt = Conn->createStatement(Query);
	stmt->executeQuery();

	cout << "   Has insertions complete." << endl << endl;
}
