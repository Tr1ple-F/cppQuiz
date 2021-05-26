#pragma once

#include "precompile.h"

namespace cpp_quiz {

	class Question {
	public:
		Question(std::string, std::vector<std::string>*, int, bool = true); // standard constructor
		~Question(); // destructor
		const std::string& getTitle() const;
		const std::string& getItemAtIndex(int) const;
		const int getOptionCount() const;
		const bool isCorrect(int) const;
	private:
		std::string title;
		std::vector<std::string>* answers;
		std::vector<int> order;
		int correctAnswer;
	};

} // namespace cpp_quiz
