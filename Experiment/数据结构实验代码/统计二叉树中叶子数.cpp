#include<stdio.h>
int main()
{
	char s[1000],ch;
	scanf("%c",&ch);
	int i=1,j=0,t,count=0;
	//���ڵ�t�㣬��i����㣬������������2^t-2^(t-1)+i��2^t-2^(t-1)+i+1λ
	
	for(i=1;i<1000;i++) //ȫ��ֵΪ@ 
	{
		s[i]='@';//�ӵڶ��㿪ʼ��һ��� 
	}
	i=1;
	
	while(ch!='#')
	{
		s[i]=ch;//�������ַ������� 
		scanf("%c",&ch);
		i++;
	}
	
	t=i;//�ܽڵ��� 
	for(i=1;i<t;i++)
	{
		if(s[i]!='@'&&s[i*2]=='@'&&s[i*2+1]=='@')//����������������Ƿ���� 
		{
			printf("%c ",s[i]);//���Ҷ��
			count++;
		}
	}
	printf("\n%d",count);//�������
	return 0;
}
