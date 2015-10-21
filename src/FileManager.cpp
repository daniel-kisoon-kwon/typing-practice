#include <stdio.h>
#include "ErrorDefine.h"

FILE* openFile(char* path)
{
	int ret = 0;
	FILE* fp;
	if (NULL == (fp = fopen(path, "r+")))
	{
		printf("File not found / path : %s!\n", path);
		if (NULL == (fp = fopen(path, "w+")))
		{
			printf("File open error! / path : %s!\n", path);
			ret = -1;
		}
		else
			printf("New file created / path : %s!\n", path);
	}
	return fp;
}

void closeFile(FILE* fp)
{
	if (NULL != fp) fclose(fp);
}

int initFileManager(fileManager* FileManager)
{
	if (NULL == FileManager)
		return ERR_NULL_POINTER;
	FileManager-> = getAccuracy;
	TypingManager->getTypingSpeed = getTypingSpeed;
	TypingManager->inputSentence = inputSentence;

	return ERR_NONE;
}
