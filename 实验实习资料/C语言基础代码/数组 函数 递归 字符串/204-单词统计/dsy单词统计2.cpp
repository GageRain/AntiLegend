/*
����3���ַ���������ĸ���ո�ͱ����ţ�ͳ�������ж��ٵ��ʣ�����֮��������һ���ո�ָ��� 
*/ 



#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

//�ж�������ַ�temp�ǲ���Ӣ����ĸ 
int isZiMu(char temp)
{
	if(
		temp>='a' && temp<='z'   ||   //��Сд��ĸ ���� 
		temp>='A' && temp<='Z'        //�Ǵ�д��ĸ 
		)
	{
		return 1;    //����ĸ���򷵻�1 
	}
	else
	{
		return 0;	//������ĸ������0�� 
	}
}

//�����ַ���str�а����ĵ��ʸ��� 
int danCiGeShu(char str[]) 
{
	//����ַ����ĳ��� 
	int length=strlen(str);   
	
	//����ַ����ĳ���Ϊ0���򷵻����а����ĵ��ʸ���Ϊ0 
	if(length==0)
	{
		return 0;
	}
	
	int count=0;
	
	int i=0;	
	
	//���ַ����е������ַ�����ɨ�裬��ͳ�Ƶ��ʸ�����
	while(i<length)	
	{
		//�жϳ���һ���µ��ʵ�����Ϊ����ǰ�ַ�Ϊ��ĸ������һ���ַ�������ĸ 
		if( 
			isZiMu(str[i])==1  &&  //��ǰ�ַ�Ϊ��ĸ�����ң� 
			isZiMu(str[i+1])==0    //��һ���ַ�������ĸ 
		 )
		 {
		 	count++;
		 }
		 
		 i++;
	}	
	
	return count;
	
}

int main()
{
	char ch[3][100];
	int i,j=0,n,word=0;	
	
	//���������ַ��� 
	gets(ch[0]);
	gets(ch[1]);
	gets(ch[2]);	
	
	//�ú�������3���ַ����������������е��ʵĸ����� 
	word=danCiGeShu(ch[0])+danCiGeShu(ch[1])+danCiGeShu(ch[2]);
	
	printf("%d",word); 
	
	return 0;
}
