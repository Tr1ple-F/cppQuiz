#pragma once

#include "quiz.h"
#include "utils.h"
#include "log.h"

namespace cpp_quiz {

	namespace file_parser {

		Quiz* loadQuizFromFile(const std::string&);

		Question* parseQuestionFromLine(const std::string&);

	} // namespace file_parser

} // namespace cpp_quiz
