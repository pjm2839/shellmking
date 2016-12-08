
#include<string.h>//strcmp가 있어야 가능함
char filename[5],filename_new[5];//cpfrom할때 filename에서 새로운 이름으로 받을 filename _new
char tmp[128];
char storage[1024][128];
int filesize,numblock,numblock_remain,check;//check는 fread로 받을때 다 받아서 완전히 없으면 0이 리턴되는 것을 받으려고 함 while문 돌릴때
FILE *ofp,*ifp;
int block_case=0;// 1이면 다이렉트블록 2이면 싱글인다이렉트 3이면 더블 인다이렉트로
char direct[128];//다이렉트블록임
int i;//i는 data블록사용유무를 슈퍼블록에서 읽어오고나서 사용할 수 있으면 그 위치를 받아옴
if((ofp = fopen(filename,"rb")) == NULL)
printf("파일을 여는데 오류가 발생되었습니다.");

if((ifp = fopen(filename_new,"wb")) == NULL)
printf("파일을 쓰는데 오류가 발생되었습니다.");
int k=0;//싱글인다이렉트블록만들때 쓰려고 


fseek(ofp,0,SEEK_END);//파일 사이즈를 알려고 맨 뒤로 가는것임
filesize=ftell(ofp);// 파일 사이즈를 알게됨
rewind(ofp);//파일포인터를 맨 앞으로 옮기려고
if(filesize>128)
{
	if((filesize%128) != 0) 
		numblock= filesize/128+1;
	else
		numblock = filesize/128;
}
else numblock =1;// 128바이트도 안되면 그냥 다이렉트로 해야하니까 box 즉 block은 1개이다.


printf("총 필요한 데이터블록은 %d 이다. ",box);
if(numblock>102 && numblock<102*102) 
	block_case = 3;//double indirect block으로
else if(box	> 1)	
	block_case = 2;//single indirect block으로
	else
	block_case =1;	//direct block으로

if(block_case == 1)
{
	fread(&tmp,sizeof(tmp),1,ofp);//tmp에서 128바이트 읽어옴
	fwrite(&tmp,sizeof(tmp),1,&storage[i]);
	// i는 저장소에서 위 데이터블록의 위치인데 이것을 inode에 보내줘야함

}
	else if(block_case == 2)
while(check)
{
	check= fread(&tmp,sizeof(tmp),1,ofp);
	fwrite(&tmp,sizeof(tmp),1,&storage[i]);
	//inode에 i의 값(위치)를 보내줘야함,다시 i가 슈퍼블록에서 찾아와야함
}
else if(block_case == 3)
	while(check)
{
	check= fread(&tmp,sizeof(tmp),1,ofp);
	fwrite(&tmp,sizeof(tmp),1,&storage[i]);
	//inode에 i의 값(위치)를 보내줘야함,다시 i가 슈퍼블록에서 찾아와야함
}



typedef	struct direct_block{
	int order;//블록 순서
	char storage[];
}direct_block;
direct_block *direct_head;
direct_head = (direct_block *)malloc(sizeof(direct_block));

