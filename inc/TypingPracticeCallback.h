#pragma once

typedef int (*CALLBACK)(int);

int getTypingSpeedCallback(CALLBACK pCallback, int n);

int getTypingAccuracyCallback(CALLBACK pCallback, int n);