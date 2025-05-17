#include "game.hpp"
#include "config.hpp"
#include "lifelines.hpp"
#include <random>
#include <algorithm>
#include <iostream>

millionaire::Game::Game(v_question questions, const CmdArgs& args) 
	: questions(questions), args(args)
{
	if (args.shuffle) {
		std::random_device seed;
		std::mt19937 gen(seed());
		std::shuffle(questions.begin(), questions.end(), gen);
	}
}

void millionaire::Game::show_scores(double reward)
{
	v_score scores = load_scores(args.questions_path + ".scores");
	scores.push_back({ args.nick, reward });

	sort_scores(scores);

	if (scores.size() > 10)
		scores.resize(10);

	save_scores(scores, args.questions_path + ".scores");

	std::cout << "\nHigh Scores:" << "\n";
	for (int i = 0; i < scores.size(); ++i)
		std::cout << (i + 1) << ". " << scores[i].nick << " - $" << scores[i].cash << "\n";
}

void millionaire::Game::run()
{
	print_banner();
	std::cout << "Commands: A-D answer, H=50/50, U=Audience, P=Phone, Q=Exit\n\n";

	int level = 0;

	while (level < num_of_questions) {
		const Question& question = questions[level];

		std::cout << "Question " << (level + 1) << " for $" << rewards[level] << ":\n";
		std::cout << question.text << "\n";

		for (int i = 0; i < 4; i++) {
			char label = 'A' + i;
			std::string ans = question.answers[i].empty() ? "---" : question.answers[i];

			std::cout << label << ") " << ans << "  ";
		}
		std::cout << "\n";

		char choice;
		std::cin >> choice;
		choice = static_cast<char>(std::toupper(choice));

		switch (choice) {
		case 'H':
			if (!used50) {
				fifty_fifty(const_cast<Question&>(question)); // prosze przymkn¹æ oko ;(
				used50 = true;
				continue;
			} 
			std::cout << "50/50 already used!" << std::endl;
			continue;

		case 'U':
			if (!used_audience) {
				std::cout << "Audience says: " << ask_audience(question) << std::endl;
				used_audience = true;
				continue;
			}
			std::cout << "Audience already used!" << std::endl;
			continue;

		case 'P':
			if (!used_phone) {
				std::cout << "Friend says: " << phone_friend(question) << std::endl;
				used_phone = true;
				continue;
			}
			std::cout << "Phone already used!" << std::endl;
			continue;

		case 'Q':
			double reward = level > 0 ? rewards[level - 1] : 0.0;
			std::cout << "You quit with $" << reward << std::endl;
			show_scores(reward);
			break;

		case 'A': case 'B': case 'C': case 'D':
			if (!question.isCorrect(choice)) {
				print_red("Wrong!");
				std::cout << "Correct was: " << question.correct << std::endl;

				double reward = level > 0 ? rewards[level - 1] : 0.0;
				show_scores(reward);
				break;
			}

			print_green("Correct!");
			level++;
			continue;

		default:
			std::cout << "Invalid input, please try again: " << std::endl;
			continue;
		}


	}

	std::cout << "CONGRATS! You won $" << rewards[num_of_questions] << "\n";
}