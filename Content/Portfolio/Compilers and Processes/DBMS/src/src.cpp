/**
 * @file src.cpp
 * @author Clayton Seelenmayer
 * @date May 1st 2017
 * @brief Helper routines.
 */

//Includes
#include <iostream>
#include "src.h"
using namespace std;

string Query;
Statement *stmt;
ResultSet *rs;

//Count Orders
int CountOrders(oracle::occi::Connection *Conn){
	cout << "   Calculating number of orders..." << endl;
	Query = "SELECT COUNT(*) FROM Orders";
	cout << "   Your Query is: " << Query << endl;
	stmt = Conn->createStatement();
	rs = stmt->executeQuery(Query);
	rs->next();
	int OrderCount = rs->getInt(1);
	cout << "   You have " << OrderCount << " orders registered." << endl << endl;
	return OrderCount;
}

//Count Products
int CountProducts(oracle::occi::Connection *Conn){
	cout << "   Calculating number of product types..." << endl;
	Query = "SELECT COUNT(*) FROM Products";
	cout << "   Your Query is: " << Query << endl;
	stmt = Conn->createStatement();
	rs = stmt->executeQuery(Query);
	rs->next();
	int ProductCount = rs->getInt(1);
	cout << "   You have " << ProductCount << " products registered." << endl << endl;
	return ProductCount;
}

//Product Names
string* FindProductNames(oracle::occi::Connection *Conn){
	cout << "   Finding the name of each product..." << endl;
	Query = "SELECT ItemName FROM Products";
	cout << "   Your Query is: " << Query << endl;
	stmt = Conn->createStatement();
	rs = stmt->executeQuery(Query);
	cout << "   Your product names are:";
	string *ProductNames = new string[CountProducts(Conn)];
	for (int i=0 ; rs->next() ; i++){
		ProductNames[i] = rs->getString(1);
		cout << " " << ProductNames[i];
	}
	cout << endl;
	return ProductNames;
}

//Product Weights
float* FindProductWeights(oracle::occi::Connection *Conn){
	cout << "   Finding the weight of each product..." << endl;
	Query = "SELECT ItemWeight FROM Products";
	cout << "   Your Query is: " << Query << endl;
	stmt = Conn->createStatement();
	rs = stmt->executeQuery(Query);
	cout << "   Your product weights are:";
	float *ProductWeights = new float[CountProducts(Conn)];
	for (int i=0 ; rs->next() ; i++){
		ProductWeights[i] = rs->getFloat(1);
		cout << " " << ProductWeights[i];
	}
	cout << endl;
	return ProductWeights;
}

//Sanitize
string Sanitize(string oldQuery){
	string newQuery = "";
	for(int i=0; i<oldQuery.length(); i++) {
		if (oldQuery[i] == '\'' || oldQuery[i] == '\\')
			newQuery = newQuery + '\\';
		newQuery = newQuery + oldQuery[i];
	}
	return newQuery;
}
