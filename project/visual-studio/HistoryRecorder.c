#include "HistoryRecorder.h"
#include "ErrorDefine.h"


int record(hint hint)
{
	FILE *fp = fopen("temp.txt", "a+");
	if ( NULL == fp )
	{
		printf("File open error!\n");
		return ERR_FILE_OPEN_FAIL;
	}
	fprintf(fp, "[ %d%d%d ] %d Strike  %d Ball\n", hint.targetNumber / 100, (hint.targetNumber % 100) / 10, ((hint.targetNumber % 100) % 10) / 1, hint.strike, hint.ball);
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
