
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





//superblock_inode write 함수
// 매개변수 position은 superblock_r로부터 값을 받아와야 쓸 수 있음
int superblock_write(int position){
unsigned int a[16]={0};// inode리스트 사용유무를 알기위한 a는 4바이트이므로 비트로 따지면 8*4=32 32비트를 담을 수 있음, 32*16=512이므로 inode를 다 담을 수 있을 크기
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



//superblock_inode delete 함수
// 매개변수 position은 superblock_r로부터 값을 받아와야 쓸 수 있음
int superblock_write(int position){
unsigned int a[16]={0};// inode리스트 사용유무를 알기위한 a는 4바이트이므로 비트로 따지면 8*4=32 32비트를 담을 수 있음, 32*16=512이므로 inode를 다 담을 수 있을 크기
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

//superblock_read datablock함수
int superblock_r(){
	int index_find=0;//16개의 인덱스를 다 읽어야 해서
	unsigned int b[16]={0};//데이터블록 사용유무를 알기위한 b는 "
	unsigned int c= 2147483648;
	int position_data=0;

	printf("슈퍼블록사용여부 표시 \n"); 	
	for(;index_find<16;index_find++)
	{	 
		while(c>=1)
		{
			if(b[index_find] & c)
				printf("1");
			else
				printf("0");
			c >>=1; // 1칸씩 뒤로 넘겨서 차례대로 읽기위해서
			++position_data;
		}
		printf("  ");
		c= 2147483648;//2145483684는 10000000 00000000 00000000 00000000임
	}
return position;
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


