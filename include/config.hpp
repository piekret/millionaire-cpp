#pragma once

#include <vector>
#include <array>
#include <string>

namespace millionaire {

	const short num_of_questions = 15;

	const double rewards[num_of_questions] = {
		500,1000,2000,5000,10000,20000,40000,75000,125000,
		250000,500000,1000000,2000000,5000000,10000000
	};

	const std::string default_questions = "assets/default_questions.csv";
	const std::string banner_file = "assets/logo.txt";

}