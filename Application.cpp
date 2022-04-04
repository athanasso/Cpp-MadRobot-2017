#include <iterator> 
#include "Application.h"

//constructors
Application::Application()
	: SimpleApp()
{
	
}

Application::Application(char *AppCode, string AppName, string minOSVersion, Developer developer, float price)
	: SimpleApp(AppCode, AppName, minOSVersion, developer, price)
{
	
}

//destructor
Application::~Application()
{
	
}

//getter
list<string> Application::getFilesHandled()
{
	return filesHandled;
}

//setter
void Application::setFilesHandled(list<string> filesHandled)
{
	this->filesHandled = filesHandled;
}


//methods
void Application::AddFilesHandled(string program) //push backs a string to the string list
{
	filesHandled.push_back(program);
}

ostream& Application::print(ostream& os) //print (inherited from parent because virtual)
{
	SimpleApp::print(os);

	os << endl << "This app supports the following file types:" << endl;

	for (auto i : filesHandled)
		os << i << endl;

	os << "-----" << endl;
	
	return os;
}
