#include <stdlib.h>
#include <string.h>
#include "SentenceManager.h"
#include "SystemManager.h"
#include "ErrorDefine.h"

int loadSentenceData()
{
	sentenceData* tmp = getSentenceDataHead();
	int i = 0;
	FILE *fp = fopen("temp.txt", "rt");

	if (NULL == fp)
	{
		printf("File open error!\n");
		return ERR_FILE_OPEN_FAIL;
	}

	while (NULL != tmp)
	{
		tmp->value = getLine(fp);
		if(tmp->value[0] != '\0' )
			tmp->pNext = createSentenceData();
		tmp = tmp->pNext;
	}
	
	fclose(fp);
	return 0;
}

sentenceData* getSentenceData(int index)
{
	sentenceData* SentenceData = NULL;
	int i = 0;

	if (0 > index)
		return NULL;

	for (i = 0, SentenceData = getSentenceDataHead(); SentenceData; i++, SentenceData = SentenceData->pNext)
		if(i == index)
			return SentenceData;
	
	return SentenceData;
}

static char* getLine(FILE* fp)
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

int addSentenceData(char* sentence)
{
	sentenceData* targetData = createSentenceData();
	return setSentenceDataHead(targetData);
}

int modifySentenceData(int index, char* sentence)
{
	int i = 0;
	sentenceData* targetData = getSentenceData(index);
	targetData->value = (char*)realloc(targetData->value, sizeof(char)*strlen(sentence)+1);
	for(i=0; i<=strlen(sentence)+1; i++)
	{
		targetData->value[i] = sentence[i];
	}

	return 0;
}

int deleteSentenceData(int index)
{
	sentenceData* newData = createSentenceData();
	return setSentenceDataHead(newData);
}

void print()
{
	sentenceData* SentenceData = NULL;
	int i = 0;
	for (i = 0, SentenceData = getSentenceDataHead(); SentenceData; i++, SentenceData = SentenceData->pNext)
		printf("%d. %s", i, SentenceData->value);
	
	//printf("print Sentence\n");
}

int initSentenceManager(sentenceManager* SentenceManager)
{
	FILE* fp = fopen("temp.txt", "w+");
	if (NULL == fp)
	{
		printf("File open error!\n");
		return ERR_FILE_OPEN_FAIL;
	}
	fclose(fp);

	if (NULL == SentenceManager)
		return ERR_NULL_POINTER;

	SentenceManager->addSentenceData = addSentenceData;
	SentenceManager->getLine = getLine;
	SentenceManager->getSentenceData = getSentenceData;
	SentenceManager->loadSentenceData = loadSentenceData;
	SentenceManager->print = print;

	return ERR_NONE;
}
