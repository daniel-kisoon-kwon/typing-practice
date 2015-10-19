#include<stdio.h>
#include<conio.h>
void Put_Password(int type);
int main()
{
	char pwd[9];
	char c;
	int i = 0;
	int loop;

	do
	{
		loop = 0;
		for (i = 0; i<9; i++)
		{
			pwd[i] = 0;
		}
		i = 0;
		printf("패스워드를 (~8자리) 입력하세요 : ");

		while (1)
		{
			pwd[i] = getch();

			if (i >= 8)
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
				if (i>0 && i<9)
				{
					putch(pwd[i]);
					putch(' ');
					putch(pwd[i]);
					i--;
				}

			}
			else {
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