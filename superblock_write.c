
superblock_write함수
int index_find=0;//16개의 인덱스를 다 읽어야 해서
unsigned int a[16]={0};// inode리스트 사용유무를 알기위한 a는 4바이트이므로 비트로 따지면 8*4=32 32비트를 담을 수 있음, 32*16=512이므로 inode를 다 담을 수 있을 크기
unsigned int b[16]={0};//데이터블록 사용유무를 알기위한 b는 "
unsigned int c= 2147483648;


for(;index_find<16;index_find++)
	{	 
		while(c>=1)
		{
		if(a[index_find] & c)
			;
		else
		 { 
			 a[index_find]+=c;
		   	return 0;// 비어있는 칸에 등록을 하고나서는 빠져나와야함 
		 }
		c >>=1;				// 1칸씩 뒤로 넘겨서 차례대로 읽기위해서
		}
		c= 2147483648;//2145483684는 10000000 00000000 00000000 00000000임
	}
