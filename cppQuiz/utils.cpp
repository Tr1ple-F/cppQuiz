#include "utils.h"

namespace cpp_quiz {

	namespace utils {
		
		std::unique_ptr<const std::vector<std::string>> split(const std::string& line, const char& delimiter) {
			std::unique_ptr<std::vector<std::string>> out = std::make_unique<std::vector<std::string>>();
			size_t pos = 0;
			std::string token;
			std::stringstream s_stream(line);
			while (s_stream.good()) {
				std::string substr;
				std::getline(s_stream, substr, delimiter);
				out->push_back(substr);
			}
			return out;
		}

		const bool startsWith(const std::string& content, const std::string& token) {
			if (content.rfind(token, 0) == 0) {
				return true;
			}
			else {
				return false;
			}
		}

	} // namespace utils

} // namespace cpp_quiz