#include"project.h"


int main(void)
{char buffer[20];//명령어 임시 받는 버퍼
	char b;//명령어의 문자 하나씩 받으려고
	int comlen;//명령어 길이
	char name[5];//파일 이름의 최대 길이가 4바이트니까 + 널문자= 5바이트
	while(1)
	{
		printf("[%s]",tree->directory_name);
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
