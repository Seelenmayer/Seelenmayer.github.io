/**
 * @file Invoice.cpp
 * @author Clayton Seelenmayer
 * @date May 1st 2017
 * @brief Generate invoices.
 */

//Libraries
#include <iostream>
#include <fstream>
#include "src.h"
using namespace std;
using namespace oracle::occi;

//Calculate Tax Receipt
void Invoice(Connection *Conn){

	//Get CID from User
	string CID;
	string temp;
	cout << "   Please enter client CID to print their invoice." << endl << endl << "   ";
	cin >> CID;
	cout << endl;
	getline(cin, temp);

	//Initialize File
	string Filename = "";
	Filename = Filename + "Invoice-For-Client-[" + CID + "].txt";
	ofstream File;
	File.open (Filename.c_str());
	if (File.fail()) throw "File Failed to Open";

	//Initializations for Query
	string Query;
	Statement *stmt;
	ResultSet *rs;
	string Name;
	string Address;
	string Phone;
	string Email;

	//Execute Query
	cout << "   Generating invoice..." << endl;
	Query = "SELECT Name, Address, Phone, Email FROM Client WHERE CID = " + CID;
	cout << "   Your Query is: " << Query << endl;
	stmt = Conn->createStatement();
	rs = stmt->executeQuery(Query);
	for (int i=0 ; rs->next() ; i++){
		Name = rs->getString(1);
		Address = rs->getString(2);
		Phone = rs->getString(3);
		Email = rs->getString(4);
	}

	//Populate File
	File << "Max's Mushrooms" << endl;
	File << "Invoice for " << Name << "." << endl;
	File << "Client ID: " << CID << endl;
	File << "Client Address: " << Address << "." << endl;
	File << "Client Phone: " << Phone << "." << endl;
	File << "Client Email: " << Email << "." << endl;

	//Cleanup
	cout << "   Invoice File Generated." << endl << endl;
	File.close();
}
