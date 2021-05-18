#include "quiz.h"
#include "utils.h"
#include "log.h"

namespace cpp_quiz {

	namespace file_parser {
	
		Quiz* loadQuizFromFile(std::string fileName) {
			std::ifstream file(fileName);
			if (file.is_open()) 
			{
				std::string line;
				int questionCount;
				std::string title;
				if (std::getline(file, line))
				{
					std::vector<std::string> subsets = *utils::split(line, "#");
					if (subsets.size() != 2) {
						log::error("First line doesn't match format QUESTIONS_COUNT#QUIZ_TITLE");
						delete& subsets;
						return 0;
					}
					else {
						questionCount = std::stoi(subsets[0]);
						title = subsets[1];
						delete& subsets;
					}
				}
				std::vector<Question*>* questions = new std::vector<Question*>(questionCount);
				while (std::getline(file, line)) 
				{
					Question* q = parseQuestionFromLine(line);
					if (q != 0) {
						questions->push_back(q);
					}
					else 
					{
						delete questions;
						return 0;
					}
				}
				Quiz* quiz = new Quiz(title, questions);
				return quiz;
			}
			else 
			{
				log::error("Unable to open file");
				return 0;
			}
		}

		Question* parseQuestionFromLine(std::string line) {
			std::vector<std::string> subsets = *utils::split(line, "#");
			if (subsets.size() >= 4)
			{
				int options = std::stoi(subsets[0]);
				std::string title = subsets[1];
				std::vector<std::string>* answers = new std::vector<std::string>(options);
				int correctAnswer = 0;
				for (int i = 0; i < options; i++)
				{
					if (i >= subsets.size())
					{
						log::error("Missing answer");
						delete& subsets;
						return 0;
					}
					else
					{
						std::string option = subsets[i];
						if (utils::startsWith(option, "*")) {
							correctAnswer = i;
							option.erase(0, 1);
						}
						(*answers)[i] = option;
					}
				}
				delete& subsets;
				Question* q = new Question(title, answers, correctAnswer);
				return q;
			}
			else {
				log::error("Not enough options");
				delete& subsets;
				return 0;
			}
		}

	}

}