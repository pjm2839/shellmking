
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


