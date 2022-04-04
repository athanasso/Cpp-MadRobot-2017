#include "Developer.h"

//constructors
Developer::Developer()
{
	this->DeveloperID ="N/A";
	this->Email = "N/A"; 
}

Developer::Developer(string id, char* name, string email)
{
	
	this->DeveloperID = id;
	this->DeveloperName = strdup(name);
	this->Email = email;
}

//destructor
Developer::~Developer()
{
	
}

//getters
string Developer::getDeveloperID()
{
	return DeveloperID;
}

char* Developer::getDeveloperName()
{
	return DeveloperName;
}

string Developer::getEmail()
{
	return Email;
}

//setters
void Developer::setDeveloperID(string DeveloperID)
{
	this->DeveloperID = DeveloperID;
}

void Developer::setDeveloperName(char *DeveloperName)
{
	this->DeveloperName = DeveloperName;
}

void Developer::setEmail(string Email)
{
	this->Email = Email;
}

//operator for printing
ostream & operator<<(ostream &os, const Developer& x) //used for printing
{
    return os << "~Developer profile:\nID:    " << x.DeveloperID << "\nName:  " << x.DeveloperName << "\nEmail: " << x.Email << endl;
}
