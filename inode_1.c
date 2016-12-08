
#include<stdio.h>
#include<time.h>
#include<string.h>


void checktim(int koreatime[26]){
	struct tm *t;
	time_t now;
	now = time(NULL);
	t = localtime(&now);
	int sec = t->tm_sec-1;
	int min = t->tm_min;
	int hour = t->tm_hour;
	int mon = t->tm_mon+1;
	int mday = t->tm_mday;
	int year = t->tm_year+1900;
	sprintf(koreatime,"%d년 %d월 %d일 %d시 %d분 %d초",year,mon,mday,hour,min,sec);
}


int main(void){
int mkdate[26];
checktim(&mkdate);


typedef struct inode{// inode는 원래 파일 이름은 저장을 안함 고유 번호로 이용함.
	      int number;//고유넘버 는 슈퍼블록에에서 받아오기
	      int mkdate[26];//파일의 생성 날짜
	      char filetype;//파일의 유형
	      int size_file;//파일의 크기 데이터블록에서 받아오기
	     int direct_block;
	     struct inode *sing;//*next처럼 이용해서 연결리스트로 들어가게 하는 것이 될 수 있다.
	     struct inode **doub;
		   }inode;
inode vs;
strcpy(vs.mkdate,mkdate);
printf("vsmkdate에 값 :  %s",vs.mkdate);
return 0;
}


