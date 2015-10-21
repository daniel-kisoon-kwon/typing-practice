#include <stdio.h>
#include <conio.h> // _getch()
#include <time.h> // time()

int main(void) {

	int startTime = (int) time(NULL);
		
	//ret = (int) (time(NULL) - startTime) % 60;
	
	puts("타이머 ON! 아무키나 누르면 종료");

	// 유저가 아무 키나 누를 때까지 무한정 대기
	_getch(); // _getch() 는 getch() 의 보안 강화 버전

	printf("timer : %d\n", (int) (time(NULL) - startTime) % 60);// 0을 넣으면 타이머가 꺼지고 시간 문자열을 버퍼에 설정
	return 0;
}