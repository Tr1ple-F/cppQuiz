#pragma once

#include "precompile.h"

namespace cpp_quiz {
	
	namespace utils {
		
		std::unique_ptr<const std::vector<std::string>> split(const std::string&, const char&);

		bool startsWith(const std::string&, const std::string&);

	} // namespace utils

} // namespace cpp_quiz
