#pragma once

#include "config.hpp"
#include <string>

namespace millionaire {
	
	struct Question {
		std::string text;
		std::string answers[4];
		char correct;
		bool isCorrect(char a) const { return a == correct; };
	};

}
