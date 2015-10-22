#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#include "TypingManager.h"
#include "SystemManager.h"
#include "ErrorDefine.h"
int getTypingSpeed(time_t startTime, int typingCount)
{
	time_t endTime;
	time_t tick = (time(&endTime) - startTime);
	int ret = tick == 0 ? 0 : (int)((typingCount* 60) / (time(&endTime) - startTime));
	return ret;
}

int getAccuracy(char* questionSentence, char* inputSentence)
{
	int fault = 0;
	int SentenceLength = strlen(questionSentence);
	int i = 0;
	bool isSentenceEnd = false;
	
	for(i = 0; i< SentenceLength; i++)
	{
		if ('\0' == inputSentence[i]) isSentenceEnd = true;
		if (isSentenceEnd || (questionSentence[i] != inputSentence[i]))
			fault++;
	}
	return ((SentenceLength - fault) * 100) / SentenceLength;
}

char* inputSentence(char* inputSentence, int length)
{
	
	int i = 0;
	bool needBreak = false;
	int typingCount = 0;

	time_t startTime;
	time(&startTime);
	while (1)
	{	
		int typingSpeed = 0;
		char c = getch();
		inputSentence[i] = c;
		typingCount++;
		
		typingSpeed = getTypingSpeed(startTime, typingCount);
		
		if (i >= length)
			needBreak = true;
		else
		{
			switch (c)
			{
				case '\n':
				case '\r':
					needBreak = true;
				break;
				case '\b':
	                if (i>0 && i<length)
					{
						putch(inputSentence[i]);
						putch(' ');
						putch(inputSentence[i]);
						i--;
					}
				break;
				default:
					putchar(inputSentence[i]);
					i++;
				break;
			}
		}
		if (needBreak)
		{
			inputSentence[i] = '\0';
			break;
		}
	}
	return inputSentence;
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
