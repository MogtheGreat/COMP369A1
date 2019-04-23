/*
Title: main.cpp
Description: An object that represents a question from the textbook.
Author: Michael G. Oranski
ID: 2743708
Date: Apr. 18, 2019
*/
#include "question.h"

/*
	Default Constructor
*/
Question :: Question () {
	ask = "";
	answer = ' ';
}

/*
	Constructor

	Param:
		ask1 		- The question from the textbook
		chc 		- The list of choices for the question
		ans 		- The answer to the question
*/
Question :: Question (std::string ask1, std::vector <std::string> chc, char ans) {
	ask = ask1;
	choice = chc;
	answer = ans;
}

/*
	Changes the question.
*/
void Question::setAsk (std::string ask1) {
	ask = ask1;
}

/*
	Changes the list of choice
*/
void Question::setChoice (std::vector <std::string> chc) {
	choice = chc;
}

/*
	Changes the answer
*/
void Question::setAnswer (char ans) {
	answer = ans;
}

/*
	Gives the question in the object
*/
std::string Question :: getAsk () {
	return ask;
}

/*
	Gives the list of choice for the question
*/
std::string Question :: getChoice (int num) {
	return choice[num];
}

/*
	Returns the number of choices for the question
*/
int Question :: numChoice () {
	return (int) choice.size();
}

/*
	Returns the answer for the question
*/
char Question :: getAns () {
	return answer;
}
