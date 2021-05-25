#include "utils.h"

namespace cpp_quiz {

	namespace utils {

		std::vector<std::string>* split(std::string line, std::string delimiter) {
			std::vector<std::string>* out = new std::vector<std::string>;
			size_t pos = 0;
			std::string token;
			while ((pos = line.find(delimiter)) != std::string::npos) {
				token = line.substr(0, pos);
				out->push_back(token);
				line.erase(0, pos + delimiter.length());
			}
			out->push_back(line); // Add final string to the end
			return out;
		}

		bool startsWith(std::string content, std::string token) {
			if (content.rfind(token, 0) == 0) {
				return true;
			}
			else {
				return false;
			}
		}

	} // namespace utils

} // namespace cpp_quiz