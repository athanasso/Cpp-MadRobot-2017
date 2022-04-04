#ifndef DEVELOPER_H
#define DEVELOPER_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <string.h>

using namespace std;

class Developer
{
	private:
		string DeveloperID;
		char *DeveloperName;
		string Email;
	
	public:
		//constructors
		Developer();
		Developer(string, char*, string);
		//destructor
		~Developer();
		//getters
		string getDeveloperID();
		char* getDeveloperName();
		string getEmail();
		//setters
		void setDeveloperID(string);
		void setDeveloperName(char*);
		void setEmail(string);
		//operator for printing
		friend ostream & operator<<(ostream &os, const Developer& x); //for printing
};

#endif
