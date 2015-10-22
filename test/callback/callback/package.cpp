/*
File Name : package.cpp

Copyright : Free.

Creation Date : 1999.9.5.
Previous Author : None.
Main Author : Kwang Hyun, Shaun.(E-mail : drakan@hitel.net)

Comment : Sample code for callback function understanding.
-------------------------------------------------------------------------*/

#include "callback.h" 

int print_integer(CALLBACK pfn_Callback, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d, ", pfn_Callback(i));
	printf("\n");

	return n;
}

/*        File End.
-------------------------------------------------------------------------*/