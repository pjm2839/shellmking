typedef struct directory{//inode에만 1이 됨 데이터블록에는 1없음. 왜냐하면 디렉토리는 0바이트임
directory_name[5];
struct file_name *start,*q;
int usuage = 0;//starter가 가리키는 곳에는 파일의 이름이 있다. 그런데 그곳에 이름이 있으면 usuage는 1을 표시하는 것이고 안 사용하면 1은 0으로 다시 바꿀것임
}directory;

directory *root; 

typedef struct file_name{
	char file_nm[5];
	struct file_name *next;
	int usuage_2=0;
}file_name;
int mk_struct_directory = 0;//기본 초기화는 0임 mkfs했을때는 1로 바뀌면서 설정해서 만들어지게 하는 것임
if(mk_struct_directory == 1)
{	root = (directory *)calloc(1,sizeof(directory));
	mk_struct_directory = -1;
}
if(mk_struct_directory == -1)
	printf("root디렉토리를 없애버리실 수 없습니다.\n"); 
strcpy(root->directory_name,"/");
void happen_file_first(){
	root->q = (file_name *)malloc(sizeof(file_name));
	root->q ->next = NULL;
	strcpy(root->q->file_nm,file_namae);
	root->starter=root->q;
	root->usuage = 1;
};
void happen_file_(){//연결리스트인데 좀 많이 복잡할 수 있을 것임......  
	root->q->usuage_2 =1;
	root->q->next = (file_name*)malloc(sizeof(file_name));
	root->q=root->q->next;//q는 주소를 next로 해서 이미 옮겼음
	root->q->next= NULL;
strcpy(root->q->file_nm,file_namae)//namae도 후에 통일화 시킬것임
}
file_name thisgroup;//구조체로 thisgroup을 만들었음
dir.starter = &thisgroup;//디렉토리 구조체가 file_name형의 thisgroup을 포인터하고 있음

