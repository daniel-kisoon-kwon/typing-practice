#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "TypingManager.h"
#include "SystemManager.h"
#include "ErrorDefine.h"

int getTypingSpeed(int startTime, int typingCount)
{
	return (int)((typingCount* 60) / ((time(NULL) - startTime) % 60));
}

int getAccuracy(char* questionSentence, char* inputSentence)
{
	int correctChar = 0;
	int SentenceLength = strlen(questionSentence);
	int i = 0;
	
	for(i = 0; i< SentenceLength; i++)
		if (('\0' != inputSentence[i]) && (questionSentence[i] == inputSentence[i]))
			correctChar++;

	return SentenceLength == 0 ? 0 : ((correctChar) * 100) / SentenceLength;
}

char* inputSentence(char* inputSentence, int length)
{
	
	int i = 0;
	bool needBreak = false;
	int typingCount = 0;
	int startTime = (int) time(NULL);
	printf("length : %d\n", length);
	while (1)
	{	
		int typingSpeed = 0;
		char c = getch();
		inputSentence[i] = c;
		typingCount++;
		
		//typingSpeed = getTypingSpeed(startTime, typingCount);
		
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
	printf("[TM]inputSentence : %s\n", inputSentence);
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
