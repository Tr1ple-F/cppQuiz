#ifndef CPPQUIZ_QUIZ_H
#define CPPQUIZ_QUIZ_H

#include "question.h"

namespace cpp_quiz {

	class Quiz {
	public:
		Quiz(std::string, Question*, int);
		std::string getQuizTitle();
		Question getQuestionAtIndex(int);
		int getQuestionCount();
	private:
		std::string quizTitle;
		Question* questions;
		int questionCount;
	};

}

#endif