#pragma once

#include "quiz.h"
#include "utils.h"
#include "log.h"

namespace cpp_quiz {

	namespace file_parser {

		Quiz* loadQuizFromFile(std::string);

		Question* parseQuestionFromLine(std::string);

	} // namespace file_parser

} // namespace cpp_quiz
