#include "stdio.h" 
#include "conio.h" 
#include "time.h" 

void main() 
{ 
  int key = 0; 
  do { 
      printf("Start : Press Enter Key!!\n"); 
      printf("Exit : Press 'q' Key!!\n"); 

      key = 0; 
      while( key != 13 && key != 'q') key = getch(); 

      time_t start_time, end_time; 
      time(&start_time); 

      if(key == 13){ 
          printf("<< End : Press Any Key!! >>\n"); 
          while(!_kbhit()){ 
              time(&end_time); 
              printf("%d\r", end_time - start_time); 
          } 
          printf("%d\n\n", end_time - start_time); 
          getch(); 
      } 
  } while(key != 'q'); 
} 