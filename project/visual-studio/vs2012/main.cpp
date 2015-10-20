#include <stdio.h>
#include "SentenceManager.h"
#include "SystemManager.h"

int main()
{
	sentenceManager* test= createSentenceManager();
	initSentenceManager(test);
	test->loadSentenceData();
	test->addSentenceData("111111111111111111");
	test->modifySentenceData(2, "333333333333333333");
	test->deleteSentenceData(4);
	test->print();
	deinitSentenceManager();
	return 0;
}