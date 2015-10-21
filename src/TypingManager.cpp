#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "TypingManager.h"
#include "ErrorDefine.h"

int getTypingSpeed(int startTime, int typingCount)
{
	return (int)((typingCount* 60) / ((time(NULL) - startTime) % 60));
}

int getAccuracy(char* questionSentence, char* inputSentence)
{
	int faultChar = 0;
	int inputSentenceLength = strlen(inputSentence) + 1;
	int i = 0;
	
	for(i = 0; i< inputSentenceLength; i++)
		if(questionSentence[i] != inputSentence[i])
			faultChar++;

	return (int)((inputSentenceLength - faultChar) / inputSentenceLength) * 100;
}

char* inputSentence(size_t sentenceLength)
{
	char pwd[100] = { 0, };
	int i = 0;
	bool needBreak = false;
	int typingCount = 0;
	int startTime = (int) time(NULL);

	while (1)
	{	
		int typingSpeed = 0;
		pwd[i] = getch();
		typingCount++;
		
		typingSpeed = getTypingSpeed(startTime, typingCount);
		
		if (i >= 99)
			needBreak = true;
		else
		{
			switch (pwd[i])
			{
				case '\r':
					needBreak = true;
				break;
				case '\b':
					putch(pwd[i]);
					putch(' ');
					putch(pwd[i]);
					i--;
				break;
				default:
				putchar(pwd[i]);
				i++;
				break;
			}
		}
		if (needBreak)
		{
			pwd[i] = '\0';			
			break;
		}
	}
	return pwd;
}

int initTypingManager(typingManager* TypingManager)
{
	FILE* fp = fopen("temp.txt", "a+");
	if (NULL == fp)
	{
		printf("File open error!\n");
		return ERR_FILE_OPEN_FAIL;
	}
	fclose(fp);

	if (NULL == TypingManager)
		return ERR_NULL_POINTER;
	TypingManager->getAccuracy = getAccuracy;
	TypingManager->getTypingSpeed = getTypingSpeed;
	TypingManager->inputSentence = inputSentence;

	return ERR_NONE;
}
