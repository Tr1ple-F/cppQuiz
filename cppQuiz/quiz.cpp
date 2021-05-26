#include "quiz.h"

namespace cpp_quiz {

	Quiz::Quiz(std::string quizTitle, std::unique_ptr<std::vector<std::unique_ptr<Question>>> questions) : quizTitle(quizTitle), questions(std::move(questions)) {} // default constructor

	Quiz::Quiz(const Quiz& other) : quizTitle(other.quizTitle) // copy constructor
	{
		this->questions = std::make_unique<std::vector<std::unique_ptr<Question>>>(other.getQuestionCount());
		for (size_t i = 0; i < other.getQuestionCount(); i++)
		{
			(*questions)[i] = std::make_unique<Question>(other.getQuestionAtIndex(i));
		}
	}

	Quiz::Quiz(Quiz&& other) noexcept : quizTitle(other.quizTitle) // move constructor
	{
		this->questions = std::move(other.questions);
	}

	Quiz::~Quiz() {}

	Quiz& Quiz::operator=(const Quiz& other) // copy assignment
	{
		if (this != &other)
		{
			this->quizTitle = other.quizTitle;
			this->questions = std::make_unique<std::vector<std::unique_ptr<Question>>>(other.getQuestionCount());
			for (size_t i = 0; i < other.getQuestionCount(); i++)
			{
				(*questions)[i] = std::make_unique<Question>(other.getQuestionAtIndex(i));
			}
		}
		return *this;
	}

	Quiz& Quiz::operator=(Quiz&& other) noexcept // move assignment
	{
		if (this != &other)
		{
			this->quizTitle = other.quizTitle;
			this->questions = std::move(other.questions);
		}
		return *this;
	}

	const std::string& Quiz::getQuizTitle() const
	{
		return this->quizTitle;
	}

	const Question& Quiz::getQuestionAtIndex(int index) const
	{
		return *(*(this->questions))[index];
	}

	const size_t Quiz::getQuestionCount() const
	{
		return this->questions->size();
	}

} // namespace cpp_quiz