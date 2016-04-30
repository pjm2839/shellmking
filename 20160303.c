#include<Stdio.h>
int main(void)
{
	int order=0,A=1,B=2,C=3,sum,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
	int num1,num2,num3,num4,num5,num6,num7,num8,num9,num10,num11,num12,num13,num14,num15,num16,num17,num18,num19,num20,num21,num22,num23,num24,num25,num26;
	// 1번째
	printf(" %d번째 프레임 %d 번째 처리 핀 수 : ", ++order,A);
	scanf ("%d" , & num1);
	if (num1 < 10) 	
	{
	printf(" ****현재까지의 점수  : %d \n" , num1);
		printf(" %d번째 프레임 %d 번째 처리 핀 수 : ", order,B);
	    scanf ("%d" , & num2);}
	else
	num2=0 ;	
	sum = num1+num2;
	printf(" ****현재까지의 점수  : %d \n" , sum);
    a=num1+num2;	
	// 2번째
	printf(" %d번째 프레임 %d 번째 처리 핀 수 : ", ++order,A);
	scanf ("%d" , & num3);
			if (num1==10)// 1프레임에서 스트라이크 일때
			sum=sum+num3;
		 if ((num1 != 10) && (a==10))// 1프레임에서 스페어 일때
			sum=sum+num3;
if (num3 ==10)
	sum=sum+num3;
	if (num3 < 10) 	
	{
		;
		sum= sum+num3;
		;
	printf(" ****현재까지의 점수  : %d \n" , sum);
		printf(" %d번째 프레임 %d 번째 처리 핀 수 : ", order,B);
	    scanf ("%d" , & num4); 
	}
	else
	num4=0;
		if (num1 ==10 && num3 !=10)
			sum= sum+num4;
	sum=sum+num4;
	printf(" ****현재까지의 점수  : %d \n" , sum);
	b=num3+num4;
	// 3번째
	printf(" %d번째 프레임 %d 번째 처리 핀 수 : ", ++order,A);
	scanf ("%d" , & num5);
	if(num1==10 && num3==10)
		sum=sum+num5;
		if (num3==10)
		sum=sum+num5;
		if (num3 != 10 && b == 10)
			sum=sum+num5;
if (num5 == 10)
	sum=sum+num5;
	if (num5 < 10) 	
	{
		sum=sum+num5;
	printf(" ****현재까지의 점수  : %d \n" , sum);
		printf(" %d번째 프레임 %d 번째 처리 핀 수 : ", order,B);
	    scanf ("%d" , & num6);}
	else
	num6=0 ;	
		if (num3==10 && num5 != 10)
			sum= sum+num6;
	sum = sum+num6;
	printf(" ****현재까지의 점수  : %d \n" , sum);
	c=num5+num6;
	// 4번째
	printf(" %d번째 프레임 %d 번째 처리 핀 수 : ", ++order,A);
	scanf ("%d" , & num7);
	if(num3==10 && num5==10)
		sum=sum+num7;
		if (num5 == 10)
			sum= sum+num7;
		if (num5 != 10 && c == 10)
			sum=sum+num7;
if (num7 == 10)
	sum=sum+num7;
	if (num7 < 10) 	
	{
		sum=sum+num7;
	printf(" ****현재까지의 점수  : %d \n" , sum);
		printf(" %d번째 프레임 %d 번째 처리 핀 수 : ", order,B);
	    scanf ("%d" , & num8);}
	else
	num8=0 ;	
	sum = sum+num8;
	printf(" ****현재까지의 점수  : %d \n" , sum);
	d=num7+num8;
	// 5번째
	printf(" %d번째 프레임 %d 번째 처리 핀 수 : ", ++order,A);
	scanf ("%d" , & num9);
	if(num5==10 && num7==10)
		sum=sum+num9;
		if (num7 == 10)
			sum= sum+num9;
		if (num7!=10 && d==10)
			sum=sum+num5;
if (num9 == 10)
	sum=sum+num9;
	if (num9 < 10) 	
	{
		sum=sum+num9;
	printf(" ****현재까지의 점수  : %d \n" , sum);
		printf(" %d번째 프레임 %d 번째 처리 핀 수 : ", order,B);
	    mcanf ("%d" , & num10);}
	else
	num10=0 ;	
		if (num7==10 && num9 != 10)
			sum= sum+num10;
	sum = sum+num10;
	printf(" ****현재까지의 점수  : %d \n" , sum);
	e=num9+num10;
	// 6번째
	printf(" %d번째 프레임 %d 번째 처리 핀 수 : ", ++order,A);
	scanf ("%d" , & num11);
	if(num7==10 && num9==10)
		sum=sum+num11;
		if (num9 == 10)
			sum= sum+num11;
		if (num9 != 10 && e == 10)
			sum=sum+num5;
if (num11 == 10)
	sum=sum+num11;
	if (num11 < 10) 	
	{
		sum=sum+num11;
	printf(" ****현재까지의 점수  : %d \n" , sum);
		printf(" %d번째 프레임 %d 번째 처리 핀 수 : ", order,B);
	    scanf ("%d" , & num12);}
	else
	num12=0 ;	
		if (num9==10 && num11 != 10)
			sum= sum+num12;
	sum = sum+num12;
	printf(" ****현재까지의 점수  : %d \n" , sum);
	f=num11+num12;
	// 7번째
	printf(" %d번째 프레임 %d 번째 처리 핀 수 : ", ++order,A);
	scanf ("%d" , & num13);
	if(num9==10 && num11==10)
		sum=sum+num13;
		if (num11==10)
			sum= sum+num13;
		if (num11 != 10 && f==10)
			sum=sum+num13;
if (num13 == 10)
	sum=sum+num13;
	if (num13 < 10) 	
	{
		sum=sum+num13;
	printf(" ****현재까지의 점수  : %d \n" , sum);
		printf(" %d번째 프레임 %d 번째 처리 핀 수 : ", order,B);
	    scanf ("%d" , & num14);}
	else
	num14=0 ;	
		if (num11==10 && num13 != 10)
			sum= sum+num14;
	sum = sum+num14;
	printf(" ****현재까지의 점수  : %d \n" , sum);
	g=num13+num14;
	// 8번째
	printf(" %d번째 프레임 %d 번째 처리 핀 수 : ", ++order,A);
	scanf ("%d" , & num15);
	if(num11==10 && num13==10)
		sum=sum+num15;
		if (num13==10)
			sum= sum+num15;
	    if (num13 !=10 && g==10)
			sum=sum+num15;
if (num15==10)
	sum=sum+num15;
	if (num15 < 10) 	
	{
		sum=sum+num15;
	printf(" ****현재까지의 점수  : %d \n" , sum);
		printf(" %d번째 프레임 %d 번째 처리 핀 수 : ", order,B);
	    scanf ("%d" , & num16);}
	else
	num16=0 ;	
		if (num13==10 && num15 != 10)
			sum= sum+num16;
	sum = sum+num16;
	printf(" ****현재까지의 점수  : %d \n" , sum);
	h=num15+num16;
	// 9번째
	printf(" %d번째 프레임 %d 번째 처리 핀 수 : ", ++order,A);
	scanf ("%d" , & num17);
	if(num13==10 && num15==10)
		sum=sum+num17;
		if (num15==10)
			sum= sum+num17;
		if (h==10 && num15!=10)
			sum=sum+num15;
if (num17==10)
	sum=sum+num17;
	if (num17 < 10) 	
	{
		sum=sum+num17;
	printf(" ****현재까지의 점수  : %d \n" , sum);
		printf(" %d번째 프레임 %d 번째 처리 핀 수 : ", order,B);
	    scanf ("%d" , & num18);}
	else
	num18=0 ;	
		if (num15==10 && num17 != 10)
			sum= sum+num18;
	sum = sum+num18;
	printf(" ****현재까지의 점수  : %d \n" , sum);
	i=num17+num18;
	//10번재
	printf(" %d번째 프레임 %d 번째 처리 핀 수 : ", ++order ,A);
	scanf ("%d", &num19);
	sum= sum+num19;
	if(num15==10 && num17==10)
		sum=sum+num19;
		if (num17==10)
			sum= sum+num19;
		if (num11 != 10 && i==10)
			sum=sum+num19;
	printf("****현재까지의 점수 : %d \n", sum);
	//10-2번째
	printf(" %d번째 프레임 %d 번째 처리 핀 수 : ", order ,B);
	    scanf ("%d" , & num20);
	sum = sum + num20;
	if(num17==10 && num19==10)
		sum=sum+num20;
	printf(" ****현재까지의 점수  : %d \n" , sum);
if (num19 ==10 || num20 == 10)	
{
	//10-3번째
	printf(" %d번째 프레임 %d 번째 처리 핀 수 : ", order ,C);
	scanf ("%d", &num21);
	sum= sum+num21;
}
	printf("****최종휙득 점수 : %d \n", sum);
	return 0;
}
