#include "log.h"

namespace cpp_quiz {

	namespace log {

		void error(const std::string& msg) {
			std::cout << "ERROR OCCURED: " << msg;
		}

	} // namespace log

} // namespace cpp_quiz