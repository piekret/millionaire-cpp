#pragma once

#include <vector>
#include "question.hpp"
#include "utils.hpp"

namespace millionaire {

	class Game {
	public:
		Game(std::vector<Question> questions, const CmdArgs& args);
		void run();
	private:
		std::vector<Question> questions;
		CmdArgs args;
	};

}