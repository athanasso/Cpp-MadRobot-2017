#include "Game.h"

//constructors
Game::Game()
	: SimpleApp()
{
	
}

Game::Game(char *AppCode, string AppName, string minOSVersion, Developer developer, float price, string category, bool isOnline)
	: SimpleApp(AppCode, AppName, minOSVersion, developer, price)
{
	this->GameCategory = category;
	this->isOnline = isOnline;
}

//destructor
Game::~Game()
{
	
}

//getters
string Game::getGameCategory()
{
	return GameCategory;
}

bool Game::getIsOnline()
{
	return isOnline;
}

//setters
void Game::setGameCategory(string GameCategory)
{
	this->GameCategory = GameCategory;
}

void Game::setIsOnline(bool isOnline)
{
	this->isOnline = isOnline;
}

//method
ostream& Game::print(ostream& os) //print (inherited from parent because virtual)
{
	SimpleApp::print(os);

	os << endl << "Category: " << GameCategory <<endl;

	(isOnline) ? os << "Internet connection required" << endl << "-----" << endl : os << "Singleplayer only" << endl << "-----" << endl;

	return os;
}
