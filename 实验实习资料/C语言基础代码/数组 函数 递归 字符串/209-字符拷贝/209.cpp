#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	//�����ַ����飬�����ַ��� 
	char x[101]={'\0'};
	char y[101]={'\0'};
	gets(x);
	
	int n=0;
	scanf("%d",&n);
	
	//ѭ������ 
	int i=0;
	int j=0;
	
	int p=n+1;
	
	if(x[p]==32)
	{
		p++;
	}
	for(j=0,i=p;x[i]!='\0';j++,i++)
	{
		y[j]=x[i];
	}
	
	//������ 
	printf("%s",y);
	return 0;
} 
