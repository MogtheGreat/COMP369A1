/*
Title: main.cpp
Description: An object that represents a question from the textbook.
Author: Michael G. Oranski
ID: 2743708
Date: Apr. 18, 2019
*/


#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

class Question {
	std::string ask;
	std::vector <std::string> choice;
	char answer;
public:
	Question (); // Default Constructor
	Question (std::string ask1, std::vector <std::string> chc, char ans);
	void setAsk (std::string ask1);
	void setChoice (std::vector <std::string> chc);
	void setAnswer (char ans);
	std::string getAsk ();
	std::string getChoice (int num = 0);
	int numChoice ();
	char getAns ();
};

#endif
