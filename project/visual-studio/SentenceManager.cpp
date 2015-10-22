#include <stdlib.h>
#include <string.h>
#include "SentenceManager.h"
#include "SystemManager.h"
#include "ErrorDefine.h"

int loadSentenceData()
{
	sentenceData* tmp = getSentenceDataHead();
	int sentenceNumber = 0;
	FILE *fp = fopen("temp.txt", "rt");

	if (NULL == fp)
	{
		printf("File open error!\n");
		return ERR_FILE_OPEN_FAIL;
	}

	while (NULL != tmp)
	{
		tmp->value = getLine(fp);
		if (tmp->value[0] != '\0')
		{
			tmp->pNext = createSentenceData();
			sentenceNumber++;
		}
		tmp = tmp->pNext;
		
	}
	//printf("sentenceNumber : %d\n", sentenceNumber);
	fclose(fp);
	return sentenceNumber;
}

char* getLine(FILE* fp)
{
	char* line = createLine();
	char buf;
	int lineLength = 1;

	while (1)
	{
		buf = fgetc(fp);
		if ('\n' == buf || feof(fp)) break;
		lineLength++;

		line = (char*)realloc(line, sizeof(char)*lineLength);
		line[lineLength - 2] = buf;
	}
	line[lineLength - 1] = '\0';
	return line;
}

sentenceData* getSentenceData(int index)
{
	sentenceData* SentenceData = NULL;
	int i = 1;

	if (1 > index)
		return NULL;

	for (i = 1, SentenceData = getSentenceDataHead(); SentenceData; i++, SentenceData = SentenceData->pNext)
		if(i == index)
			return SentenceData;
	
	return SentenceData;
}

int addSentenceData(char* sentence)
{
	int i = 0;
	sentenceData* targetData = createSentenceData();
	
	targetData->value = createLine();
	targetData->value = (char*)realloc(targetData->value, sizeof(char)* (strlen(sentence)+1) );
	
	for (i = 0; i < strlen(sentence) + 1; i++)
		targetData->value[i] = sentence[i];
	
	return setSentenceDataHead(targetData);
}

int modifySentenceData(int index, char* sentence)
{
	int i = 0;
	sentenceData* targetData = getSentenceData(index);
	
	targetData->value = (char*)realloc(targetData->value, sizeof(char)* (strlen(sentence)+1) );
	
	for (i = 0; i < strlen(sentence) + 1; i++)
		targetData->value[i] = sentence[i];
	
	return 0;
}

int deleteSentenceData(int index)
{
	sentenceData* SentenceData = NULL;
	sentenceData* targetToRemove = NULL;
	int i = 0;

	if (0 > index)
		return ERR_INVALID_PARAMETER;
	
	if (index == 0)
	{
		SentenceData = getSentenceDataHead();
		targetToRemove = SentenceData;
		SentenceData = SentenceData->pNext;
	}

	for (i = 1, SentenceData = getSentenceDataHead(); SentenceData; i++, SentenceData = SentenceData->pNext)
	{
		if (i == index)
		{
			targetToRemove = SentenceData->pNext;
			SentenceData->pNext = targetToRemove->pNext;
			break;
		}
	}

	destroySentenceValue(targetToRemove);
	return 0;
}

void print()
{
	sentenceData* SentenceData = getSentenceDataHead();
	int i = 0;
	while (NULL != SentenceData)
	{
		if(SentenceData->value[0] != '\0' )
			printf("%d. %s\n", i, SentenceData->value);
		SentenceData = SentenceData->pNext;
		i++;
	}

	//printf("print Sentence\n");
}

int saveSentenceDataToFile()
{
	FILE* fp = fopen("temp.txt","w+"); 
	
	sentenceData* SentenceData = getSentenceDataHead();

	while (NULL != SentenceData)
	{
		fprintf(fp,"%s\n", SentenceData->value);
		SentenceData = SentenceData->pNext;
	}
	fclose(fp);
	printf("[save] Saved successfully\n");
	return 0;
}

int initSentenceManager(sentenceManager* SentenceManager)
{
	FILE* fp = fopen("temp.txt", "a+");
	if (NULL == fp)
	{
		printf("File open error!\n");
		return ERR_FILE_OPEN_FAIL;
	}
	fclose(fp);

	if (NULL == SentenceManager)
		return ERR_NULL_POINTER;
	setSentenceDataHead( createSentenceData() );
	SentenceManager->addSentenceData = addSentenceData;
	SentenceManager->modifySentenceData = modifySentenceData;
	SentenceManager->deleteSentenceData = deleteSentenceData;
	SentenceManager->getSentenceData = getSentenceData;
	SentenceManager->loadSentenceData = loadSentenceData;
	SentenceManager->print = print;
	SentenceManager->saveSentenceDataToFile = saveSentenceDataToFile;

	return ERR_NONE;
}
