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
							log::warning("Line 1 contains more than two parameters. All parameters except for the title and question count will be ignored");
						}
						try {
							questionCount = std::stoi((*subsets)[0]);
							title = (*subsets)[1];

							if (questionCount < 1)
							{
								log::error("QUESTION_COUNT needs to be greater than 1. Actual: " + questionCount);
								return 0;
							}
						}
						catch (std::exception& e) { // Not a number
							log::error("The QUESTION_COUNT parameter in line 1 expected an positive integer. Actual: " + (*subsets)[0]);
							return 0;
						}
					}
				}
				else // No lines
				{
					log::warning("The file \"" + fileName + "\" is empty");
				}

				std::unique_ptr<std::vector<std::unique_ptr<Question>>> questions = std::make_unique<std::vector<std::unique_ptr<Question>>>(questionCount);
				int i = 0;

				while (std::getline(file, line)) 
				{
					if (i == questionCount) // More lines
					{
						std::string msg = "Line " + static_cast<size_t>(i) + 2;
						msg.append(" will be ignored");
						log::warning(msg);
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

				if (i < questionCount - 1) // Not all questions filled
				{
					std::string msg = "Expected " + questionCount;
					msg.append(" questions but got ");
					msg.append("" + static_cast<size_t>(i)+1);
					log::error(msg);
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
						std::string msg = "Question " + no;
						msg.append(": parameter <ANSWER_COUNT> expected a number greater than 1. Actual: " + options);
						msg.append((*subsets)[0]);
						log::error(msg);
						return 0;
					}

					std::unique_ptr<std::vector<std::string>> answers = std::make_unique<std::vector<std::string>>(options);
					int correctAnswer = 0;
					for (int i = 0; i < options; i++)
					{
						if (static_cast<size_t>(i)+2 >= subsets->size()) // Not enough answers
						{
							std::string msg = "Question " + no;
							msg.append(": missing answers. Expected: " + options);
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
						std::string msg = "Question ";
						msg.append(": more parameters than necessary. Expected " + options);
						msg.append(" parameters but received " + subsets->size());
						msg.append(". Additional parameters will be ignored.");
						log::warning(msg);
					}

					return std::make_unique<Question>((*subsets)[1], std::move(answers), correctAnswer);
				}
				catch (std::exception& e) { // Answer count not a number
					std::string msg = "Question " + no;
					msg.append(": parameter <ANSWER_COUNT> expected a positive number. Actual: ");
					msg.append((*subsets)[0]);
					log::error(msg);
					return 0;
				}
			}
			else {
				std::string msg = "Question " + no;
				msg.append(" doesn't have enough options");
				log::error(msg);
				log::info("Question lines should match the format: \"<ANSWER_COUNT>#<QUESTION_TITLE>#<ANSWER_1>#<ANSWER_2>#...#<ANSWER_n>\"");
				return 0;
			}
		}

	} // namespace file_parser

} // namespace cpp_quiz