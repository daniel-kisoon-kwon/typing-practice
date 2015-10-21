#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SentenceManager.h"
#include "SystemManager.h"
#include "TypingManager.h"
#include "TypingPracticeCallback.h"

int main()
{
	int totalSentenceNumber = 0;
	int randomNumber = 0;
	int i = 0;
	sentenceManager* test= createSentenceManager();

	

	initSentenceManager(test);
	totalSentenceNumber = test->loadSentenceData();
	if(0 == totalSentenceNumber)
		printf("Sentence is not exist!\n");
	test->addSentenceData("12345");
	test->modifySentenceData(2, "654321");
	test->deleteSentenceData(4);
	test->print();
	
	srand(time(NULL));
	for (i = 0; i < 5; i++)
	{
		randomNumber = rand() % totalSentenceNumber;
		printf("random sentence(%d) : %s\n", randomNumber, test->getSentenceData(randomNumber)->value);
	}
	
	return 0;
}