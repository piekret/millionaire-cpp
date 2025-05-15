#pragma once

#include "config.hpp"
#include <string>

namespace millionaire {
	
	struct Question {
		std::string text;
		std::string answers[4];
		char correct;
		level level;
		bool isCorrect(char a) const;
	};

}
