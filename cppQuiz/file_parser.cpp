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

				if (std::getline(file, line)) // First line available
				{
					std::unique_ptr<const std::vector<std::string>> subsets = utils::split(line, '#');

					if (subsets->size() < 2)  // Not enough #
					{
						log::error("Line 1 doesn't define all required parameters");
						log::info("Line 1 should match the format: \"<QUESTION_COUNT>#<QUIZ_TITLE>\"");
						return 0;
					}
					else 
					{
						if (subsets->size() > 2) // Too many #
						{
							log::warning("Line 1 contains more than two parameters. All parameters except for the title and question count will be ignored.");
						}
						try {
							questionCount = std::stoi((*subsets)[0]);
							title = (*subsets)[1];

							if (questionCount < 1)
							{
								std::string msg = std::string("<QUESTION_COUNT> needs to be greater than 1. Actual: ") + std::to_string(questionCount);
								log::error(msg);
								return 0;
							}
						}
						catch (std::exception& e) { // Not a number
							log::error("The <QUESTION_COUNT> parameter in line 1 expected an positive integer. Actual: " + (*subsets)[0]);
							return 0;
						}
					}
				}
				else // No lines
				{
					log::error("The file \"" + fileName + "\" is empty");
					return 0;
				}

				std::unique_ptr<std::vector<std::unique_ptr<Question>>> questions = std::make_unique<std::vector<std::unique_ptr<Question>>>(questionCount);
				int i = 0;

				while (std::getline(file, line)) 
				{
					if (i >= questionCount) // More lines
					{
						std::string msg = "Line " + std::to_string(static_cast<size_t>(i) + 2);
						msg.append(" will be ignored");
						log::warning(msg);
						i += 1;
						continue;
					}

					std::unique_ptr<Question> q = parseQuestionFromLine(line, i+1);

					if (q != 0) {
						(*questions)[i] = std::move(q);
					}
					else 
					{
						return 0;
					}

					i += 1;
				}

				if (i < questionCount) // Not all questions filled
				{
					std::string msg = "Expected " + std::to_string(questionCount);
					msg.append(" questions but only got ");
					msg.append(std::to_string(static_cast<size_t>(i)));
					log::error(msg);
					return 0;
				}

				return std::make_unique<Quiz>(title, std::move(questions));
			}
			else 
			{
				log::error("Unable to open file \"" + fileName + "\"");
				return 0;
			}
		}

		std::unique_ptr<Question> parseQuestionFromLine(const std::string& line, int no) {
			std::unique_ptr<const std::vector<std::string>> subsets = utils::split(line, '#');
			if (subsets->size() >= 4)
			{
				try {
					int options = std::stoi((*subsets)[0]);

					if (options < 2) // Expected at least two answers
					{
						std::string msg = std::string("Question ");
						msg.append(std::to_string(no));
						msg.append(": parameter <ANSWER_COUNT> expected a number greater than 1. Actual: ");
						msg.append((*subsets)[0]);
						log::error(msg);
						return 0;
					}

					std::unique_ptr<std::vector<std::string>> answers = std::make_unique<std::vector<std::string>>(options);
					int correctAnswer = 0;
					for (int i = 0; i < options; i++)
					{
						if (static_cast<size_t>(i) >= subsets->size()-2) // Not enough answers
						{
							std::string msg = std::string("Question ");
							msg.append(std::to_string(no));
							msg.append(": missing answers. Expected ");
							msg.append(std::to_string(options));
							msg.append(" but only got ");
							msg.append(std::to_string(subsets->size()-2));
							log::error(msg);
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

					if (subsets->size() > 2 + static_cast<size_t>(options)) // More answers than expected
					{
						std::string msg = std::string("Question ");
						msg.append(std::to_string(no));
						msg.append(": more answers than necessary. Expected ");
						msg.append(std::to_string(options));
						msg.append(" but received ");
						msg.append(std::to_string(subsets->size() - 2));
						msg.append(". Additional parameters will be ignored.");
						log::warning(msg);
					}

					return std::make_unique<Question>((*subsets)[1], std::move(answers), correctAnswer);
				}
				catch (std::exception& e) { // Answer count not a number
					std::string msg = std::string("Question ");
					msg.append(std::to_string(no));
					msg.append(": parameter <ANSWER_COUNT> expected a positive number. Actual: ");
					msg.append((*subsets)[0]);
					log::error(msg);
					return 0;
				}
			}
			else {
				std::string msg = std::string("Question ");
				msg.append(std::to_string(no));
				msg.append(" doesn't have enough options");
				log::error(msg);
				log::info("Question lines should match the format: \"<ANSWER_COUNT>#<QUESTION_TITLE>#<ANSWER_1>#<ANSWER_2>#...#<ANSWER_n>\"");
				return 0;
			}
		}

	} // namespace file_parser

} // namespace cpp_quiz