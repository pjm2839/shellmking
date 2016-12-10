#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

typedef struct single_indirect{
	int datablock_pos[120];
	single_number_get_inode(&datablock_pos)//함수에를 만들어서 데이터블록에서 받은 것을 pos 배열에다가 담아놓기 
}single_indirect;

typedef struct double_indirect{
	int datablock_ition[120*120];
	double_number_get_inode(&datablock_ition)
}double_indirect;
double_indirect vos;//더블인다이렉트를 사용하기위해서 설

typedef struct directory{//inode에만 1이 됨 데이터블록에는 1없음. 왜냐하면 디렉토리는 0바이트임
	char directory_name[5];
	struct file_name *start,*q;
	struct directory *indirectory,*nextdirectory = NULL;//nextdirectory는 디렉토리를 연결리스트로만들려고한것이고 indirectroy는 디렉토리 안에 디렉토리들을 잇기위해서 만든것임
	int directory_inode;
	int usuage = 0;//starter가 가리키는 곳에는 파일의 이름이 있다. 그런데 그곳에 이름이 있으면 usuage는 1을 표시하는 것이고 안 사용하면 1은 0으로 다시 바꿀것임
	int usuage_dir = 0;
	int usuage_indir =0;
}directory;

directory *root,*root_helper,*root_inhelper;//루트 포인터는 파일안에 파일들과 아이노드 담을때 쓸꺼고 inodehelper는 디렉토리를 linkedlist로 만들때 사용할 것임 
root_helper = root;
root_inhelper = root;

