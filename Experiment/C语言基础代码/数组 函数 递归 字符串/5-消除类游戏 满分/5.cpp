#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	//��������n������m 
	int n=0;
	int m=0;
	scanf("%d %d",&n,&m);
	
	//aϵ���м�¼����bϵ�������ڱ���Ƿ�����ͬ������ 
	int a[100][100]={0};
	int b[100][100]={0};
	int i=0;
	int j=0;
	
	//������� 
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=m-1;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	//�ж�ÿ���Ƿ��п�������������,����b���еĶ�Ӧ����Ϊ1 
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=m-3;j++)
		{
			if(a[i][j]==a[i][j+1]&&a[i][j+1]==a[i][j+2])
			{
				b[i][j]=1;
				b[i][j+1]=1;
				b[i][j+2]=1;
			}
		}
	} 
	
	//�ж�ÿ���Ƿ��п������������� 
	for(j=0;j<=m-1;j++)
	{
		for(i=0;i<=n-3;i++)
		{
			if(a[i][j]==a[i+1][j]&&a[i][j]==a[i+2][j])
			{
				b[i][j]=1;
				b[i+1][j]=1;
				b[i+2][j]=1;
			}
		}
	} 	
	
	//��ʼ����  
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=m-1;j++)
		{
			if(b[i][j]==1)
			{
				a[i][j]=0;
			}
		}
	}
	
	//���������ľ��� 
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=m-1;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
