/******************************************************************************************************
[] SystemManager.h
- Memory management.
- Customized scanf to input inteager value.
- After 'createEngine' or 'createHistoryRecorder' is called, 'freeMemory' must be called to free allocated memory.
*******************************************************************************************************/

#pragma once

#include "Engine.h"
#include "HistoryRecorder.h"

/*
input: X
output : Memory-allocated engine struct
Allocate dynamic memory of engine
*/
engine* createEngeine();

/*
input: X
output : Memory-allocated histroyRecorder struct
Allocate dynamic memory of histroyRecorder
*/
histroyRecorder* createHistroyRecorder();

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