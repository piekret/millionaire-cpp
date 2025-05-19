#pragma once

#include "config.hpp"
#include <string>
#include <vector>

namespace millionaire {
	
	typedef std::string answers[4];

	struct Question {
		std::string text;
		answers answers;
		char correct;
		bool isCorrect(char a) const { return a == correct; };
	};

	typedef std::vector<Question> v_question;

}
