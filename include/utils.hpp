#pragma once

#include <vector>
#include <string>
#include "question.hpp"

namespace millionaire {

	struct CmdArgs {
		std::string questions_path;
		bool shuffle;
		std::string nick;
	};

	Question parse_csv_row(const std::string& row, level level);
	std::vector<Question> load_questions(const std::string& path);

	void print_green(const std::string& s);
	void print_red(const std::string& s);
	CmdArgs parse_args(int argc, char** argv);


}	