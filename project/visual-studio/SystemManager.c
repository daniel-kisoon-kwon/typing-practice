#include <stdio.h>
#include <stdlib.h>

#include "SystemManager.h"
#include "ErrorDefine.h"

engine* Engine = NULL;
histroyRecorder* HistoryRecorder = NULL;

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

histroyRecorder* createHistroyRecorder()
{
	HistoryRecorder = (histroyRecorder*)malloc(sizeof(histroyRecorder));
	if (NULL == HistoryRecorder)
	{
		printf("[Error] Memory allocation fail!\n");
		exit(1);
	}
	HistoryRecorder->record = NULL;
	HistoryRecorder->print = NULL;
	//printf("Create HistoryRecorder!\n");
	
	return HistoryRecorder;
}

void freeMemory()
{
	if ( NULL != Engine )
	{
		free(Engine);
		Engine = NULL;
		//printf("Engine free complete!\n");
	}

	if ( NULL != HistoryRecorder )
	{
		free(HistoryRecorder);
		HistoryRecorder = NULL;
		//printf("HistoryRecorder free complete!\n");
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