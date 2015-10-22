#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

void gotoxy(int x, int y);
int main()
{
	char pwd[100] = { 0, };
	int i = 0;
	bool needBreak = false;
	int typingCount = 0;
	int startTime = (int) time(NULL);

	while (1)
	{	
		int typingSpeed = 0;
		pwd[i] = getch();
		typingCount++;
		
		typingSpeed = (int)((typingCount* 60) / ((time(NULL) - startTime) % 60));
		//callback - return typing count(speed)
		{
			gotoxy(2, 2);
			printf("typing number : %d typing/min", typingSpeed);
		}

		if (i >= 99)
			needBreak = true;
		else
		{
			gotoxy(i+1, 1);
			switch (pwd[i])
			{
				case '\r':
					needBreak = true;
				break;
				case '\b':
					putch(pwd[i]);
					putch(' ');
					putch(pwd[i]);
					i--;
				break;
				default:
					printf("\b");
				putchar(pwd[i]);
				i++;
				break;
			}
		}
		if (needBreak)
		{
			pwd[i] = '\0';			
			break;
		}
	}
	return 0;
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}