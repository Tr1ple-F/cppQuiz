#pragma once

#include "question.h"

namespace cpp_quiz {

	class Quiz {
	public:
		Quiz(std::string, std::vector<Question*>*);
		~Quiz();
		const std::string& getQuizTitle() const;
		const Question* getQuestionAtIndex(int) const;
		const int getQuestionCount() const;
	private:
		std::string quizTitle;
		std::vector<Question*>* questions;
	};

} // namespace cpp_quiz
