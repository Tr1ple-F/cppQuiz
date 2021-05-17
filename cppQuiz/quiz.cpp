#include "quiz.h"

namespace cpp_quiz {

	Quiz::Quiz(std::string quizTitle, Question* questions, int questionCount)
	{
		this->quizTitle = quizTitle;
		this->questions = questions;
		this->questionCount = questionCount;
	}

	std::string Quiz::getQuizTitle()
	{
		return this->quizTitle;
	}

	Question Quiz::getQuestionAtIndex(int index)
	{
		return *(this->questions + index);
	}

	int Quiz::getQuestionCount()
	{
		return this->questionCount;
	}

}