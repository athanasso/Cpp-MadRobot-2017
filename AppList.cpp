#include "AppList.h"

//constructor
AppList::AppList()
{
	this->NumberOfInstalledApp = 0;
	InstalledApp = new SimpleApp*[NumberOfInstalledApp];
}

//destructor
AppList::~AppList()
{
	delete[] InstalledApp;
}

//getters
SimpleApp** AppList::getInstalledApp()
{
	return InstalledApp;
}

int AppList::getNumberOfInstalledApp()
{
	return NumberOfInstalledApp;
}

//setters
void AppList::setInstalledApp(SimpleApp** InstalledApp)
{
	this->InstalledApp = InstalledApp;
}

void AppList::setNumberOfInstalledApp(int NumberOfInstalledApp)
{
	this->NumberOfInstalledApp = NumberOfInstalledApp;
}

//methods
void AppList::addOSApp(SimpleApp *newApp) //simulate push_back, add an app to the application array
{
	SimpleApp **temp = new SimpleApp*[NumberOfInstalledApp + 1]; //allocate new array

	for (int i = 0; i < NumberOfInstalledApp; i++) //transfer to new array
		temp[i] = InstalledApp[i];

	if (InstalledApp != NULL)
		delete[] InstalledApp; //delete previous array

	InstalledApp = temp; //renew it
	InstalledApp[NumberOfInstalledApp] = newApp; //last element
	NumberOfInstalledApp++; //update size
}

void AppList::delOSApp(SimpleApp *appToDelete) //simulate single element erase, remove an app from the application array
{
	SimpleApp **temp = new SimpleApp*[NumberOfInstalledApp - 1]; //allocate new array

	for (int i = 0, j = 0; i < NumberOfInstalledApp; i++) //transfer to new array
		if (!((*appToDelete) == (*InstalledApp[i]))) //only the apps that aren't deleted
		{
			temp[j] = InstalledApp[i];
			j++;
		}

	if (InstalledApp != NULL)
		delete[] InstalledApp; //delete previous array

	InstalledApp = temp; //renew it
	NumberOfInstalledApp--; //update size
}

SimpleApp** AppList::findFreeApps() //return simpleapp array and print out result. Finds free office apps
{
	int freeApps = 0;

	for (int i = 0; i < NumberOfInstalledApp; i++)
		if ((InstalledApp[i]->getPrice() == 0) && (dynamic_cast<Application*>(InstalledApp[i])))
			freeApps++; //first count how many office apps meet the criteria so the new array can be created

	SimpleApp **temp = new SimpleApp*[freeApps]; //create new array
	for (int i = 0, j = 0; i < NumberOfInstalledApp; i++) //add only office apps that meet the criteria
		if ((InstalledApp[i]->getPrice() == 0) && (dynamic_cast<Application*>(InstalledApp[i])))
		{
			temp[j] = InstalledApp[i];
			j++;
		}

	//print result section
	cout << "There are " << freeApps << " free office apps, and they are: " << endl;
	for (int i = 0; i < freeApps; i++)
		cout << "- " << temp[i]->getAppName() << endl;
	cout << "-----" << endl;

	return temp; //return the array
}

SimpleApp** AppList::findRateGames() //return simpleapp array and print out result. Finds games have a rating above 4
{
	int ratedApps = 0;

	for (int i = 0; i < NumberOfInstalledApp; i++)
		if ((InstalledApp[i]->getAppRate() > 4) && (dynamic_cast<Game*>(InstalledApp[i])))
			ratedApps++; //first count how many games meet the criteria so the new array can be created

	SimpleApp **temp = new SimpleApp*[ratedApps]; //create new array
	for (int i = 0, j = 0; i < NumberOfInstalledApp; i++) //add only games that meet the criteria
		if ((InstalledApp[i]->getAppRate() > 4) && (dynamic_cast<Game*>(InstalledApp[i])))
		{
			temp[j] = InstalledApp[i];
			j++;
		}

	//print result section
	cout << "There are " << ratedApps << " games with a rating above 4, and they are: " << endl;
	for (int i = 0; i < ratedApps; i++)
		cout << "- " << temp[i]->getAppName() << endl;
	cout << "-----" << endl;

	return temp; //return the array
}

void AppList::removeMaliciousApp(string badDev) //remove all apps made by specific developer
{
	int badApps = 0; //initialize counter of malicious apps

	for (int i = 0; i < NumberOfInstalledApp; i++)
		if (badDev == InstalledApp[i]->getDeveloper().getDeveloperID())
			badApps++; //count how many apps are created by the bad developer

	SimpleApp **temp = new SimpleApp*[NumberOfInstalledApp - badApps]; //create new array
	for (int i = 0, j = 0; i < NumberOfInstalledApp; i++) //put only GOOD apps in the array
		if (badDev != InstalledApp[i]->getDeveloper().getDeveloperID())
		{
			temp[j] = InstalledApp[i];
			j++;
		}

	delete[] InstalledApp; //delete previous array
	InstalledApp = temp; //renew it with only good apps
	NumberOfInstalledApp -= badApps; //update size
}
