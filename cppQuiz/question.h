#ifndef CPPQUIZ_QUESTION_H
#define CPPQUIZ_QUESTION_H

#include "precompile.h"

class Question {
public:
	Question(std::string, std::string*, int);
	std::string getTitle();
	std::string getItemAtIndex(int);
	int getOptionCount();
private:
	std::string title;
	std::string* answers;
	int optionCount;
};

#endif