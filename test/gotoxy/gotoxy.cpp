#include<stdio.h>
#include<windows.h>

void gotoxy(int x, int y);

int main(void)
{
	int i = 0;
	for (i = 0; i <= 100; i++)
	{
		gotoxy(1, 1);
		printf("buffering ... %d\n", i);
	}
	return 0;
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}