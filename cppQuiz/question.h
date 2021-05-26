#pragma once

#include "precompile.h"

namespace cpp_quiz {

	class Question {
	public:
		Question(std::string, std::unique_ptr<std::vector<std::string>>, int, bool = true); // default constructor
		Question(const Question&); // copy constructor
		Question(Question&&) noexcept; // move constructor
		~Question(); // destructor
		Question& operator=(const Question&); // copy assignment
		Question& operator=(Question&&) noexcept; // move assignment
		const std::string& getTitle() const;
		const std::string& getItemAtIndex(int) const;
		const size_t getOptionCount() const;
		const bool isCorrect(int) const;
	private:
		std::string title;
		std::unique_ptr<std::vector<std::string>> answers;
		std::vector<int> order;
		int correctAnswer;
	};

} // namespace cpp_quiz
