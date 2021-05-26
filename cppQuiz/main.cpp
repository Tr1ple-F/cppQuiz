#include "file_parser.h"

int main() {
	std::string filePath;
	std::cout << "Please enter file path: ";
	std::cin >> filePath;
	cpp_quiz::Quiz* quiz = cpp_quiz::file_parser::loadQuizFromFile(filePath);
	if (quiz != 0) {
		int score = 0;
		std::cout << quiz->getQuizTitle() << "\n";
		for (int i = 0; i < quiz->getQuestionCount(); i++)
		{
			const cpp_quiz::Question* question = quiz->getQuestionAtIndex(i);
			int answer;
			std::cout << question->getTitle() << "\n";
			for (int j = 0; j < question->getOptionCount(); j++)
			{
				std::cout << j << ") " << question->getItemAtIndex(j) << "\n";
			}
			std::cout << "Your answer: ";
			std::cin >> answer;
			if (question->isCorrect(answer)) {
				score += 1;
				std::cout << "CORRECT\n";
			}
			else {
				std::cout << "FALSE\n";
			}
		}
		std::cout << "Your score: " << score;
		delete quiz;
	}
	return 0;
}