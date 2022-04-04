#ifndef APPLIST_H
#define APPLIST_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <string.h>

#include "Developer.h"
#include "Evaluation.h"
#include "SimpleApp.h"
#include "Game.h"
#include "Application.h"

using namespace std;

class AppList
{
	private:
		SimpleApp **InstalledApp;
		int NumberOfInstalledApp;

	public:
		//constructor
		AppList();
		//destructor
		~AppList();
		//getters
		SimpleApp** getInstalledApp();
		int getNumberOfInstalledApp();
		//setters
		void setInstalledApp(SimpleApp**);
		void setNumberOfInstalledApp(int);
		//methods
		void addOSApp(SimpleApp*); //simulate push_back, add an app to the application array
		void delOSApp(SimpleApp*); //simulate single element erase, remove an app from the application array
		SimpleApp** findFreeApps(); //return simpleapp array and print out result. Finds free office apps
		SimpleApp** findRateGames(); //return simpleapp array and print out result. Finds games have a rating above 4
		void removeMaliciousApp(string); //remove all apps made by specific developer
};

#endif
