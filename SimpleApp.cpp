#include "SimpleApp.h"

//constructors
SimpleApp::SimpleApp()
{
	
}

SimpleApp::SimpleApp(char *AppCode, string AppName, string minOSVersion, Developer developer, float price)
{
	this->AppCode = strdup(AppCode);
	this->AppName = AppName;
	this->minOSVersion = minOSVersion;
	this->developer = developer;
	this->price = price;
	this->UsersEvaluation = (NULL);
	this->numberOfEvaluations = 0;	
}

//destructor
SimpleApp::~SimpleApp()
{
	delete [] UsersEvaluation;
}

//getters
char* SimpleApp::getAppCode()
{
	return AppCode;
}

string SimpleApp::getAppName()
{
	return AppName;
}

string SimpleApp::getMinOSVersion()
{
	return minOSVersion;
}

Developer SimpleApp::getDeveloper()
{
	return developer;
}

Evaluation* SimpleApp::getUsersEvaluation()
{
	return UsersEvaluation;
}

int SimpleApp::getNumberofevaluations()
{
	return numberOfEvaluations;
}

float SimpleApp::getPrice()
{
	return price;
}

//setters
void SimpleApp::setAppCode(char *AppCode)
{
	this->AppCode = AppCode;
}

void SimpleApp::setAppName(string AppName)
{
	this->AppName = AppName;
}

void SimpleApp::setMinOSVersion(string minOSVersion)
{
	this->minOSVersion = minOSVersion;
}

void SimpleApp::setDeveloper(Developer developer)
{
	this->developer = developer;
}

void SimpleApp::setUsersEvaluation(Evaluation *UsersEvaluation)
{
	this->UsersEvaluation = UsersEvaluation;
}

void SimpleApp::setNumberofevaluations(int numberOfEvaluations)
{
	this->numberOfEvaluations = numberOfEvaluations;
}

void SimpleApp::setPrice(float price)
{
	this->price = price;
}

//methods
float SimpleApp::getAppRate() //get average rating of app
{
	float total = 0;

	for(int i = 0; i < numberOfEvaluations; i++)
		total += UsersEvaluation[i].getStars(); //calculate the sum

	return total/numberOfEvaluations; //return average value
}

void SimpleApp::addEvaluation(Evaluation rhs) //add an evaluation to the review array (simulate push_back)
{
	Evaluation* temp = new Evaluation[numberOfEvaluations + 1]; //allocate new array

	for (int i = 0; i < numberOfEvaluations; i++) //transfer to new array
		temp[i] = UsersEvaluation[i];

	if (UsersEvaluation != NULL) //delete previous array
		delete[] UsersEvaluation;

	UsersEvaluation = temp; //renew it
	UsersEvaluation[numberOfEvaluations] = rhs; //last element
	numberOfEvaluations++; //update size
}
	
ostream& SimpleApp::print(ostream& os) //print function of parent
{
	os << "-----\n~Application info:" << endl;
	os << "ID:     " << AppCode << endl ;
	os << "Name:   " << AppName << endl;
	os << "min.OS: " << minOSVersion  << endl;
	os << "Price:  " << price << endl;
	os << "\n";
	
	os << developer;
	os << "\n~User reviews:" << endl;
	
	for(int i = 0; i < numberOfEvaluations - 1; i++)
		os << UsersEvaluation[i] << "-" << endl;
	os << UsersEvaluation[numberOfEvaluations - 1];
		
	return os;
}

//operator for comparison
bool SimpleApp::operator == (const SimpleApp &x) //compare based on ID
{
	if (!strcmp(AppCode, x.AppCode))
		return true;
	return false;
}
