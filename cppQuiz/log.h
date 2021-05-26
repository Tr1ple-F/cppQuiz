#pragma once

#include "precompile.h"

namespace cpp_quiz {

	namespace log {

		enum class Level {INFO = 0, WARNING, ERROR};

		void error(const std::string&);

		void warning(const std::string&);

		void info(const std::string&);

		void log(const Level&&, const std::string&);

	} // namespace log

} // namespace cpp_quiz
