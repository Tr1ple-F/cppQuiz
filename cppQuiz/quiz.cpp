#include "quiz.h"

namespace cpp_quiz {

	Quiz::Quiz(std::string quizTitle, std::vector<Question> questions)
	{
		this->quizTitle = quizTitle;
		this->questions = questions;
	}

	std::string Quiz::getQuizTitle()
	{
		return this->quizTitle;
	}

	Question Quiz::getQuestionAtIndex(int index)
	{
		return this->questions[index];
	}

	int Quiz::getQuestionCount()
	{
		return this->questions.size();
	}

}