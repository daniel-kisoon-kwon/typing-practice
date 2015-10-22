#include <conio.h>
#include <Windows.h>
#include "TypingPracticeCallback.h"

int printTypingSpeed(CALLBACK pfn_Callback, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d, ", pfn_Callback(i));
	printf("\n");

	return n;
}

int printInputSentence(CALLBACK pCallback,int n)
{ 
   return pCallback(n); 
}