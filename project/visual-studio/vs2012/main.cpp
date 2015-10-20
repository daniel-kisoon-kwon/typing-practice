#include <stdio.h>
#include "SentenceManager.h"
#include "SystemManager.h"

int main()
{
	sentenceManager* test;
	initSentenceManager(test);
	test->loadSentenceData();
	test->print();
	return 0;
}