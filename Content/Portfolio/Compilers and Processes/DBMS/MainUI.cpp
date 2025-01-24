/**
 * @file MainUI.cpp
 * @author Clayton Seelenmayer
 * @date May 1st 2017
 * @brief Main application user interface routines.
 */

//Includes
#include <iostream>
#include <occi.h>
#include <termios.h>
#include <unistd.h>
#include <cstdlib>
#include <string>
using namespace std;
using namespace oracle::occi;
#include "src/src.h"

//Read hidden username.
void userLogin(string &Username, string &Password){

	//Hidden Text On
	struct termios settings;
	tcgetattr( STDIN_FILENO, &settings );
	settings.c_lflag =  (settings.c_lflag & ~(ECHO));
	tcsetattr( STDIN_FILENO, TCSANOW, &settings );

	//Get Username
	cout << "   Enter your username: ";
	getline(cin, Username);
	cout << endl;

	//Get Password
	cout << "   Enter your password: ";
	getline(cin, Password);
	cout << endl << endl;

	//Hidden Text Off
	settings.c_lflag = (settings.c_lflag |   ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &settings );
	return;
}

//User Prompt
void UserPrompt(){
	cout << "   Please enter a command." << endl
		 << "   A to create the database." << endl
		 << "   B to delete the database." << endl
		 << "   C to insert new data." << endl
		 << "   D to insert standing data." << endl
		 << "   E to create a customer invoice." << endl
		 << "   F to calculate total weight." << endl
		 << "   G to calculate total gross proffit." << endl
		 << "   H to view help menu." << endl
		 << "   Q to quit." << endl
		 << endl;
}

//Main Routine
int main(){

	//Introduction
	cout << endl
		 << "*********************************************************" << endl
		 << "***                                                   ***" << endl
		 << "***  Welcome to the DBMS Invoice Managing Application ***" << endl
		 << "***                                                   ***" << endl
		 << "*********************************************************" << endl
		 << endl;

	//Oracle Server Address
	const string Address = "sunfire.csci.viu.ca";

	//User Login
	string Username;
	string Password;
	userLogin(Username, Password);

	//Establish Connection
	try{

		//Connect and Login
		Environment *Env = Environment::createEnvironment();
		Connection *Conn = Env->createConnection (Username, Password, Address);

		//User Interface
		char UserCommand;
		while (UserCommand != 'Q'){
			UserPrompt();
			cout << "   ";
			cin >> UserCommand;
			cout << endl;
			UserCommand = toupper(UserCommand);
			string temp;
			getline(cin, temp);

			switch(UserCommand){
				case 'A':
					CreateDatabase(Conn);
					break;
				case 'B':
					DeleteDatabase(Conn);
					break;
				case 'C':
					InsertData(Conn);
					break;
				case 'D':
					Populate(Conn);
					break;
				case 'E':
					Invoice(Conn);
					break;
				case 'F':
					NetWeight(Conn);
					break;
				case 'G':
					GrossProffit(Conn);
					break;
				case 'H':
					Help();
					break;
			}
		}

		//Close
		Env->terminateConnection(Conn);
		Environment::terminateEnvironment(Env);
		cout << "*********************************" << endl
			 << "***                           ***" << endl
			 << "***  Thank you for using the  ***" << endl
			 << "***  DBMS Invoice Manager     ***" << endl
			 << "***                           ***" << endl
			 << "*********************************" << endl
			 << endl;
	}

	//Connection Failed
	catch (SQLException & e){
		cout << endl
			 << "*************************************" << endl
			 << "***                               ***" << endl
			 << "***  Connection To Oracle Failed  ***" << endl
			 << "***                               ***" << endl
			 << "*************************************" << endl
			 << endl;
		cout << "   " << e.what() << endl << endl;
	}
}
