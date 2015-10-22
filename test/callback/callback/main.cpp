/*
File Name : main.cpp

Copyright : Free.

Creation Date : 1999.9.5.
Previous Author : None.
Main Author : Kwang Hyun, Shaun.(E-mail : drakan@hitel.net)

Comment : Sample code for callback function understanding.
-------------------------------------------------------------------------*/
#include "callback.h" 
int print_integer(CALLBACK pfn_Callback, int n);

int Callback_0(int i)
{
	return i + 0;
}

int Callback_1(int i)
{
	return i + 1;
}

int Callback_2(int i)
{
	return i + 2;
}

void main()
{
	print_integer(Callback_0, 10);
	print_integer(Callback_1, 10);
	print_integer(Callback_2, 10);
}

/*        File End.
-------------------------------------------------------------------------*/