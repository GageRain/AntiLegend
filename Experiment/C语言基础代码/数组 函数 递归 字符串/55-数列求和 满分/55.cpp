#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//���ַ��ӷ�ĸ�������������ͬ���ĵ��ƣ�ֻ��ǰ���ͬ����˿��Զ�����������ĺ���������� 

int main()
{
	//��������������n 
	int n=0;
	scanf("%d",&n);
	
	//��������  
	double sum=0;
	
	//�ֱ������������ 
	int Fib1(int n);
	int Fib2(int n);
	
	int i=0; 
	for(i=1;i<=n;i++){
	//�������������������a�ͷ�ĸb 
	int a=Fib1(i);
	int b=Fib2(i);
	double x=(double)a/(double)b;
	sum+=x;
	}
	
	
	printf("%.2lf",sum);
	return 0; 
}

int Fib1(int n)
{
	if(n==1)
	{
		return(2);
	}
	else if(n==2)
	{
		return(3);
	}
	else
	{
		return(Fib1(n-1)+Fib1(n-2));
	}
}

int Fib2(int n)
{
	if(n==1)
	{
		return(1);
	}
	else if(n==2)
	{
		return(2);
	}
	else
	{
		return(Fib2(n-1)+Fib2(n-2));
	}
}
