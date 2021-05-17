#include "quiz.h"
#include "utils.h"

namespace cpp_quiz {

	namespace file_parser {
	
		Quiz* loadQuizFromFile(std::string fileName) {
			return 0;
		}

		Question* parseQuestionFromLine(std::string line) {
			std::vector<std::string> subsets = *utils::split(line, "#");
			return 0;
		}

	}

}