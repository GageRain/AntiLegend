#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	//�������������n 
	int n=0;
	scanf("%d",&n);
	
	//������ѭ������n������ 
	int a[1000]={0};
	int i=0;
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&a[i]);
	} 
	
	//����ѭ������j�ͽ����м���t 
	int j=0;
	int t=0;
	
	//ȷ��ż��/�ϴ�����ǰ������/��С���ں� 
	for(i=0;i<=n+1;i++)
	{
		for(j=0;j<=n-2;j++)
		{
			if(a[j]%2!=0&&a[j+1]%2==0)
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
			if((a[j]+a[j+1])%2==0&&a[j]<a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	
	
	
	//ѭ��������������� 
	for(i=0;i<=n-1;i++)
	{
		printf("%d ",a[i]);
	}
	
	return 0;
}
