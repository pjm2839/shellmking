#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(void)
{char buffer[20];//명령어 임시 받는 버퍼
	char b;//명령어의 문자 하나씩 받으려고
	int comlen;//명령어 길이
	while(1)
	{
		printf("[/]$ ");
		scanf("%s",buffer);
		getchar();
		comlen = strlen(buffer);// '\0'을 제외한 문자의 개수를 comlen에 저장
		if(strcmp(buffer,"byebye") == 0)// exit가 입력되면 강제로 나옴 ,byebye			
			return -1;
		buffer[20] = 0;//버퍼를 비우기위해서
		printf("\n");

	}
	return 0;
}
