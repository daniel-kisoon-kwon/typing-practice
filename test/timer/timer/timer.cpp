#include <stdio.h>
#include <conio.h> // _getch()
#include <time.h> // time()

int main(void) {

	int startTime = (int) time(NULL);
		
	//ret = (int) (time(NULL) - startTime) % 60;
	
	puts("Ÿ�̸� ON! �ƹ�Ű�� ������ ����");

	// ������ �ƹ� Ű�� ���� ������ ������ ���
	_getch(); // _getch() �� getch() �� ���� ��ȭ ����

	printf("timer : %d\n", (int) (time(NULL) - startTime) % 60);// 0�� ������ Ÿ�̸Ӱ� ������ �ð� ���ڿ��� ���ۿ� ����
	return 0;
}