#pragma once

#include <array>
#include <string>

#define ASSETS_DIR "../../../../assets/"
#define NUM_OF_QUESTIONS 15

namespace millionaire {

    inline constexpr std::size_t num_of_questions = NUM_OF_QUESTIONS;

    inline constexpr double rewards[num_of_questions] = {
        100, 200, 300, 500, 1000,
        2000, 4000, 8000, 16000, 32000,
        64000, 125000, 250000, 500000, 1000000
    };

    inline const std::string default_questions{ ASSETS_DIR "default_questions.csv" };
    inline const std::string banner_file{ ASSETS_DIR "logo.txt" };
    inline const std::string last_round_file{ ASSETS_DIR "last.csv" };
    inline const std::string scores_file{ ASSETS_DIR "scores.csv" };

}