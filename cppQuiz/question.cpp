#include "question.h"

namespace cpp_quiz {

	Question::Question(std::string title, std::vector<std::string>* answers, int correctAnswer, bool shufflingEnabled)
	{
		this->title = title;
		this->answers = answers;

		// Shuffle options array
		std::vector<int> order(answers->size());
		for (int i = 0; i < answers->size(); i++)
		{
			order[i] = i;
		}

		if (shufflingEnabled) {
			unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
			shuffle(order.begin(), order.end(), std::default_random_engine(seed));
		}

		this->correctAnswer = correctAnswer;
		this->order = order;
	}

	Question::~Question()
	{
		delete answers;
	}

	std::string Question::getTitle()
	{
		return this->title;
	}

	std::string Question::getItemAtIndex(int index)
	{
		return (*(this->answers))[order[index]];
	}

	int Question::getOptionCount()
	{
		return this->answers->size();
	}

	bool Question::isCorrect(int answer)
	{
		return order[answer] == this->correctAnswer;
	}

}