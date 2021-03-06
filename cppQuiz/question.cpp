#include "question.h"

namespace cpp_quiz {

	Question::Question(std::string title, std::unique_ptr<std::vector<std::string>> a, int correctAnswer, bool shufflingEnabled) : answers(std::move(a)), title(title), correctAnswer(correctAnswer) // default constructor
	{

		// Shuffle options array
		this->order = std::make_unique<std::vector<int>>(this->answers->size());
		for (int i = 0; i < this->answers->size(); i++)
		{
			(*(this->order))[i] = i;
		}

		if (shufflingEnabled) {
			unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
			shuffle(order->begin(), order->end(), std::default_random_engine(seed));
		}
	}

	Question::Question(const Question& other) : title(other.title), correctAnswer(other.correctAnswer) // copy constructor
	{
		this->order = std::make_unique<std::vector<int>>(*(other.order));
		this->answers = std::make_unique<std::vector<std::string>>(*(other.answers));
	}
	
	Question::Question(Question&& other) noexcept : title(other.title), correctAnswer(other.correctAnswer) // move constructor
	{
		this->order = std::move(other.order);
		this->answers = std::move(other.answers);
	}

	Question::~Question() {} // destructor

	Question& Question::operator=(const Question& other) // copy assignment
	{
		if (this != &other) 
		{
			this->title = other.title;
			this->correctAnswer = other.correctAnswer;
			this->order = std::make_unique<std::vector<int>>(*(other.order));
			this->answers = std::make_unique<std::vector<std::string>>(*(other.answers));
		}
		return *this;
	}

	Question& Question::operator=(Question&& other) noexcept // move assignment
	{
		if (this != &other)
		{
			this->title = other.title;
			this->correctAnswer = other.correctAnswer;
			this->order = std::move(other.order);
			this->answers = std::move(other.answers);
		}
		return *this;
	}

	const std::string& Question::getTitle() const
	{
		return this->title;
	}

	const std::string& Question::getItemAtIndex(int index) const
	{
		return (*(this->answers))[(*(this->order))[index]];
	}

	const size_t Question::getOptionCount() const
	{
		return this->answers->size();
	}

	const bool Question::isCorrect(int answer) const
	{
		return (*(this->order))[answer] == this->correctAnswer;
	}

} // namespace cpp_quiz