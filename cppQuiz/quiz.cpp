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

	const std::string& Quiz::getQuizTitle() const
	{
		return this->quizTitle;
	}

	const Question* Quiz::getQuestionAtIndex(int index) const
	{
		return (*(this->questions))[index];
	}

	const int Quiz::getQuestionCount() const
	{
		return this->questions->size();
	}

} // namespace cpp_quiz