#include <iostream>
#include <clocale>
#include "utils.hpp"
#include "game.hpp"

using namespace millionaire;

int main(int argc, char** argv)
{
	std::setlocale(LC_ALL, "");

	try {
		CmdArgs args = parse_args(argc, argv);
		v_question questions = load_questions(args.questions_path);
		Game game(std::move(questions), args);

		game.run();
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
