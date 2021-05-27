#include "file_parser.h"

int main() {
	std::string filePath;
	std::cout << "Please enter file path: ";
	std::cin >> filePath;
	std::unique_ptr<const cpp_quiz::Quiz> quiz = cpp_quiz::file_parser::loadQuizFromFile(filePath);
	if (quiz != 0) {
		int score = 0;
		std::cout << quiz->getQuizTitle() << "\n";
		for (int i = 0; i < quiz->getQuestionCount(); i++)
		{
			const cpp_quiz::Question question = quiz->getQuestionAtIndex(i);
			std::string input;
			std::cout << question.getTitle() << "\n";
			for (int j = 0; j < question.getOptionCount(); j++)
			{
				std::cout << j << ") " << question.getItemAtIndex(j) << "\n";
			}
			int answer = -1;

			// Check whether answer is integer
			while (answer == -1)
			{
				std::cout << "Your answer (number between 0 and " << question.getOptionCount()-1 << "): ";
				std::cin >> input;
				try {
					answer = std::stoi(input);

					if (answer < 0 || answer >= question.getOptionCount())
					{
						std::cout << "Your answer need to be between 0 and " << question.getOptionCount() - 1 << ". Please try again.\n";
						answer = -1;
					}
				}
				catch (std::exception& e) { // Not a number
					std::cout << "Your answer need to be a number between 0 and " << question.getOptionCount() - 1 << ". Please try again.\n";
					answer = -1;
				}
			}

			if (question.isCorrect(answer)) {
				score += 1;
				std::cout << "CORRECT\n";
			}
			else {
				std::cout << "FALSE\n";
			}
		}
		std::cout << "Your score: " << score;
	}
	return 0;
}