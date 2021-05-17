#ifndef CPPQUIZ_QUESTION_H
#define CPPQUIZ_QUESTION_H

#include "precompile.h"

class Question {
public:
	Question(std::string, std::string*, int, int, bool = false);
	std::string getTitle();
	std::string getItemAtIndex(int);
	int getOptionCount();
	bool isCorrect(int);
private:
	std::string title;
	std::string* answers;
	std::vector<int> order;
	int optionCount;
	int correctAnswer;
};

#endif