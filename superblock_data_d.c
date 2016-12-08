
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

