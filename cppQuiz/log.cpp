#include "log.h"

namespace cpp_quiz {

	namespace log {

		void error(const std::string& msg) {
			std::cout << "ERROR: " << msg << std::endl;
		}

		void warning(const std::string& msg) {
			std::cout << "WARNING: " << msg << std::endl;
		}

		void info(const std::string& msg) {
			std::cout << "INFO: " << msg << std::endl;
		}

		void log(const Level&& level, const std::string& msg) {
			switch (level)
			{
			case Level::INFO:
				info(msg);
				break;
			case Level::WARNING:
				warning(msg);
				break;
			default:
				error(msg);
				break;
			}
		}

	} // namespace log

} // namespace cpp_quiz