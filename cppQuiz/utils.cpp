#include "utils.h"

namespace cpp_quiz {

	namespace utils {

		std::vector<std::string>* split(std::string line, std::string delimiter) {
			std::vector<std::string> out;
			size_t pos = 0;
			std::string token;
			while ((pos = line.find(delimiter)) != std::string::npos) {
				token = line.substr(0, pos);
				out.push_back(token);
				line.erase(0, pos + delimiter.length());
			}
			return &out;
		}

	}

}