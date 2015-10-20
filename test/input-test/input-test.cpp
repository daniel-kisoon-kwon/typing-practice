#include<stdio.h>
#include<conio.h>
#include <windows.h>

void Put_Password(int type);
void gotoxy(int x, int y);
int main()
{
	char pwd[100] = { 0, };
	char c;
	int i = 0;
	int loop;
	int temp = 0;
	do
	{
		loop = 0;
		printf("Sentence : ");
		
		while (1)
		{
			
			pwd[i] = getch();
			
			gotoxy(2, 4);
			printf("typing number : %d", temp++);
			if (i >= 99)
			{
				Put_Password(1);
				loop = 1;
				break;
			}

			if (pwd[i] == '\r')
			{
				pwd[i] = NULL;
				break;
			}
			if (pwd[i] == '\b')
			{
				if (i>0 && i<100)
				{
					gotoxy(i+1, 3);
					putch(pwd[i]);
					putch(' ');
					putch(pwd[i]);
					i--;
				}

			}
			else {
				gotoxy(i+1, 3);
				putchar(pwd[i]);
				i++;
			}
		}
		if (i == 0)
		{
			Put_Password(2);
			loop = 1;
		}

	} while (loop);
	printf("\n \n\n %s\n", pwd);
	return 0;
}
void Put_Password(int type)
{
	if (1 == type)
	{
		printf("\n");
		printf("*********************************");
		printf("\n");
		printf("패스워드 입력범위를 벗어났습니다.\n입력범위는 8자리입니다.");
		printf("\n");
		printf("*********************************");
		printf("\n");
	}

	if (2 == type)
	{
		printf("\n");
		printf("입력값이 잘 못되었습니다.");
		printf("\n");
	}

}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}