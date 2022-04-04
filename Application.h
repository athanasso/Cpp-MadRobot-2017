#ifndef APPLICATION_H
#define APPLICATION_H

#include <list>

#include "SimpleApp.h"

class Application : public SimpleApp
{	
	private:
		list<string> filesHandled;

	public:
		//constructors
		Application();
		Application(char *, string, string, Developer, float);
		//destructor
		~Application();
		//getter
		list<string> getFilesHandled();
		//setter
		void setFilesHandled(list<string>);
		//methods
		void AddFilesHandled(string); //push backs a string to the string list
		ostream& print(ostream& os); //print (inherited from parent because virtual)
};

#endif
