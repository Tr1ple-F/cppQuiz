#include "question.h"

namespace cpp_quiz {

	Question::Question(std::string title, std::string* answers, int optionCount, int correctAnswer, bool shufflingEnabled)
	{
		this->title = title;
		this->answers = answers;
		this->optionCount = optionCount;

		// Shuffle options array
		std::vector<int> order(optionCount);
		for (size_t i = 0; i < optionCount; i++)
		{
			order.push_back(i);
		}

		if (shufflingEnabled) {
			unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
			shuffle(order.begin(), order.end(), std::default_random_engine(seed));
		}

		this->order = order;
	}

	std::string Question::getTitle()
	{
		return this->title;
	}

	std::string Question::getItemAtIndex(int index)
	{
		return *(this->answers + order[index]);
	}

	int Question::getOptionCount()
	{
		return this->optionCount;
	}

	bool Question::isCorrect(int answer)
	{
		return order[answer] == this->correctAnswer;
	}

}