#include "file_parser.h"

namespace cpp_quiz {

	namespace file_parser {
	
		std::unique_ptr<Quiz> loadQuizFromFile(const std::string& fileName) {
			std::ifstream file(fileName);
			if (file.is_open()) 
			{
				std::string line;
				int questionCount = 0;
				std::string title;
				if (std::getline(file, line))
				{
					std::unique_ptr<const std::vector<std::string>> subsets = utils::split(line, '#');
					if (subsets->size() != 2) {
						log::error("First line doesn't match format QUESTIONS_COUNT#QUIZ_TITLE");
						return 0;
					}
					else {
						questionCount = std::stoi((*subsets)[0]);
						title = (*subsets)[1];
					}
				}
				std::unique_ptr<std::vector<std::unique_ptr<Question>>> questions = std::make_unique<std::vector<std::unique_ptr<Question>>>(questionCount);
				int i = 0;
				while (std::getline(file, line)) 
				{
					std::unique_ptr<Question> q = parseQuestionFromLine(line);
					if (q != 0) {
						(*questions)[i] = std::move(q);
					}
					else 
					{
						return 0;
					}
					i += 1;
				}
				return std::make_unique<Quiz>(title, std::move(questions));
			}
			else 
			{
				log::error("Unable to open file");
				return 0;
			}
		}

		std::unique_ptr<Question> parseQuestionFromLine(const std::string& line) {
			std::unique_ptr<const std::vector<std::string>> subsets = utils::split(line, '#');
			if (subsets->size() >= 4)
			{
				int options = std::stoi((*subsets)[0]);
				std::unique_ptr<std::vector<std::string>> answers = std::make_unique<std::vector<std::string>>(options);
				int correctAnswer = 0;
				for (int i = 0; i < options; i++)
				{
					if (i >= subsets->size())
					{
						log::error("Missing answer");
						return 0;
					}
					else
					{
						int j = i + 2;
						std::string option = (*subsets)[j];
						if (utils::startsWith(option, "*")) {
							correctAnswer = i;
							option.erase(0, 1);
						}
						(*answers)[i] = option;
					}
				}
				return std::make_unique<Question>((*subsets)[1], std::move(answers), correctAnswer);
			}
			else {
				log::error("Not enough options");
				return 0;
			}
		}

	} // namespace file_parser

} // namespace cpp_quiz