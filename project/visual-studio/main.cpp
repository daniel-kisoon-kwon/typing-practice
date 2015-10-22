#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
//#include <Windows.h>
#include "SentenceManager.h"
#include "SystemManager.h"
#include "TypingManager.h"

int typingPractice(typingManager* TypingManager, sentenceManager* SentenceManager, int totalSentenceNumber);
int getRandomNumber(int totalSentenceNumber);
void sentenceDataSetting(sentenceManager* SentenceManager);
void saveNode(sentenceManager* SentenceManager);
//void gotoxy(int x, int y);

int main(int argc, char* argv[])
{
	int selectNum = 0;
	int totalSentenceNumber = 0;
	int randomNumber = 0;
	int i = 0;

	sentenceManager* SentenceManager = createSentenceManager();
	typingManager* TypingManager = createTypingManager();
	initSentenceManager(SentenceManager);
	initTypingManager(TypingManager);

	totalSentenceNumber = SentenceManager->loadSentenceData();
	if(0 == totalSentenceNumber)
		printf("Sentence is not exist!\n");

	while (1)
	{
		bool needBreak = false;
		printf("** Typing Practice **\n");
		printf(" [] Select Menu\n");
		printf("   1. Practice Start\n");
		printf("   2. Sentence Data Setting\n");
		printf("   3. Exit\n");
		printf(" [] input : ");
		scanf("	 %d", &selectNum);
		clearEnter();
		
		switch (selectNum)
		{
		case 1:
			typingPractice(TypingManager, SentenceManager, totalSentenceNumber);
			break;
		case 2:
			sentenceDataSetting(SentenceManager);
			break;
		case 3:
			destroySentenceManager(SentenceManager);
			destroyTypingManager(TypingManager);
			destroySentenceData();
			needBreak = true;
			break;
		default:
			printf(" [] Invalid number\n");
			break;
		}
		system("cls");
		if (needBreak) break;
	}
	
	return 0;
}

int typingPractice(typingManager* TypingManager, sentenceManager* SentenceManager, int totalSentenceNumber)
{
	while(1)
	{
		int randumNumber = getRandomNumber(totalSentenceNumber);
		char* questionSentence = (SentenceManager->getSentenceData(randumNumber))->value;
		char* inputSentence = strdup(questionSentence);
		char* outputSentence = NULL;
		int accuracy = 0;
		system("cls");
		
		printf("%s\n", questionSentence); 
		outputSentence = TypingManager->inputSentence(inputSentence, strlen(questionSentence));
		accuracy = TypingManager->getAccuracy(questionSentence, outputSentence);
		free(outputSentence);

		printf("\n\n [] Accuracy %d %%\n", accuracy);
	
		printf("\n [] Please anykey... (Ctrl+z for exit)\n");
		if(getch() == 26) break;
	}
	return 0;
}

int getRandomNumber(int totalSentenceNumber)
{
	srand(time(NULL));
	return (rand() % totalSentenceNumber)+1;
}


void sentenceDataSetting(sentenceManager* SentenceManager)
{
	int selectNum = 0;
	int targetIndex = 0;
	char sentence[400] = { '\0', };
	SentenceManager->print();
	printf(" [] Sentence data setting\n");
	printf("   1. Insert sentence\n");
	printf("   2. Modify sentence\n");
	printf("   3. Delete sentence\n");
	printf("   4. Back to main menu\n");
	printf(" [] input : ");
	scanf("	 %d", &selectNum);
	clearEnter();
	switch (selectNum)
	{
	case 1:
		printf(" [Insert] Sentence : ");
		scanf("%399[^\n]s", sentence);
		clearEnter();
		SentenceManager->addSentenceData(sentence);
		SentenceManager->print();
		break;
	case 2:
		printf(" [Modify] Target index : ");
		scanf("%d", &targetIndex);
		clearEnter();
		printf(" [Modify] Description : ");
		scanf("%399[^\n]s", sentence);
		clearEnter();
		SentenceManager->modifySentenceData(targetIndex, sentence);
		SentenceManager->print();
		break;
	case 3:
		printf(" [Delete] Target index : ");
		scanf("%d", &targetIndex);
		clearEnter();
		SentenceManager->deleteSentenceData(targetIndex);
		SentenceManager->print();
		break;
	case 4:
		saveNode(SentenceManager);
	default:
		break;
	}
}

void saveNode(sentenceManager* SentenceManager)
{
	char ch;
	printf(" [Save] Save Lunch place info to file(y/n)?");
	ch = getch();
	printf("%c", ch);
	if( 'y' == ch || 'Y' == ch)
	{
		printf(" [Save] Saving... \n");
		SentenceManager->saveSentenceDataToFile();
	}
	else if ( 'n' == ch || 'N' == ch) { ; }
	else
	{
		printf(" [Error] Invalid value\n");
		saveNode(SentenceManager);
	}
}
/*
void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
*/