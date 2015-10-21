
#pragma once
#include <stdio.h>
/*
[] Consistence
record : function pointer to use generateNumber() function
print : funtion pointer to use checkAnswer() function
*/
typedef struct fileManager
{
	FILE*(*openFile)(char* path);
	void(*closeFIle)(FILE* fp);
}fileManager;

/*
input : typedef struct engine
output : 0(success), non-zeror(error)
Register function pointers
*/
int initTypingManager(typingManager* TypingManager);