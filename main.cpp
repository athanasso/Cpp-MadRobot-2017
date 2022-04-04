/*
оладийг еяцасиа апо
тулотеоус кеомаямт стежамиай 171012
&
елламоугк ахамасопоукос 171049
*/
#include "AppList.h"

#include <fstream>
#include <vector>

int main()
{
	AppList MadRobot; //app handler (system)

	//2 developers
	Developer developer1("01", "Timothy", "cs171012@uniwa.gr");
	Developer developer2("02", "Manos", "cs171049@uniwa.gr");
	//3 evaluations by users
	Evaluation review1("user1", 4.3, "What a GREAT app, i just wish it made me toast.");
	Evaluation review2("user2", 4.5, "I love this app, but nobody can be perfect.");
	Evaluation review3("user3", 3.7, "Could be better.");
	//2 apps
	Application *office_app = new Application("A01", "Uniwa office", "1.0", developer1, 0);
	Game *game_app = new Game("G01", "Pass the class!", "2.0", developer2, 4.99, "FPS", true);
	//reviews for apps
	office_app->addEvaluation(review1);
	office_app->addEvaluation(review3);
	game_app->addEvaluation(review2);
	//files for office application
	office_app->AddFilesHandled("Eclass_pdf");
	office_app->AddFilesHandled("Eclass_doc");
	//add the apps to our store
	MadRobot.addOSApp(office_app);
	MadRobot.addOSApp(game_app);

	//self explanatory code thanks to print messages
	cout << "First two apps added in code:\n" << endl;
	MadRobot.getInstalledApp()[0]->print(cout);
	MadRobot.getInstalledApp()[1]->print(cout);
	MadRobot.delOSApp(office_app);
	MadRobot.delOSApp(game_app);
	cout << "\nNow those 2 apps have been deleted from the system and 5 new apps are added, 3 that are identical to the first one, and 2 to the second one." << endl;
	MadRobot.addOSApp(office_app);
	MadRobot.addOSApp(game_app);
	MadRobot.addOSApp(office_app);
	MadRobot.addOSApp(office_app);
	MadRobot.addOSApp(game_app);
	cout << "\nNow the 3 apps that are made by the developer known as Timothy will be deleted because he has been deemed a malicious developer" << endl;
	cout << "Applications in our store before the removal of malicious developer \"Timothy\": " << MadRobot.getNumberOfInstalledApp() << endl;
	MadRobot.removeMaliciousApp("01");
	cout << "Applications in our store after the removal of malicious developer \"Timothy\": " << MadRobot.getNumberOfInstalledApp() << endl;
	cout << "\nNow removing the other apps too for cleanup purposes." << endl;
	MadRobot.removeMaliciousApp("02");
	cout << "\nNow re-adding the first two apps again so we can use the methods of finding free games and finding office apps with an average rating above 4.0" << endl;
	MadRobot.addOSApp(office_app);
	MadRobot.addOSApp(game_app);
	cout << "Average score from reviews of 1st app: " << MadRobot.getInstalledApp()[0]->getAppRate() << endl;
	cout << "Average score from reviews of 2nd app: " << MadRobot.getInstalledApp()[1]->getAppRate() << endl << endl;	
	//we were tasked to make the methods return an array, so we did that but we don't use the array anywhere else, also the methods print out messages
	SimpleApp **socialism = MadRobot.findFreeApps();
	SimpleApp **goodRating = MadRobot.findRateGames();
	//making report with the 2 apps
	try
	{
		ofstream report;
		report.open("report.txt");
		if (report.fail())
			throw 1;
		for(int i = 0; i < MadRobot.getNumberOfInstalledApp(); i++)
		    MadRobot.getInstalledApp()[i]->print(report); //print is overloaded to accept any output stream
	    report.close();
		cout << "\nA report of the system's apps has been published to a textfile called \"reports.txt\"" << endl << endl;
	}
	catch(int exc)
	{
		cerr << "Could not create or open the file \"reports.txt\"\n" << endl << endl;
	}

	//load system data from file
	cout << "Now application data will be retrieved from the file known as \"load.txt\", that data is:\n" << endl;
	int filesHandledNum, numberOfEvaluations, boolConversion;
	bool isOnline;
	float price, Stars;
	string temp, app_type, AppName, minOSVersion, DeveloperID, Email, Username, Comments, fileHandled, GameCategory;
	char *AppCode,*DeveloperName;
	//for office applications
	vector <string> filesHandled;
	//for evaluation objects
	vector <string> Username_vector;
	vector <float> Stars_vector;
	vector <string> Comments_vector;
	try
	{
		ifstream load_file;
		load_file.open("load.txt");
		if (load_file.fail())
			throw 0;

		while(!load_file.eof()) //read until end of file
		{
			getline(load_file, app_type, ','); //type of app (game or office application)

			getline(load_file, temp, ',');
			char AppCode[temp.length() + 1]; //AppCode
			strcpy(AppCode, temp.c_str());

			getline(load_file, AppName, ','); //AppName

			getline(load_file, minOSVersion, ','); //minOSVersion

			getline(load_file, DeveloperID, ','); //developer DeveloperID

			getline(load_file, temp, ',');
			char DeveloperName[temp.length() + 1]; //developer DeveloperName
			strcpy(DeveloperName, temp.c_str());

			getline(load_file, Email, ','); //developer Email

			getline(load_file, temp, ','); //how many reviews to read
			numberOfEvaluations = stoi(temp);

			for(int i = 0; i < numberOfEvaluations ; i++)
			{
				getline(load_file, Username, ','); //review's username
				Username_vector.push_back(Username);

				getline(load_file, temp, ','); //review's score
				Stars = stof(temp);
				Stars_vector.push_back(Stars);

				getline(load_file, Comments, ','); //review's comment
				Comments_vector.push_back(Comments);
			}
			getline(load_file, temp, ','); //price
			price = stof(temp);

			if(app_type == "Application") //if office application
			{
				getline(load_file, temp, ',');
				filesHandledNum = stoi(temp); //how many files can the office app handle

				for(int i = 0; i < filesHandledNum - 1; i++)
				{
					getline(load_file, fileHandled, ',');
					filesHandled.push_back(fileHandled); //the files the app handles
				}
				getline(load_file, fileHandled, '\n');
				filesHandled.push_back(fileHandled); //get the last file the app handles but read until new line not delimeter

				//application creation
				Developer dev(DeveloperID, DeveloperName, Email); //create developer
				Application *app = new Application(AppCode, AppName, minOSVersion, dev, price); //create the office app
				for(int i = 0; i < numberOfEvaluations; i++) //create add evaluations to the app
				{
					Evaluation ev(Username_vector[i], Stars_vector[i], Comments_vector[i]);
					app->addEvaluation(ev);
				}
				MadRobot.addOSApp(app); //add the app to the system
				for(int i = 0; i < filesHandled.size(); i++) //add files the app can handle to the apps array
					app->AddFilesHandled(filesHandled[i]);
				filesHandled.clear(); //clear the temp array
			}
			else if (app_type == "Game") //if game
			{
				getline(load_file, GameCategory, ',');

				getline(load_file, temp, '\n'); //read isOnline
				boolConversion = stoi(temp);
				(boolConversion == 1)? isOnline = true : isOnline = false ; //check if game requires connection to play

				Developer dev(DeveloperID, DeveloperName, Email);  //create developer
				Game *app = new Game(AppCode, AppName, minOSVersion, dev, price, GameCategory, isOnline); //create the game
				for(int i = 0; i < numberOfEvaluations; i++) //create and add evaluations to the app
				{
					Evaluation ev(Username_vector[i],Stars_vector[i],Comments_vector[i]);
					app->addEvaluation(ev);
				}
				MadRobot.addOSApp(app); //add the app to the system
			}
			else 
				throw 1;
			//clear the no-longer-needed vectors
			Username_vector.clear();
			Stars_vector.clear();
			Comments_vector.clear();
			}
		load_file.close();
		for(int i = 2; i < MadRobot.getNumberOfInstalledApp(); i++) //print the new applications
		    MadRobot.getInstalledApp()[i]->print(cout);
	}
	catch(int e)
	{
		switch (e)
		{
			case 0:
				cerr << "\nCould not open or find the file \"load.txt\"\n" << endl;
			case 1:
				cerr << "\nWrong information in the file \"load.txt\"\n" << endl;
		}
	}

	//savefile creation, where all information of the app system is saved
	try //print is overloaded to accept any output stream
	{
		SimpleApp** temp = MadRobot.getInstalledApp(); //make "temp" shorthand for MadRobot.getInstalledApp() so i don't have to type it every time in full
		ofstream save_file;
		save_file.open("save.txt");
		if (save_file.fail())
			throw 1;
		for(int i = 0; i < MadRobot.getNumberOfInstalledApp(); i++) //retrieve ALL data of each application and store it in a single line of the save file
		{
			//determine what kind of app it is
			if (dynamic_cast<Application*>(temp[i]))
			    save_file << "Application,";
			else if (dynamic_cast<Game*>(temp[i]))
			    save_file << "Game,";
			else
				throw 1;

			//generic info for all apps
			save_file << temp[i]->getAppCode() << "," <<  temp[i]->getAppName() << "," <<  temp[i]->getMinOSVersion() << "," <<  temp[i]->getDeveloper().getDeveloperID() << "," <<  temp[i]->getDeveloper().getDeveloperName() << "," <<  temp[i]->getDeveloper().getEmail() << "," <<  temp[i]->getNumberofevaluations() << ",";
			for (int j = 0; j < temp[i]->getNumberofevaluations(); j++)
				save_file << temp[i]->getUsersEvaluation()[j].getUsername() << "," << temp[i]->getUsersEvaluation()[j].getStars() << "," << temp[i]->getUsersEvaluation()[j].getComments() << ",";
			save_file << temp[i]->getPrice() << ",";

			//specific info for office apps
			if (dynamic_cast<Application*>(temp[i]))
			{
				//dynamic cast has to be used in order to check if a pointer is what we want it to be and also to execute children methods from parent pointers
			    save_file << dynamic_cast<Application*>(temp[i])->getFilesHandled().size() << ((dynamic_cast<Application*>(temp[i])->getFilesHandled().size() != 0)? "," : "");
				int k = 0;
				for(auto j : dynamic_cast<Application*>(temp[i])->getFilesHandled())
					if (k != dynamic_cast<Application*>(temp[i])->getFilesHandled().size() - 1)
					{
						save_file << j << ",";
						k++;
					}
					else
						save_file << j;
				save_file << endl;
			}
			else //specific info for games
			    save_file << dynamic_cast<Game*>(temp[i])->getGameCategory() << "," << ((dynamic_cast<Game*>(temp[i])->getIsOnline()) ? "1" : "0") << endl;
		}
	    save_file.close();
		cout << "\nThe system's application data has been saved to \"save.txt\"" << endl;
	}
	catch(int exc)
	{
		switch (exc)
		{
			case 0:
				cerr << "\nCould not open or find the file \"load.txt\"\n" << endl;
			case 1:
				cerr << "\nWrong type of app in InstalledApp\n" << endl;
		}
	}
	return 0;
}
