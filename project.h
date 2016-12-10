#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
struct tm{
	int tm_sec;//초[0,61]
	int tm_min;//분[0,59]
	int tm_hour;//시[0,23]
	int tm_mon;//월[0,11]
	int tm_mday;//일[1,31]
	int tm_year;//년 1900년이후
};
struct tm *t;
time_t now;
now = time(NULL);
t = localtime(&now);

int * time(tm t)
{
	int mkdate[7];
	mkdate[0] = t->tm_year;
	mkdate[1] = t->tm_mon;
	mkdate[2] = t->tm_mday;
	mkdate[3] = t->tm_hour;
	mkdate[4] = t->tm_min;
	mkdate[5] = t->tm_sec;

	return mkdate;
}

typedef struct datablock{



}datablock;


typedef struct inode
{
	char type;//파일종류
	char mkdate[18];	//파일 생성날짜
	int size;//파일크기
	struct inode *p;//direct block
	struct datablock *sing;//single indirect block
	struct datablock **doub;//double indirect blockl
}inode;


void Get_inode();// 파일 및 디렉토리 생성
void Free_inode();//파일 및 디렉터리 삭제
void Get_datablock();//파일 및 디렉터리 생성 및 업데이트
void Free_datablock();//파일 및 디렉터리 삭제 및 업데이트
void Set_inode_info();//파일 및 디렉터리 생성
void Write_datablock();//파일 생성 업데이트 등
void Read_datablock();//파일 읽기


void superblockinfo(){//슈퍼블록의 내용을 볼수 있는 함수
typedef sturct superblock{
	int total_inode;//총 inode개수
	int inode[];// 이걸로 할까? 아니면 찾는 값이 1이면 알려주는 변수로 만들까?
	int total_block;//전체 블록의 개수
	int block[];//블록의 사용하는지 안 하는지
	int size_block;//블록의 크기
	int freeblock;//할당되지 않은 블록의 개수
}superblock;
superblock block;
printf("슈퍼블록의 정보\n");
}// project.h 파엘이 담아놓겠음



