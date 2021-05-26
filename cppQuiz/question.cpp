#include "question.h"

namespace cpp_quiz {

	Question::Question(std::string title, std::unique_ptr<std::vector<std::string>> a, int correctAnswer, bool shufflingEnabled) : answers(std::move(a))
	{
		this->title = title;

		// Shuffle options array
		std::vector<int> order(this->answers->size());
		for (int i = 0; i < this->answers->size(); i++)
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
	}

	const std::string& Question::getTitle() const
	{
		return this->title;
	}

	const std::string& Question::getItemAtIndex(int index) const
	{
		return (*(this->answers))[order[index]];
	}

	const int Question::getOptionCount() const
	{
		return this->answers->size();
	}

	const bool Question::isCorrect(int answer) const
	{
		return order[answer] == this->correctAnswer;
	}

} // namespace cpp_quiz