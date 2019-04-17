#include "question.h"

Question :: Question () { }

Question :: Question (std::string ask1, std::vector <std::string> chc, int ans) {
	ask = ask1;
	choice = chc;
	answer = ans;
}

std::string Question :: getAsk () {
	return ask;
}

std::string Question :: getChoice (int num) {
	return choice[num];
}

int Question :: getAns () {
	return answer;
}
