#pragma once

#include "quiz.h"
#include "utils.h"
#include "log.h"

namespace cpp_quiz {

	namespace file_parser {

		std::unique_ptr<Quiz> loadQuizFromFile(const std::string&);

		std::unique_ptr<Question> parseQuestionFromLine(const std::string&);

	} // namespace file_parser

} // namespace cpp_quiz
