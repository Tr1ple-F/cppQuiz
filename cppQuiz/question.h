#ifndef CPPQUIZ_QUESTION_H
#define CPPQUIZ_QUESTION_H

#include "precompile.h"

namespace cpp_quiz {

	class Question {
	public:
		Question(std::string, std::vector<std::string>, int, bool = false);
		std::string getTitle();
		std::string getItemAtIndex(int);
		int getOptionCount();
		bool isCorrect(int);
	private:
		std::string title;
		std::vector<std::string> answers;
		std::vector<int> order;
		int correctAnswer;
	};

}

#endif