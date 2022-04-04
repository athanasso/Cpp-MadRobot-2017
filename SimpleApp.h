#ifndef SIMPLEAPP_H
#define SIMPLEAPP_H

#include <iostream>

#include "Developer.h"
#include "Evaluation.h"

using namespace std;

class SimpleApp
{	
	private:
		char *AppCode;
		string AppName;
		string minOSVersion;
		Developer developer;
		Evaluation *UsersEvaluation;
		int numberOfEvaluations;
		float price;

	public:
		//constructors
		SimpleApp();
		SimpleApp(char *, string, string, Developer, float);
		//destructor
		~SimpleApp();
		//getters
		char* getAppCode();
		string getAppName();
		string getMinOSVersion();
		Developer getDeveloper();
		Evaluation* getUsersEvaluation();
		int getNumberofevaluations();
		float getPrice();
		//setters
		void setAppCode(char*);
		void setAppName(string);
		void setMinOSVersion(string);
		void setDeveloper(Developer);
		void setUsersEvaluation(Evaluation*);
		void setNumberofevaluations(int);
		void setPrice(float);
		//methods
		float getAppRate(); //get average rating of app
		void addEvaluation(Evaluation); //add an evaluation to the review array (simulate push_back)
		virtual ostream& print(ostream& os); //print function of parent
		//operator for comparison
		bool operator == (const SimpleApp &); //compare based on ID
};

#endif
