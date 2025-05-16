#include "lifelines.hpp"
#include <random>

void millionaire::fifty_fifty(Question& question)
{
	std::random_device seed;
	std::mt19937 gen(seed());
	std::vector<char> options;

	for (char i = 'A'; i <= 'D'; i++) {
		options.push_back(i);
	}

	std::uniform_int_distribution<> roll(1, options.size() - 1);
	char keep = options[roll(gen)];

	for (int i = 0; i < 4; i++) {
		char label = 'A' + i;

		if (label != question.correct && label != keep)
			question.answers[i].clear();
	}
}

char millionaire::ask_audience(const Question& question)
{
	std::random_device seed;
	std::mt19937 gen(seed());
	std::uniform_int_distribution<> roll(1, 100);

	int rng = roll(gen);

	if (rng <= 65)
		return question.correct;
	else {
		std::vector<char> wrong;

		for (char i = 'A'; i <= 'D'; i++) {
			if (i != question.correct)
				wrong.push_back(i);
		}

		std::uniform_int_distribution<> roll_wrong(0, wrong.size() - 1);
		return wrong[roll_wrong(gen)];
	}
}

char millionaire::phone_friend(const Question& question)
{
	return question.correct;
}