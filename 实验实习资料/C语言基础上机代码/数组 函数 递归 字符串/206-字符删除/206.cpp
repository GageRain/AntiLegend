#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
	
	//�����ַ����ַ����� 
	char s=0;
	char x[101]={0};

	//�����Ӧ���ַ������ַ��� 
	gets(x);
	s=getchar();
	
	//����ѭ������ 
	int i=0;
	int t=0;
	
	for(i=0,t=0;x[i]!='\0';i++)
	{
		if(x[i]!=s)
		{
			x[t]=x[i];
			t++;
		}
	}
	x[t]='\0';
	
	printf("%s",x);
	return 0;
} 
