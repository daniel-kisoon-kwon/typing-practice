
#pragma once
/*
[] Consistence
record : function pointer to use generateNumber() function
print : funtion pointer to use checkAnswer() function
*/
typedef struct typingManager
{
	int(*getTypingSpeed)(int startTime, int typingCount);
	int(*getAccuracy)(char* questionSentence, char* inputSentence);
	char*(*inputSentence)(char* inputSentence, int length);
}typingManager;

/*
input : typedef struct engine
output : 0(success), non-zeror(error)
Register function pointers
*/
int initTypingManager(typingManager* TypingManager);