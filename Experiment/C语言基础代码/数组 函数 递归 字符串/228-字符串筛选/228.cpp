#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	//�����ַ����飬�������ַ��� 
	char x[100]={0};
	scanf("%s",x);
	
	//����ѭ������i 
	int i=0;
	
	//�����ַ������� 
	int n=strlen(x);
	
	//����������ַ� 
	for(i=0;i<=n;i=i+2)
	{
		printf("%c",x[i]);
	}
	
	return 0;
}
