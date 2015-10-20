#include <stdio.h>
#include "SentenceManager.h"
#include "SystemManager.h"

int main()
{
	sentenceManager* test= createSentenceManager();
	initSentenceManager(test);
	test->loadSentenceData();
	test->addSentenceData("12345");
	test->modifySentenceData(2, "654321");
	test->deleteSentenceData(4);
	test->print();
	deinitSentenceManager();
	return 0;
}