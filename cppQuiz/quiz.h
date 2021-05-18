#ifndef CPPQUIZ_QUIZ_H
#define CPPQUIZ_QUIZ_H

#include "question.h"

namespace cpp_quiz {

	class Quiz {
	public:
		Quiz(std::string, std::vector<Question*>*);
		~Quiz();
		std::string getQuizTitle();
		Question* getQuestionAtIndex(int);
		int getQuestionCount();
	private:
		std::string quizTitle;
		std::vector<Question*>* questions;
	};

}

#endif