#ifndef GAME_H
#define GAME_H

#include "SimpleApp.h"

using namespace std;

class Game : public SimpleApp
{
	private:	
		string GameCategory;
		bool isOnline;
	
	public:
		//constructors
		Game();
		Game(char *, string, string, Developer, float, string, bool);
		//destructor
		~Game();
		//getters
		string getGameCategory();
		bool getIsOnline();
		//setters
		void setGameCategory(string);
		void setIsOnline(bool);
		//method
		ostream& print(ostream& os); //print (inherited from parent because virtual)
};

#endif
