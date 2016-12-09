#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
typedef struct single_indirect{
	int datablock_pos[120];
}single_indirect;

typedef struct double_indirect{
	int datablock_ition[120][120];
}double_indirect;

typedef struct inode{// inode는 원래 파일 이름은 저장을 안함 고유 번호로 이용함.
	      int number;//고유넘버 는 슈퍼블록에에서 받아오기
	      int mkdate[26];//파일의 생성 날짜
	      char filetype;//파일의 유형
	      int size_file;//파일의 크기 데이터블록에서 받아오기
	     int direct_block;
		 struct inode *next;
	     struct single_indirect *single;//*next처럼 이용해서 연결리스트로 들어가게 하는 것이 될 수 있다.
	     struct double_indirect *doub;
		   }inode;

inode *inode_head,*p;

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


void date_input(int inode_number){
int mkdate[26];
int time_align=0;
checktim(&mkdate);//필요할때만 쓰게 함수로 따로 빼놔야겠음
if(inode_number == -1)
	printf("inode리스트를 다 쓰고 있거나 오류가 발생했습니다.");

inode_head = (inode *)malloc(sizeof(inode));//할당해주는 것은 다른 함수에다 만들어야함
p=inode_head;
p=repeating_inter_list(inode_number);//함수만든거
strcpy(p->makdate,mkdate);
p = inode_head;//다시 원래 head주소로 돌아옴
}

	void making_linked_inode(int num_link){
for(i=0;i<num_link-1;i++){
	p->next = (inode *)malloc(sizeof(inode));
p = p->next;
	}
}

inode * repeating_inter_list(int num_link){
for(int i=0;i<num_link-1;i++)
	p = p->next;
return p;
}





return 0;
}


void inodelist_number_input(){
	int inode_number = superblock_r();
making_linked_inode(inode_number);//함수만든거
	repeating_inter_list(inode_number);
	p->number = inode_number;
}


void File_or_Directory(char buffer[20],int inode){
char file_type;
	if(buffer[0] == 'm')
		if(buffer[1] == 'k')
			if(buffer[2] == 'd')
				if(buffer[3] == 'i')
					if(buffer[4] == 'r')
						file_type = 'd';
if(buffer[0] == 'c')
	if(buffer[1] =='p')
		 file_type = 'f';
p->filetype = file_type;
}
