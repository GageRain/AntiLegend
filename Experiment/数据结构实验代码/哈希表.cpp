#include <stdio.h>

int main()
{
	int p=0,m=0,i=0,j=0,len=0,t=0;
	int input[100]={0},hxtable[100]={0};
	scanf("%d %d",&m,&p);

	for(j=0;j<100;j++)//�ȳ�ʼ����Ϊ-1��δʹ�� 
	{
		hxtable[j]=-1;
	}
	
	while(1)
	{
		scanf("%d",&input[i]);
		if(input[i]==-1)
		{
			break;
		}
		for(t=0,j=0;input[i]!=hxtable[j]&&t<len;j++)//�����йؼ����в��� 
		{
			if(hxtable[j]!=-1)//��Ԫ������1 
			{
				t++;
			}
		}
		
		if(t==len)//����ͬ�ؼ��� 
		{
			if(len==m-1)//�����˳� 
			{
				printf("Table full\n");
				break;
			}
			j=input[i]%p;//�ӵ�һ�����ܲ���λ�ÿ�ʼѰ�� 
			while(hxtable[j]!=-1)
			{
				j=(j+1)%m;
			}
			hxtable[j]=input[i];
			printf("%d\n",j);
			len++;
		}
		else//����ͬ�ؼ��ʣ����λ�� 
		{
			printf("%d\n",j);
		}
		i++;
	}
	return 0;
}