typedef struct file_name{
	char file_nm[5];
	int file__inode;
	struct file_name *next;
	int usuage_2=0;
}file_name;

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
inode *inode_head,*p,**double_head;//doublehead는 더블인다이렉트블록에 접근하기 위한것임, head는 inode구조체에 가장 맨 앞에 주소를 가지고 있으며 p를 움직여서 그 안에 넣어 주는 것임

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
//checktim(&a);//a는 main함수에서 그냥 26개의 인덱스를 가진 배열임 
void checktim(int koreatime[26]){
	struct tm *t;:ㅈ`
	time_t now;
	now = time(NULL);
	t = localtime(&now);
	int sec = t->tm_sec-1;
	int min = t->tm_min;
	int hour = t->tm_hour;
	int mon = t->tm_mon+1;
	int day = t->tm_mday;
	int year = t->tm_year+1900;
	sprintf(koreatime,"%d년 %d월 %d일 %d시 %d분 %d초",year,mon,mday,hour,min,sec);
}
//date_input(position_inode);으로한다.
void date_input(int inode_number){
	int mkdate[26];
	int time_align=0;
	checktim(&mkdate);//필요할때만 쓰게 함수로 따로 빼놔야겠음
	if(inode_number == -1)
		printf("inode리스트를 다 쓰고 있거나 오류가 발생했습니다.");

	inode_head=(inode *)malloc(sizeof(inode));//할당해주는 것은 다른 함수에다 만들어야함
	p=inode_head;
	p=repeating_inter_list(inode_number);//함수만든거
	strcpy(p->makdate,mkdate);
	p = inode_head;//다시 원래 head주소로 돌아옴
}


void making_linked_inode(int num_link){//필요한만큼 inode크기의 포인터로 만들어낸다.
	for(i=0;i<num_link-1;i++)
	{
		p->next = (inode *)malloc(sizeof(inode));
		p = p->next;
	}
}

inode * repeating_inter_list(int num_link){//필요한 곳 까지 들어간다.
	for(int i=0;i<num_link-1;i++)
		p = p->next;
	return p;
}

void inodelist_number_input(){//inodelist에 숫자를 넣기위한 함수
	int inode_number = superblock_r();//superblock_r()의 리턴은 position_inode이다.
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
			if(buffer[2] == 'f')
				if(buffer[3] == 'r')
					if(buffer[4] == 'o')
						if(buffer[5] == 'm')
							file_type = 'f';
	p->filetype = file_type;
}

void single_number_get_inode(int single_indirect_pos[102]){
	//datablock에서 할당받은 값을 계속 받아서
	int number_pos;
	int data_final;//마지막 데이터가 있는 위치
	int i=0;// single_indirect_pos[i]로 설정하려고
	while(1){
		number_pos = ; // 데이터블록에서 값을 받아옴
		single_indirect_pos[i] = number_pos;정
		if(number_pos == -1)
		{	
			data_final = i;
			break;
		}
		i++;
	}

}


void superblockinf(int total_iniode,int total_block,int freeblock){//슈퍼블록의 내용을 볼수 있는 함수
		int total_inode;//총 inode개수
		int inode[];// 이걸로 할까? 아니면 찾는 값이 1이면 알려주는 변수로 만들까?
		int total_block;//전체 블록의 개수
		int block[];//블록의 사용하는지 안 하는지
		int size_block;//블록의 크기
		int freeblock;//할당되지 않은 블록의 개수
}// project.h 파엘이 담아놓겠음

void double_number_get_inode(int double_indirect_pos[102*102]){
	//datablock에서 할당받은 값을 계속 받아서
	int number_pos;
	int data_final;//마지막 데이터가 있는 위치
	int i=0;// doiuble_indirect_pos[i]로 설정하려고
	while(1){
		number_pos = ; // 데이터블록에서 값을 받아옴
		double_indirect_pos[i] = number_pos;
		if(number_pos == -1)
		{	data_final = i;
			break;
		}
		i++;
	}

}


void show_double_indirect_num_find(int double_indirect_pos[120]){//호출할때  double매개변수에 인자는 &주소를 넣어줘야함
	// show_single_indirect랑 double은 사용하고 있는 인다이렉트 블록에서 데이터블록 위치정보들을 모두 출력해서 보여주는 함수이다.
	int a=0;//그냥 변수 datafile만날때 까지
	while(a != datafinal-1)
	{
		printf("%d",double_indirect_pos[a] 
				a++;
				}
				a++;
				printf("%d . " ,double_indirect_pos[a]);//데이터블록사용하는 것을 보여주는 거니까..
				}


				void show_single_indirect_num_find(int single_indirect_pos[120*102]){
				// show_single_indirect랑 double은 사용하고 있는 인다이렉트 블록에서 데이터블록 위치정보들을 모두 출력해서 보여주는 함수이다.
				int a=0;//그냥 변수 datafile만날때 까지
				while(a != datafinal-1)
				{
				printf("%d",single_indirect_pos[a] 
						a++;}
						a++;
						printf("%d . " ,single_indirect_pos[a]);//데이터블록사용하는 것을 보여주는 거니까..

						}


						void superblockinfo(){
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
						}

//superblock_read inode함수
int superblock_r(){
	int index_find=0;//16개의 인덱스를 다 읽어야 해서
	unsigned int a[16]={0};// inode리스트 사용유무를 알기위한 a는 4바이트이므로 비트로 따지면 8*4=32 32비트를 담을 수 있음, 32*16=512이므로 inode를 다 담을 수 있을 크기
	unsigned int c= 2147483648;
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

//superblock_data delete함수
// 매개변수 position은 superblock_data read로부터 값을 받아와야 쓸 수 있음
int superblock_write(int position){
	unsigned int b[16]={0};//데이터블록 사용유무를 알기위한 b는 "
	unsigned int c= 2147483648;
	int same_position;
	int index_find=0;
	for(;index_find<16;index_find++)
	{	 
		while(c>=1)
		{
			if(same_position == position)
			{ 
				a[index_find]-=c;
				return 0; 
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

//superblock_inode_show함수
void superblock_inode_show(){
	int index_find=0;//16개의 인덱스를 다 읽어야 해서
	unsigned int a[16]={0};// inode리스트 사용유무를 알기위한 a는 4바이트이므로 비트로 따지면 8*4=32 32비트를 담을 수 있음, 32*16=512이므로 inode를 다 담을 수 있을 크기
	unsigned int c= 2147483648;
	int position_inode=0;

	printf("슈퍼블록사용여부 표시 \n"); 	
	for(;index_find<16;index_find++)
	{	 
		while(c>=1)
		{
			if(a[index_find] & c)
				printf("1");
			else
				printf("0");
			c >>=1; // 1칸씩 뒤로 넘겨서 차례대로 읽기위해서
		}
		printf("  ");
		c= 2147483648;//2145483684는 10000000 00000000 00000000 00000000임
	}

}

//superblock_write datablock함수
// 매개변수 position은 superblock_data read로부터 값을 받아와야 쓸 수 있음
int superblock_write(int position){
	unsigned int b[16]={0};//데이터블록 사용유무를 알기위한 b는 "
	unsigned int c= 2147483648;
	int same_position;
	int index_find=0;
	for(;index_find<16;index_find++)
	{	 
		while(c>=1)
		{
			if(same_position == position)
			{ 
				a[index_find]+=c;
				return ;// 비어있는 칸에 등록을 하고나서는위치를 알려주면서 빠져나와야함 
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



int mk_struct_directory = 0;//기본 초기화는 0임 mkfs했을때는 1로 바뀌면서 설정해서 만들어지게 하는 것임

void making_root_directory(){
	if(mk_struct_directory == 1)
	{	root = (directory *)calloc(1,sizeof(directory));
		mk_struct_directory = -1;
	}
	if(mk_struct_directory == -1)
		printf("root디렉토리를 없애버리실 수 없습니다.\n"); 
	strcpy(root->directory_name,"/");
}


//happen_file_first 함수는 처음으로 파일을 디렉토리에 생성할때 쓰는 것이다. 
void happen_file_first(){
	root->q = (file_name *)malloc(sizeof(file_name));
	root->q ->next = NULL;
	strcpy(root->q->file_nm,file_namae);
	input_inode_in_direct(inode);//inode는 슈퍼블록에서 받아와야겠지??? input_inode함수를 첩부했음
	root->starter=root->q;
	root->usuage = 1;
}

//happen_file함수는 파일을 디렉토리에 생성할때 쓰는것이며
void happen_file_(){//연결리스트인데 좀 많이 복잡할 수 있을 것임......  
	root->q->next = (file_name*)malloc(sizeof(file_name));
	root->q->usuage_2 = 1;//할당해서 다음 next를 쓸수있음을 알려주는 것임 
	root->q=root->q->next;//q는 주소를 next로 해서 이미 옮겼음
	root->q->next= NULL;
	strcpy(root->q->file_nm,file_namae)//namae도 후에 통일화 시킬것임
		input_inode_in_direct(inode);//inode는 슈퍼블록에서 받아와야겠지???
}

void input_inode_in_direct(int inode){
	root->q->file_inode=inode;
}


void Linked_directory(){//directory linked list로 이건 평행한 디렉토리들을 연결할때 쓸꺼

	if(root_helper->usuage_dir == 0)
		root_helper->nextdirectory = (directory *)malloc(sizeof(directory));
	root_helper->usuage_dir = 1;
	root_helper= root_helper->nextdirectory;
	root_helper->nextdirectory = NULL;
}

void Linked_indirectory(){//directory linked list 이건 종속적인 디렉토리들을 연결할때 쓸꺼

	if(root_inhelper->usuage_indir == 0)
		root_inhelper -> indirectory = (directory *)malloc(sizeof(directory));
	root_inhelper -> usuage_indir =1;
	root_inhelper = root_inhelper -> indirectory;
	root_inhelper -> indirectory = NULL;
}

char * Data_block(char* filename, char* filename_new){
	char filename[5],filename_new[5];
	char tmp[128];
	char storage[1024][128]={0};
	char storage_on[1024];
	int i=0;//시그윈에선i를해놓고for문을돌려야되내f
	int filesize,numblock,numblock_remain,check;
	FILE *ofp,*ifp;
	int block_case=0;
	char direct[128];
	if((ofp = fopen(filename,"rb")) == NULL)
		printf("파일을 여는데 오류가 발생되었습니다.");

	if((ifp = fopen(filename_new,"wb")) == NULL)
		printf("파일을 쓰는데 오류가 발생되었습니다.");
	int k=0;


	fseek(ofp,0,SEEK_END);
	filesize=ftell(ofp);
	rewind(ofp);
	if(filesize>128)
	{
		if((filesize%128) != 0) 
			numblock= filesize/128+1;
		else
			numblock = filesize/128;
	}
	else numblock =1;


	printf("총 필요한 데이터블록은 %d 이다. ",box);
	if(numblock>102 && numblock<102*102) 
		block_case = 3;//double indirect block으로
	else if(box	> 1)	
		block_case = 2;//single indirect block으로
	else
		block_case =1;	//direct block으로

	if(block_case == 1)
	{       for(i=0; i<1024; i++)
		{
			if(storage_on[i]==0){
				fread(&tmp,sizeof(tmp),1,ofp);
				fwrite(&tmp,sizeof(tmp),1,&storage[i]);
				storage_on[i]=1;
				break;
			}
			;
		}

	}
	else if(block_case == 2)
		while(check)
		{       for(i=0; i<1024; i++){
										 if(storage_on[i]==0){
											 fread(&tmp,sizeof(tmp),1,ofp);
											 fwrite(&tmp,sizeof(tmp),1,&storage[i]);
											 storage_on[i]=1;
											 break;
										 }
										 ;
									 }
		}
	else if(block_case == 3)
		while(check)
		{       for(i=0; i<1024; i++)
			{
				if(storage_on[i]==0){
					fread(&tmp,sizeof(tmp),1,ofp);
					fwrite(&tmp,sizeof(tmp),1,&storage[i]);
					storage_on[i]=1;
					break;
				}
				;
			}
		}

	return storage_on; 
}
