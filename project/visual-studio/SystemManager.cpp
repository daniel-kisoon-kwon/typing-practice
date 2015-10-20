#include <stdio.h>
#include <stdlib.h>

#include "SystemManager.h"
#include "ErrorDefine.h"

engine* Engine = NULL;
sentenceManager* SentenceManager = NULL;
sentenceData* SentenceDataHead = NULL;
char* Line = NULL;

engine* createEngeine()
{
	Engine = (engine*)malloc(sizeof(engine));
	if (NULL == Engine)
	{
		printf("[Error] Memory allocation fail!\n");
		exit(1);
	}
	Engine->generateNumber = NULL;
	Engine->checkAnswer = NULL;
	//printf("Create Engine!\n");

	return Engine;
}

sentenceData* createSentenceData()
{
	sentenceData* SentenceData = NULL;
	
	SentenceData = (sentenceData*)malloc(sizeof(sentenceData));
	if (NULL == SentenceData)
	{
		printf("[Error] Memory allocation fail!\n");
		exit(1);
	}
	SentenceData->value = NULL;
	SentenceData->pNext = NULL;
	
	if(NULL == SentenceDataHead)
		SentenceDataHead = SentenceData;

	//printf("Create sentenceData!\n");
	return SentenceData;
}

sentenceData* getSentenceDataHead()
{
	return SentenceDataHead;
}

int setSentenceDataHead(sentenceData* newData)
{
	sentenceData* temp = SentenceDataHead;
	SentenceDataHead = newData;
	SentenceDataHead->pNext = temp;

	return 0;
}

sentenceManager* createSentenceManager()
{
	SentenceManager = (sentenceManager*)malloc(sizeof(sentenceManager));
	if (NULL == SentenceManager)
	{
		printf("[Error] Memory allocation fail!\n");
		exit(1);
	}

	SentenceManager->addSentence = NULL;
	SentenceManager->getLine = NULL;
	SentenceManager->getSentenceData = NULL;
	SentenceManager->loadSentenceData = NULL;
	SentenceManager->print = NULL;
	//printf("Create sentenceManager!\n");
	
	return SentenceManager;
}

char* createLine()
{
	Line = (char*)malloc(sizeof(char) * 1);
	if (NULL == Line)
	{
		printf("[Error] Memory allocation fail!\n");
		exit(1);
	}
	//printf("Create Line!\n");

	return Line;
}

void freeMemory()
{
	if ( NULL != Engine )
	{
		free(Engine);
		Engine = NULL;
		//printf("Engine free complete!\n");
	}

	if ( NULL != SentenceManager)
	{
		free(SentenceManager);
		SentenceManager = NULL;
		//printf("SentenceManager free complete!\n");
	}
	//printf("Memory free complete!\n");
}

void  scanfForAnswer(int* number)
{
	int i, j;
	int targetNumber[3] = { 0, 0, 0 };
	scanf("%d", number);
	if (*number < 0 || *number > 987)
		*number = ERR_INVALID_PARAMETER;
	else if (*number != 0)
	{
		targetNumber[0] = *number / 100;
		targetNumber[1] = (*number % 100) / 10;
		targetNumber[2] = (*number % 100) % 10;
		for (i = 0; i < 3; i++)
			for (j = 0; j < i; j++)
				if (i != j && targetNumber[i] == targetNumber[j])
					*number = ERR_INVALID_PARAMETER;
	}
	clearEnter();
}

void clearEnter()
{
	while (getchar() != '\n');
}