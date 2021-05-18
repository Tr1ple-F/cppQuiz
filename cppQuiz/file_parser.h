#ifndef CPPQUIZ_FILE_PARSER_H
#define CPPQUIZ_FILE_PARSER_H

#include "quiz.h"
#include "utils.h"
#include "log.h"

namespace cpp_quiz {

	namespace file_parser {

		Quiz* loadQuizFromFile(std::string);

		Question* parseQuestionFromLine(std::string);

	}

}

#endif
