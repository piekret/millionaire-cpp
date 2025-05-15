#include "utils.hpp"  
#include <fstream>  
#include <sstream>
#include <iostream>

millionaire::Question millionaire::parse_csv_row(const std::string& row, level level)  
{  
    std::stringstream ss;
    ss << row;

    Question question;
    question.level = level;

    for (int i = 0; i < 4; i++)
        std::getline(ss, question.answers[i], ';');

    std::string letter;
    std::getline(ss, letter, ';');

    question.correct = letter.empty() ? 'A' : letter[0];

    return question;
}

std::vector<millionaire::Question> millionaire::load_questions(const std::string& path)
{
    std::ifstream in(path);
    if (!in) 
        throw std::runtime_error("Cannot open file");

    std::vector<Question> out;
    std::string line;
    int level = 0;

    while (std::getline(in, line)) {
        if (line.empty()) continue;

        out.push_back(parse_csv_row(line, level));
        level++;
    }

    return out;
}

void millionaire::print_green(const std::string& s)
{
    std::cout << "\x1B[32m" << s << "\x1B[0m" << "\n";
}

void millionaire::print_red(const std::string& s)
{
    std::cout << "\x1B[32m" << s << "\x1B[0m" << "\n";
}

millionaire::CmdArgs millionaire::parse_args(int argc, char** argv)
{
    CmdArgs args;
    args.shuffle = false;
    args.nick = "player";

    for (int i = 1; i < argc; i++) {
        std::string a = argv[i];

        if (a.find("-questions=") == 0)
            args.questions_path = a.substr(11);
        else if (a == "-shuffle")
            args.shuffle = true;
        else if (a.find("-nick=") == 0)
            args.nick = a.substr(6);
    }

    if (args.questions_path.empty())
        args.questions_path = default_questions;

    return args;
}