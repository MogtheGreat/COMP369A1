#include "question.h"

Question :: Question () {
	ask = "";
	answer = ' ';
}

Question :: Question (std::string ask1, std::vector <std::string> chc, char ans) {
	ask = ask1;
	choice = chc;
	answer = ans;
}

void Question::setAsk (std::string ask1) {
	ask = ask1;
}

void Question::setChoice (std::vector <std::string> chc) {
	choice = chc;
}

void Question::setAnswer (char ans) {
	answer = ans;
}

std::string Question :: getAsk () {
	return ask;
}

std::string Question :: getChoice (int num) {
	return choice[num];
}

char Question :: getAns () {
	return answer;
}
