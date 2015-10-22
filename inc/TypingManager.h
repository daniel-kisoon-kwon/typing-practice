#pragma once

#include "TypingPracticeCallback.h"

/*
[] Consistence
record : function pointer to use generateNumber() function
print : funtion pointer to use checkAnswer() function
*/
typedef struct typingManager
{
	int(*getTypingSpeed)(time_t startTime, int typingCount);
	int(*getAccuracy)(char* questionSentence, char* inputSentence);
	char*(*inputSentence)(printSpeedCallback printTypingSpeed, setInputPositionCallback setInputPosition, char* inputSentence, int length);
}typingManager;

/*
input : typedef struct engine
output : 0(success), non-zeror(error)
Register function pointers
*/
int initTypingManager(typingManager* TypingManager);