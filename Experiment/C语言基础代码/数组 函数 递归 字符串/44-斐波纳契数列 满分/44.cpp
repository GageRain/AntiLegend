#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	//��������n 
	int n=0;
	scanf("%d",&n);
	
	//����쳲��������еĺ��� 
	int Fib(int n);
	
	//�����n��쳲�������������n��1��ʼ�� 
	int m=Fib(n);
	int i=0;
	
	//1��������Ҳ���Ǻ������������� 
	if(m==1)
	{
		printf("%d",m);
		return 0;
	}
	
	//�ж��Ƿ�Ϊ���� 
	for(i=2;i<m;i++)
	{
		if(m%i==0&&m!=2)
		{
			printf("%d",m);
			return 0;
		}

	}
	printf("yes");
	
	return 0;
}

//����쳲��������еĺ��� 
int Fib(int n)
{
	//��һ��͵ڶ���Ϊ��Ϊ�涨���������� 
	if(n==1)
	{
		return(1);
	}
	else if(n==2)
	{
		return(1);
	}
	else
	{
		return(Fib(n-1)+Fib(n-2));
	}
}
