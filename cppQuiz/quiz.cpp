#include "quiz.h"

namespace cpp_quiz {

	Quiz::Quiz(std::string quizTitle, std::vector<Question*>* questions)
	{
		this->quizTitle = quizTitle;
		this->questions = questions;
	}

	Quiz::~Quiz() 
	{
		for (int i = 0; i < questions->size(); i++)
		{
			delete (*questions)[i];
		};
		delete questions;
	}

	std::string Quiz::getQuizTitle()
	{
		return this->quizTitle;
	}

	Question* Quiz::getQuestionAtIndex(int index)
	{
		return (*(this->questions))[index];
	}

	int Quiz::getQuestionCount()
	{
		return this->questions->size();
	}

}