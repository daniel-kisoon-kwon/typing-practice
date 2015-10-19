#include "HistoryRecorder.h"
#include "ErrorDefine.h"

static char* getLine(FILE *fp)
{
	char* line = (char*)malloc(sizeof(char) * 1);
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

int addSentence(char* sentence)
{
	FILE *fp = fopen("temp.txt", "a+");
	if ( NULL == fp )
	{
		printf("File open error!\n");
		return ERR_FILE_OPEN_FAIL;
	}
	sentence = fputs(sentence, fp);
	fclose(fp);
	return 0;
}

int loadSentence(char* sentence)
{
	FILE *fp = fopen("temp.txt", "rt");
	if (NULL == fp)
	{
		printf("File open error!\n");
		return ERR_FILE_OPEN_FAIL;
	}
	sentence = getLine(fp);

	fclose(fp);
	return 0;
}

void print()
{
	FILE* fp = fopen("temp.txt", "rt");
	if (NULL == fp)
		printf("File open error!\n");
	else
	{
		char result[25];
		while (fgets(result, sizeof(result), fp) != NULL)
			printf(result);
		fclose(fp);
	}
	//printf("print recorded file\n");
}

int initHistoryRecorder(histroyRecorder* HistoryRecorder)
{
	FILE* fp = fopen("temp.txt", "w+");
	if (NULL == fp)
	{
		printf("File open error!\n");
		return ERR_FILE_OPEN_FAIL;
	}
	fclose(fp);

	if (NULL == HistoryRecorder)
		return ERR_NULL_POINTER;

	HistoryRecorder->record = record;
	HistoryRecorder->print = print;

	return ERR_NONE;
}
