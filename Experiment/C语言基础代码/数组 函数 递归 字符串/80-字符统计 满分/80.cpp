#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
	//����������c,n 
	char c=0;
	int n=0;
	scanf("%c %d",&c,&n);
	
	//num���ڱ���ַ�c������ 
	int num=0;	
	
	//�����ַ��� 
	char x[100]={'\0'};
	scanf("%s",x);
	
	//��¼�ַ������� 
	int len=strlen(x);
	
	//����ѭ������i 
	int i=0;
	
	//��ʼɨ�裬����ע�����ִ�Сд�Ƿ����� 
	for(i=0;i<=len-1;i++)
	{
		if(n==1)
		{
			if(x[i]==c)
			{
				num+=1;
			}
		}
		else if(n==0)
		{
			if(c>=65&&c<=90)
			{
				if(x[i]==c||x[i]==c+32)
				{
					num+=1;
				}				
			}
			else if(c>=97&&c<=122)
			{
				if(x[i]==c||x[i]==c-32)
				{
					num+=1;
				}				
			}
		}
	}
	
	//������ 
	printf("%d",num);
	return 0;
}
