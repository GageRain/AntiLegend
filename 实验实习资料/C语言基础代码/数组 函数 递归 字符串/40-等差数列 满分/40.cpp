#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
	//�������������n��������������a
	int n=0;
	scanf("%d",&n);
	int a[100]={0};
	
	//����ѭ������i,j�Լ���������t 
	int i=0;
	int j=0;
	int t=0;
	
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&a[i]);
	} 
	
	//���� 
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-2;j++)
		{
			if(a[j]<=a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	
	//�ж��Ƿ���Թ��ɵȲ����� 
	for(i=0;i<=n-3;i++)
	{
		if(a[i]-a[i+1]!=a[i+1]-a[i+2])
		{
			printf("no");
			return 0;
		}
	}
	
	//������� 
	int p=a[0]-a[1];
	printf("%d",p);
	return 0;
}
