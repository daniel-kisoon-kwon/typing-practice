/******************************************************************************************************
[] SystemManager.h
- Memory management.
- Customized scanf to input inteager value.
- After 'createEngine' or 'createSentenceManager' is called, 'freeMemory' must be called to free allocated memory.
*******************************************************************************************************/

#pragma once

#include "Engine.h"
#include "SentenceManager.h"
#include "TypingManager.h"

/*
input: X
output : Memory-allocated sentenceManager struct
Allocate dynamic memory of sentenceManager
*/
sentenceData* createSentenceData();
sentenceData* getSentenceDataHead();
int setSentenceDataHead(sentenceData* newData);
void destroySentenceValue(sentenceData* SentenceData);

sentenceManager* createSentenceManager();
void destroySentenceManager(sentenceManager* SentenceManager);

typingManager* createTypingManager();
void destroyTypingManager(typingManager* TypingManager);





char* createLine();
void destroyLine(char* Line);
/*
input : X
output : X
Free all allocated memories.
*/
void destroySentenceData();

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