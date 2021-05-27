# cppQuiz
A C++ quiz project.

## Quiz Structure

### First line
Every quiz file must start with a defining line.

Parameter | Explanation
--------- | -----------
`<QUESTION_COUNT>` | The number of question in the quiz. The programm will expect this many further lines in the file.
`<QUIZ_TITLE>` | The quiz title.

The first line should be formatted like this:

``` 
<QUESTION_COUNT>#<QUIZ_TITLE>
```

### Question lines
Every other line is read as a question line any must contain the following parameters:

Parameter | Explanation
--------- | -----------
`<ANSWER_COUNT>` | The number of answers to this specific question.
`<QUESTION_TITLE>` | The quiz title.
`<ANSWER_n>` | The `n`th answer.

There must be at least as many answers as defined in `<ANSWER_COUNT>`.

The question lines should match the following formatting:

``` 
<ANSWER_COUNT>#<QUESTION_TITLE>#<ANSWER_1>#<ANSWER_2>#...#<ANSWER_n>
```
