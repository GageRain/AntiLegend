#include<stdio.h>
int main()
{
	//�����ַ� 
	char a=0;
	scanf("%c",&a);
	
	//�Ƿ�Ϊ��д��ĸ�ж� 
	if(a>=65&&a<=90)
	{
		a=a+32;
	}
	
	//�Ƿ�ΪСд��ĸ�ж� 
	else if(a>=97&&a<=122)
	{
		a=a-32;
	}
	printf("%c",a);
	return 0;
}
