#pragma once

#include "question.h"

namespace cpp_quiz {

	class Quiz {
	public:
		Quiz(std::string, std::unique_ptr<std::vector<std::unique_ptr<Question>>>); // default constructor
		Quiz(const Quiz&); // copy constructor
		Quiz(Quiz&&) noexcept; // move constructor
		~Quiz(); // destructor
		Quiz& operator=(const Quiz&); // copy assignment
		Quiz& operator=(Quiz&&) noexcept; // move assignment
		const std::string& getQuizTitle() const;
		const Question& getQuestionAtIndex(int) const;
		const size_t getQuestionCount() const;
	private:
		std::string quizTitle;
		std::unique_ptr<std::vector<std::unique_ptr<Question>>> questions;
	};

} // namespace cpp_quiz
