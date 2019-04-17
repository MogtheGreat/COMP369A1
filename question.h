#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

class Question {
	std::string ask;
	std::vector <std::string> choice;
	int answer;
public:
	// Constructor
	Question ();
	Question (std::string ask1, std::vector <std::string> chc, int ans);
	std::string getAsk ();
	std::string getChoice (int num = 0);
	int getAns ();
};

#endif
