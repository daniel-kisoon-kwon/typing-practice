#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SentenceManager.h"
#include "SystemManager.h"
#include "TypingManager.h"
#include "TypingPracticeCallback.h"

int main(int argc, char* argv[])
{
	int totalSentenceNumber = 0;
	int randomNumber = 0;
	int i = 0;

	char* path = argv[1];
	path = path ? path : "lunch-place-info.txt";
	if (LoadFile(path) != 0)
	{
		printf("Load fail!\n");
		return -1;
	}

	sentenceManager* test= createSentenceManager();

	

	initSentenceManager(test);
	totalSentenceNumber = test->loadSentenceData();
	if(0 == totalSentenceNumber)
		printf("Sentence is not exist!\n");
	test->addSentenceData("12345");
	test->modifySentenceData(2, "654321");
	test->deleteSentenceData(4);
	test->print();
	
	
	for (i = 0; i < 5; i++)
	{
		randomNumber = pickRandomSentenceNumber(totalSentenceNumber);
		printf("random sentence(%d) : %s\n", randomNumber, test->getSentenceData(randomNumber)->value);
	}
	
	return 0;
}

int pickRandomSentenceNumber(int totalSentenceNumber)
{
	srand(time(NULL));
	return rand() % totalSentenceNumber;
}

bool mainMenu()
{
	int selectNum = 0;
	LunchPlaceInfo* lunchPlace = NULL;
	printf("** Typing Practice **\n");
	printf(" [] Select Menu\n");
	printf("   1. Practice Start\n");
	printf("   2. Sentence Data Setting\n");
	printf("   3. Exit\n");
	printf(" [] input : ");
	scanf("	 %d",&selectNum);
	clearEnter();
	switch (selectNum)
	{
	case 1:
		lunchPlace = pickLunchPlace();
		if(lunchPlace)
			printf("[result] Lunch Place information : NAME(%s) / DESC(%s)\n", lunchPlace->name, lunchPlace->desc);
		else
			printf("[result] There is no lunch place!\n");
		saveLunchPlaceInfoToFile();
		break;
	case 2:
		nodeSetting();
		break;
	case 3:
		saveNode();
		release();
		closeFile();
		exit(1);
	default:
		printf(" [] Invalid number\n");
		break;
	}
	printf("\n");
}

void nodeSetting()
{
	int selectNum = 0;
	int targetIndex = 0;
	char name[100] = { '\0', };
	char desc[400] = { '\0', };
	printNode();
	printf(" [] Sentence data setting\n");
	printf("   1. Insert sentence\n");
	printf("   2. Modify sentence\n");
	printf("   3. Delete sentence\n");
	printf("   4. Save sentence data to file\n");
	printf("   5. Back to main menu\n");
	printf(" [] input : ");
	scanf("	 %d", &selectNum);
	clearEnter();
	switch (selectNum)
	{
	case 1:
		printf(" [Insert] Name : ");
		scanf("%99[^\n]s", name);
		clearEnter();
		printf(" [Insert] Description : ");
		scanf("%399[^\n]s", desc);
		clearEnter();
		insertLunchPlaceInfo(name, desc);
		printNode();
		break;
	case 2:
		printf(" [Modify] Target index : ");
		scanf("%d", &targetIndex);
		clearEnter();
		printf(" [Modify] Name : ");
		scanf("%99[^\n]s", name);
		clearEnter();
		printf(" [Modify] Description : ");
		scanf("%399[^\n]s", desc);
		clearEnter();
		modifyLunchPlaceInfo(targetIndex, name, desc);
		printNode();
		break;
	case 3:
		printf(" [Delete] Target index : ");
		scanf("%d", &targetIndex);
		clearEnter();
		deleteLunchPlaceInfo(targetIndex);
		printNode();
		break;
	case 4:
	default:
		mainMenu();
		break;
	}
}

void saveNode()
{
	char ch;
	printf(" [Save] Save Lunch place info to file(y/n)?");
	scanf("%c", &ch);
	clearEnter();
	if( 'y' == ch || 'Y' == ch)
	{
		printf(" [Save] Saving... \n");
		saveLunchPlaceInfoToFile();
		printNode();
	}
	else if ( 'n' == ch || 'N' == ch) { ; }
	else
	{
		printf(" [Error] Invalid value\n");
		saveNode();
	}
}