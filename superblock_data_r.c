
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
