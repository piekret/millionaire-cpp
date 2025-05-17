#pragma once

#include <vector>
#include <string>
#include "question.hpp"

namespace millionaire {

	struct CmdArgs {
		std::string questions_path;
		bool shuffle;
		std::string nick;
		bool help;
	};

	struct Score {
		std::string nick;
		double cash;
	};

	typedef std::vector<Score> v_score;

	Question parse_csv_row(const std::string& row);
	v_question load_questions(const std::string& path);

	void print_green(const std::string& s);
	void print_red(const std::string& s);
	void clear();
	void print_banner();

	CmdArgs parse_args(int argc, char** argv);

	v_score load_scores(const std::string& path);
	void save_scores(const v_score& scores, const std::string& path);
	void sort_scores(v_score& scores);

}	