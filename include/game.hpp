#pragma once

#include <vector>
#include "question.hpp"
#include "utils.hpp"

namespace millionaire {

	class Game {
	public:
		Game(v_question questions, const CmdArgs& args);
		void run();
	private:
		v_question questions;
		CmdArgs args;
		bool used50{ false }, used_audience{ false }, used_phone{ false };

		void show_scores(double reward);
	};

}