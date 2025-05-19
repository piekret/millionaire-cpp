#pragma once

#include "config.hpp"
#include <string>
#include <vector>

namespace millionaire {
	
	typedef std::string Answers[4];

	struct Question {
		std::string text;
		Answers answers;
		char correct;
		bool isCorrect(char a) const { return a == correct; };
	};

	typedef std::vector<Question> v_question;

}
