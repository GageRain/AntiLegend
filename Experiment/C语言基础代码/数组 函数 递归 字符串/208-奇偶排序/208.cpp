#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
	//�������������n��������������a
	int N=0;
	scanf("%d",&N);
	int a[20]={0};
	
	//����ѭ������i,j�Լ���������t 
	int i=0;
	int j=0;
	int t=0;
	
	for(i=0;i<=N-1;i++)
	{
		scanf("%d",&a[i]);
	} 
	
	//���� 
	for(i=0;i<=N-1;i++)
	{
		for(j=0;j<=N-2;j++)
		{
			if(a[j]>=a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	
		for(i=0;i<=N-1;i++)
	{
		for(j=0;j<=N-2;j++)
		{
			if(a[j]%2==0&&a[j+1]%2!=0)
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	
	for(j=0;j<=N-1;j++)
	{
		if(a[j]%2!=0&&a[j+1]%2==0)
		{
			printf("%d   ",a[j]);
		}
		else
		{
			printf("%d ",a[j]);
		}
		
	}
	
	return 0;
}
