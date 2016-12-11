#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
typedef struct directory{//inode에만 1이 됨 데이터블록에는 1없음. 왜냐하면 디렉토리는 0바이트임
	char directory_name[5];
	int number_directory;
	struct file_name *start,*q;
	struct directory *indirectory,*nextdirectory;//nextdirectory는 디렉토리를 연결리스트로만들려고한것이고 indirectroy는 디렉토리 안에 디렉토리들을 잇기위해서 만든것임
	char directory_filetype;
	int directory_inode;
	int usuage ;//starter가 가리키는 곳에는 파일의 이름이 있다. 그런데 그곳에 이름이 있으면 usuage는 1을 표시하는 것이고 안 사용하면 1은 0으로 다시 바꿀것임
	int usuage_dir;//usuage usuage_dir, usuage_indir에 =0이라고 초기화 하고 싶은데 그게 안된다...
	int usuage_indir;
}directory;

directory *root,*root_helper,*root_inhelper;//루트 포인터는 파일안에 파일들과 아이노드 담을때 쓸꺼고 inodehelper는 디렉토리를 linkedlist로 만들때 사용할 것임 

	int mk_struct_directory = 0;//기본 초기화는 0임 mkfs했을때는 1로 바뀌면서 설정해서 만들어지는 것임

void making_root_directory(){
	if(mk_struct_directory == 1)
	{	root = (directory *)malloc(sizeof(directory));
	}
	if(mk_struct_directory == -1)
		printf("root디렉토리를 없애버리실 수 없습니다.\n"); 
	strcpy(root->directory_name,"/");
		mk_struct_directory = -1;
}

	
unsigned int c= 2147483648;
unsigned int a[16]={0};// inode리스트 사용유무를 알기위한 a는 4바이트이므로 비트로 따지면 8*4=32 32비트를 담을 수 있음, 32*16=512이므로 inode를 다 담을 수 있을 크기
unsigned int b[16]={0};//데이터블록 사용유무를 알기위한 b는 "
//superblock_read inode함수
int superblock_r(){
	int index_find=0;//16개의 인덱스를 다 읽어야 해서
	int position_inode=0;

	for(;index_find<16;index_find++)
	{	 
		while(c>=1)
		{
			if(a[index_find] & c)
			{	c >>=1; // 1칸씩 뒤로 넘겨서 차례대로 읽기위해서
				++position_inode;
			}
			else
				return position_inode;
		}
		c= 2147483648;//2145483684는 10000000 00000000 00000000 00000000임
	}
	return -1;// -1로 리턴되었다는 것은 모두 꽉차있거나 오류가 발생했다는 것
}

int superblock_write(int position){
	int same_position;
	int index_find=0;
	for(;index_find<16;index_find++)
	{	 
		while(c>=1)
		{
			if(same_position == position)
			{ 
				a[index_find]+=c;
				return 1 ;// 비어있는 칸에 등록을 하고나서는위치를 알려주면서 빠져나와야함 
			}	
			else
				;
			c >>=1;		// 1칸씩 뒤로 넘겨서 차례대로 읽기위해서
			++same_position;
		}
		c= 2147483648;//2145483684는 10000000 00000000 00000000 00000000임
	}

	return 0;
}

//checktim(&a);//a는 main함수에서 그냥 26개의 인덱스를 가진 배열임 
void checktim(int koreatime[26]){
	struct tm *t;
	time_t now;
	now = time(NULL);
	t = localtime(&now);
	int sec = t->tm_sec-1;
	int min = t->tm_min;
	int hour = t->tm_hour;
	int mon = t->tm_mon+1;
	int day = t->tm_mday;
	int year = t->tm_year+1900;
	sprintf(koreatime,"%d년 %d월 %d일 %d시 %d분 %d초",year,mon,day,hour,min,sec);
}


typedef struct inode{// inode는 원래 파일 이름은 저장을 안함 고유 번호로 이용함.
	int number_inode;///이름 바꿨음.. 함수도 아마 수정해야할 거임 고유넘버 는 슈퍼블록에에서 받아오기
	int mkdate[26];//파일의 생성 날짜
	char filetype;//파일의 유형
	int size_file;//파일의 크기 데이터블록에서 받아오기
	int direct_block;
	struct inode *next;
	struct single_indirect *single;//*next처럼 이용해서 연결리스트로 들어가게 하는 것이 될 수 있다.
	struct double_indirect *doub;
}inode;
inode *inode_head,*p,*double_head;//doublehead는 더블인다이렉트블록에 접근하기 위한것임, head는 inode구조체에 가장 맨 앞에 주소를 가지고 있으며 p를 움직여서 그 안에 넣어 주는 것임

int main(void)
{char buffer[20];//명령어 임시 받는 버퍼
	char b;//명령어의 문자 하나씩 받으려고
	int comlen;//명령어 길이
	char name[5];//파일 이름의 최대 길이가 4바이트니까 + 널문자= 5바이트
	int position_inode;
	int file_date[26];
	mk_struct_directory=1;
	making_root_directory();
	(root -> number_directory) = 1;
	(root -> directory_filetype) = 'd';
	position_inode = superblock_r();//슈퍼블록에서 0인 칸을 읽어온 후 position_inode라는 변수에 저장한다.
	if(superblock_write(position_inode) != 1)//슈퍼블록에  position_inode에 저장된 칸으로 가서 값을 1을 넣고 나온다. 정상적으로 1을 넣고 나오면 1을 리턴하고 그렇지 않으면 0을 리턴
	printf("슈퍼블록에 쓰는데 오류가 생겼습니다.\n");
	inode_head = (inode *)calloc(1,sizeof(inode));
	inode_head -> number_inode = position_inode;
	checktim(&file_date);//현재시간을 받아서 보내기 위한 함수
	strcpy(file_date,inode_head->mkdate);
	inode_head = calloc(1,sizeof(inode));//inode 처음으로 할당하는 것임
	inode_head->number_inode = root -> number_directory;// inode에 1저장하기
	inode_head -> filetype = root -> directory_filetype;// inode에 filetype 'd' 저장하기
	root_helper = root; //root디렉토리에서 평행적인 디렉토리들을 연결리스트로 만들것임
	root_inhelper = root;//root디렉토리에서 수직적인 디렉토리들을 연결리스트로 만들것임
	while(1)
	{
		printf("[%s]$ ",root->directory_name);
		scanf("%s",buffer);
		getchar();
		comlen = strlen(buffer);// '\0'을 제외한 문자의 개수를 comlen에 저장
		if(strcmp(buffer,"byebye") == 0)// exit가 입력되면 강제로 나옴
			exit(1);
		buffer[20] = 0;//버퍼를 비우기위해서
		printf("\n");

	}
	return 0;
}
