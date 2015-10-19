/******************************************************************************************************
[] SystemManager.h
- Memory management.
- Customized scanf to input inteager value.
- After 'createEngine' or 'createSentenceManager' is called, 'freeMemory' must be called to free allocated memory.
*******************************************************************************************************/

#pragma once

#include "Engine.h"
#include "SentenceManager.h"

/*
input: X
output : Memory-allocated engine struct
Allocate dynamic memory of engine
*/
engine* createEngeine();

/*
input: X
output : Memory-allocated sentenceManager struct
Allocate dynamic memory of sentenceManager
*/
sentenceData* createSentenceData();
sentenceData* getSentenceDataHead();
sentenceManager* createSentenceManager();


char* createLine();
/*
input : X
output : X
Free all allocated memories.
*/
void freeMemory();

/*
input : inteager pointer value
output : X
Free all allocated memories.
*/
void scanfForAnswer(int* number);

/*
input : X
output : X
Free stored in stdin memory.
*/
void clearEnter();