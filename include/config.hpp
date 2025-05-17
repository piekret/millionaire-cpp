#pragma once

#include <vector>
#include <array>
#include <string>

namespace millionaire {

	const short num_of_questions = 15;

	const double rewards[num_of_questions] = {
		100, 200, 300, 500, 1000, 2000, 4000, 8000, 16000,
		32000, 64000, 125000, 250000, 500000, 10000000
	};

	const std::string default_questions = "../../../../assets/default_questions.csv";
	const std::string banner_file = "../../../../assets/logo.txt";

}