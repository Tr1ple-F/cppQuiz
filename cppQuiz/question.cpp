#include "question.h"

Question::Question(std::string title, std::string* answers, int optionCount)
{
	this->title = title;
	this->answers = answers;
	this->optionCount = optionCount;
}

std::string Question::getTitle()
{
	return this->title;
}

std::string Question::getItemAtIndex(int index)
{
	return *(this->answers+index);
}

int Question::getOptionCount()
{
	return this->optionCount;
}