#include "utils.hpp"  
#include <fstream>  
#include <sstream>
#include <iostream>

millionaire::Question millionaire::parse_csv_row(const std::string& row)  
{  
    std::vector<std::string> tokens;
    std::string field;
    std::stringstream ss;

    ss << row;
    while (std::getline(ss, field, ';'))
        tokens.push_back(field);

    if (tokens.size() != 6)
        throw std::runtime_error("invalid csv row: expected 6 fields, got " + std::to_string(tokens.size()));

    Question question;
    question.text = tokens[0];

    for (int i = 0; i < 4; i++)
        question.answers[i] = tokens[i + 1];

    const std::string corr = tokens[5];
    if (corr.size() != 1 || corr[0] < 'A' || corr[0] > 'D')
        throw std::runtime_error("invalid correct answer: expected A-D");

    question.correct = corr[0];
    return question;
}

millionaire::v_question millionaire::load_questions(const std::string& path)
{
    std::ifstream in(path);
    if (!in)
        throw std::runtime_error("Cannot open file");
        

    v_question out;
    std::string line;
    int level = 0;

    while (std::getline(in, line)) {
        if (line.empty()) continue;

        out.push_back(parse_csv_row(line));
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
    std::cout << "\x1B[31m" << s << "\x1B[0m" << "\n";
}

void millionaire::clear()
{
    std::cout << "\x1B[2J\x1B[H" << "\n";
}

void millionaire::print_banner()
{
    std::ifstream in(banner_file);
    if (!in)
        return;

    std::string line;
    while (std::getline(in, line))
        std::cout << line << "\n";
}

millionaire::CmdArgs millionaire::parse_args(int argc, char** argv)
{
    CmdArgs args;
    args.shuffle = true;
    args.nick = "player";
    args.help = false;

    for (int i = 1; i < argc; i++) {
        std::string a = argv[i];

        if (a == "-help")
            args.help = true;
        else if (a.find("-questions=") == 0)
            args.questions_path = a.substr(11);
        else if (a == "-shuffle=false")
            args.shuffle = false;
        else if (a.find("-nick=") == 0)
            args.nick = a.substr(6);
    }

    if (args.questions_path.empty())
        args.questions_path = default_questions;

    return args;
}

millionaire::v_score millionaire::load_scores(const std::string& path)
{
    std::ifstream in(path);

    if (!in) {
        std::ofstream out(path);
        return {};
    }

    v_score out;
    std::string line;

    while (std::getline(in, line)) {
        if (line.empty())
            continue;

        std::stringstream ss;
        ss << line;

        Score s;
        std::string amt;

        std::getline(ss, s.nick, ';');
        std::getline(ss, amt, ';');

        try {
            s.cash = std::stod(amt);
        }
        catch (...) {
            s.cash = 0.0;
        }
    }

    return out;
}

void millionaire::save_scores(const v_score& scores, const std::string& path)
{
    std::ofstream out(path);

    for (auto& s : scores)
        out << s.nick << ";" << s.cash << "\n";
}

void millionaire::sort_scores(v_score& scores)
{
    bool swapped;
    size_t n = scores.size();

    do {
        swapped = false;
        
        for (int i = 1; i < n; i++) {
            if (scores[i - 1].cash < scores[i].cash) {
                std::swap(scores[i - 1], scores[i]);
                swapped = true;
            }
        }

        n--;
    } while (swapped);
}