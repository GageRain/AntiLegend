#include<stdio.h>
int main()
{
	int n=0,i=0,j=0,tmp=0;//tmp��ʾ��ʱ���� 
	int num[100]={0};
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	//�������������������Ľ������������
	//��ֱ��������������� 
	
	for(i=0;i<n;i++)//ð������ 
	{
		for(j=0;j<n-1;j++)
		{
			if(num[j]>num[j+1])//��С�������� 
			{
				tmp=num[j],num[j]=num[j+1],num[j+1]=tmp;//�������� 
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d ",num[i]);//ֱ����� 
	}
	return 0;
}
