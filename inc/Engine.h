/******************************************************************************************************
[] Engine.h
- It has handle to calling functions by using 'typedef struct engine'.
- To use this handle, 'initEngine' must be called before using functions of engine struct.
ex) engine* Engine;
initEngine(Engine);
Engine->generateNumber();
Engine->checkAnswer(123);
- After 'checkAnswer' is called, it is able to use 'hint' that is result from 'checkAnswer'
*******************************************************************************************************/

#pragma once

/*
[] Consistence
targetNumber : guessed value from user input
ball : count of Ball comparing  targetNumber to answer
strike : count of Strike comparing  targetNumber to answer
checkAnswer : funtion pointer to use checkAnswer() function
*/
typedef struct _hint
{
	int targetNumber;
	int ball;
	int strike;
	int answer;
}hint;

/*
[] Consistence
generateNumber : function pointer to use generateNumber() function
checkAnswer : funtion pointer to use checkAnswer() function
*/
typedef struct _engine
{
	/*
	input: X
	output : generated random number
	Generates random number
	*/
	int(*generateNumber)();

	/*
	input: int input value
	output : generated hint
	Get hint with target value(set input value, ball, strike and value for answer or not)
	*/
	hint(*checkAnswer)(int input);
}engine;

/*
input : typedef struct engine
output : 0(success), non-zeror(error)
Register function pointers
*/
int initEngine(engine *Engine);