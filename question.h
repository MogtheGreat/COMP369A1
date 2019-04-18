#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

class Question {
	std::string ask;
	std::vector <std::string> choice;
	char answer;
public:
	// Constructor
	Question ();
	Question (std::string ask1, std::vector <std::string> chc, char ans);
	void setAsk (std::string ask1);
	void setChoice (std::vector <std::string> chc);
	void setAnswer (char ans);
	std::string getAsk ();
	std::string getChoice (int num = 0);
	char getAns ();
};

#endif
