//Clayton Seelenmayer     Clientele Invoice Manager      CSCI 370

//Libraries
#include <iostream>
#include "src.h"
using namespace std;
using namespace oracle::occi;

//C Insert Data
void InsertData(Connection *Conn){

	//Initialize
	string Query = "INSERT INTO ";
	Statement *stmt;
	char UserCommand;
	string UserInput;

	//Prompt Until Valid Command
	while (TRUE){

		//Table Prompt
		cout << "   Which Table will you insert into? Please enter a command." << endl
			 << "   A for Client." << endl
			 << "   B for Orders." << endl
			 << "   C for Products." << endl
			 << "   D for Units." << endl
			 << "   Q for Quit." << endl
			 << endl;

		//Get User Command
		cout << "   ";
		cin >> UserCommand;
		UserCommand = toupper(UserCommand);
		string temp;
		getline (cin, temp);
		cout << endl;
		switch(UserCommand){

			//Client Table Data
			case 'A':{

				//Iniitialize
				Query = Query + "Client VALUES ('";

				//Client ID
				cout << "   Please enter the Client ID." << endl << "   ";
				cin >> UserInput;
				getline(cin, temp);
				Query = Query + UserInput + "', '";

				//Client Name
				cout << "   Please enter the Client name." << endl << "   ";
				cin >> UserInput;
				getline(cin, temp);
				Query = Query + UserInput + "', '";

				//Client Address
				cout << "   Please enter the Client address." << endl << "   ";
				cin >> UserInput;
				getline(cin, temp);
				Query = Query + UserInput + "', '";

				//Client Phone
				cout << "   Please enter the Client phone." << endl << "   ";
				cin >> UserInput;
				getline(cin, temp);
				Query = Query + UserInput + "', '";

				//Client Email
				cout << "   Please enter the Client email." << endl << "   ";
				cin >> UserInput;
				getline(cin, temp);
				Query = Query + UserInput + "')";

				//Execute Query
				cout << endl << "   Your Query is:" << endl;
				cout << "   Client ('CID', 'Name', 'Street', 'Phone', 'Email')" << endl;
				cout << "   " << Query << endl << endl;
				stmt = Conn->createStatement(Query);
				stmt->executeQuery();
				cout << "   Insertion complete." << endl << endl;
				return;
				break;
			}

			//Orders Table Data
			case 'B':{

				//Iniitialize
				Query = Query + "Orders VALUES ('";

				//Order ID
				cout << "   Please enter the Order ID." << endl << "   ";
				cin >> UserInput;
				getline(cin, temp);
				Query = Query + UserInput + "', '";

				//Order Client ID
				cout << "   Please enter the Client ID." << endl << "   ";
				cin >> UserInput;
				getline(cin, temp);
				Query = Query + UserInput + "', '";

				//Order Price
				cout << "   Please enter the Order Price." << endl << "   ";
				cin >> UserInput;
				getline(cin, temp);
				Query = Query + UserInput + "', '";

				//Order Weight
				cout << "   Please enter the Order Weight." << endl << "   ";
				cin >> UserInput;
				getline(cin, temp);
				Query = Query + UserInput + "')";

				//Execute Query
				cout << endl << "   Your Query is:" << endl;
				cout << "   Orders ('OID', 'CID', 'Price', 'Weight')" << endl;
				cout << "   " << Query << endl << endl;
				stmt = Conn->createStatement(Query);
				stmt->executeQuery();
				cout << "   Insertion complete." << endl << endl;
				return;
				break;
			}

			//Products Table Data
			case 'C':{

				//Iniitialize
				Query = Query + "Products VALUES ('";

				//Product PID
				cout << "   Please enter the Product ID." << endl << "   ";
				cin >> UserInput;
				getline(cin, temp);
				Query = Query + UserInput + "', '";

				//Product OID
				cout << "   Please enter the Order ID." << endl << "   ";
				cin >> UserInput;
				getline(cin, temp);
				Query = Query + UserInput + "', '";

				//Product Name
				cout << "   Please enter the Product Name." << endl << "   ";
				cin >> UserInput;
				getline(cin, temp);
				Query = Query + UserInput + "', '";

				//Product Price
				cout << "   Please enter the Product Price." << endl << "   ";
				cin >> UserInput;
				getline(cin, temp);
				Query = Query + UserInput + "', '";

				//Product Weight
				cout << "   Please enter the Product Weight in lbs." << endl << "   ";
				cin >> UserInput;
				getline(cin, temp);
				Query = Query + UserInput + "')";

				//Execute Query
				cout << endl << "   Your Query is:" << endl;
				cout << "   Products ('PID', 'OID', 'Name', 'Price', 'Weight)" << endl;
				cout << "   " << Query << endl << endl;
				stmt = Conn->createStatement(Query);
				stmt->executeQuery();
				cout << "   Insertion complete." << endl << endl;
				return;
				break;
			}

			//Units Table Data
			case 'D':{

				//Iniitialize
				Query = Query + "Units VALUES ('";

				//Unit UID
				cout << "   Please enter the Unit ID." << endl << "   ";
				cin >> UserInput;
				getline(cin, temp);
				Query = Query + UserInput + "', '";

				//Unit Name
				cout << "   Please enter the Product Name." << endl << "   ";
				cin >> UserInput;
				getline(cin, temp);
				Query = Query + UserInput + "', '";

				//Unit Count
				cout << "   Please enter the Product Count." << endl << "   ";
				cin >> UserInput;
				getline(cin, temp);
				Query = Query + UserInput + "')";

				//Execute Query
				cout << endl << "   Your Query is:" << endl;
				cout << "   Unit ('UID', 'Name', 'Count')" << endl;
				cout << "   " << Query << endl << endl;
				stmt = Conn->createStatement(Query);
				stmt->executeQuery();
				cout << "   Insertion complete." << endl << endl;
				return;
				break;
			}

			case 'E':{

				//Iniitialize
				Query = Query + "Has VALUES ('";

				//Has OID
				cout << "   Please enter the Order ID." << endl << "   ";
				cin >> UserInput;
				getline(cin, temp);
				Query = Query + UserInput + "', '";

				//Has PID
				cout << "   Please enter the Product ID." << endl << "   ";
				cin >> UserInput;
				getline(cin, temp);
				Query = Query + UserInput + "', '";

				//Has Quantity
				cout << "   Please enter the Quantity" << endl << "   ";
				cin >> UserInput;
				getline(cin, temp);
				Query = Query + UserInput + "')";

				//Execute Query
				cout << endl << "   Your Query is:" << endl;
				cout << "   Has ('OID', 'PID', 'Quantity')" << endl;
				cout << "   " << Query << endl;
				stmt = Conn->createStatement(Query);
				stmt->executeQuery();
				cout << "   Insertion complete." << endl << endl;
				return;
				break;
			}

			//Quit
			case 'Q':{
				cout << "   Input Aborted." << endl << endl;
				return;
				break;
			}
		}
	}
}
