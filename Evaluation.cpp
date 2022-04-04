#include "Evaluation.h"

//constructors
Evaluation::Evaluation()
{
	this->Username = "N/A";
	this->Stars = 0;
	this->Comments = "No comments";
}

Evaluation::Evaluation(string usname, float stars, string comments)
{
	this->Username = usname;
	this->Stars = stars;
	this->Comments = comments;
}

//destructor
Evaluation::~Evaluation()
{
	
}

//getters
string Evaluation::getUsername()
{
	return Username;
}

float Evaluation::getStars()
{
	return Stars;
}

string Evaluation::getComments()
{
	return Comments;
}

//setters
void Evaluation::setUsername(string Username)
{
	this->Username = Username;
}

void Evaluation::setStars(float Stars)
{
	this->Stars = Stars;
}

void Evaluation::setComments(string Comments)
{
	this->Comments = Comments;
}

//operator for printing
ostream & operator<<(ostream &os, const Evaluation& x) //used for printing
{
    return os << "Username: " << x.Username << "\nRating:   " << x.Stars << "\nReview:   " << x.Comments << endl;
}
