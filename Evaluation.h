#ifndef EVALUATION_H
#define EVALUATION_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <string.h>

using namespace std;

class Evaluation
{	
	private:
		string Username;
		float Stars;
		string Comments;
		
	public:
		//constructors
		Evaluation();
		Evaluation(string, float, string);
		//destructor
		~Evaluation();
		//getters
		string getUsername();
		float getStars();
		string getComments();
		//setters
		void setUsername(string);
		void setStars(float);
		void setComments(string);
		//operator for printing
		friend ostream & operator<<(ostream &os, const Evaluation& x); //for printing
};

#endif
