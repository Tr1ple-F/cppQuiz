#include "quiz.h"
#include "utils.h"
#include "log.h"

namespace cpp_quiz {

	namespace file_parser {
	
		Quiz* loadQuizFromFile(std::string fileName) {
			return 0;
		}

		Question parseQuestionFromLine(std::string line) {
			std::vector<std::string> subsets = *utils::split(line, "#");
			if (subsets.size() >= 4)
			{
				int options = std::stoi(subsets[0]);
				std::string title = subsets[1];
				std::vector<std::string> answers(options);
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
						answers[i] = option;
					}
				}
				delete& subsets;
				return Question(title, answers, correctAnswer);
			}
			else {
				log::error("Not enough options");
				delete& subsets;
				return 0;
			}
		}

	}

}