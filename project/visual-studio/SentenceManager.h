/******************************************************************************************************
[] HistoryRecorder.h
- It has handle to calling functions by using 'typedef struct historyRecorder'.
- To use this handle, 'initSentenceManager' must be called before using functions of historyRecorder struct.
ex) historyRecorder* HistoryRecorder;
initHistoryRecorder(HistoryRecorder);
HistoryRecorder->record(hint);
HistoryRecorder->print();
- After 'checkAnswer' is called, it is able to use 'hint' that is result from 'checkAnswer'
*******************************************************************************************************/

#pragma once

#include <stdio.h>
#include "Engine.h"

typedef struct sentenceData {
	char* value;
	sentenceData* pNext;
}sentenceData;

/*
[] Consistence
record : function pointer to use generateNumber() function
print : funtion pointer to use checkAnswer() function
*/
typedef struct sentenceManager
{
	int(*loadSentenceData)();
	sentenceData*(*getSentenceData)(int index);
	int(*addSentenceData)(char* sentence);
	int(*modifySentenceData)(int index, char* sentence);
	int(*deleteSentenceData)(int index);
	void(*print)();
}sentenceManager;

/*
input : typedef struct engine
output : 0(success), non-zeror(error)
Register function pointers
*/
char* getLine(FILE* fp);
int initSentenceManager(sentenceManager* SentenceManager);
int deinitSentenceManager();