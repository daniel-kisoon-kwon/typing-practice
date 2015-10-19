/******************************************************************************************************
[] HistoryRecorder.h
- It has handle to calling functions by using 'typedef struct historyRecorder'.
- To use this handle, 'initHistroyRecorder' must be called before using functions of historyRecorder struct.
ex) historyRecorder* HistoryRecorder;
    initHistoryRecorder(HistoryRecorder);
    HistoryRecorder->record(hint);
    HistoryRecorder->print();
- After 'checkAnswer' is called, it is able to use 'hint' that is result from 'checkAnswer'
*******************************************************************************************************/

#pragma once

#include <stdio.h>
#include "Engine.h"

/*
[] Consistence
record : function pointer to use generateNumber() function
print : funtion pointer to use checkAnswer() function
*/
typedef struct histroyRecorder
{
	/*
	input: hint information 
	output : 0(success), non-zeror(error)
	Records input hint
	*/
	int (*record)(hint hint);
	
	/*
	input: X
	output : x
	Print records of histroy
	*/
	void (*print)();
}histroyRecorder;

/*
input : typedef struct engine
output : 0(success), non-zeror(error)
Register function pointers
*/
int initHistoryRecorder(histroyRecorder* HistoryRecorder);