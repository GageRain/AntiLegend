#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	//�������������n
	int n=0;
	scanf("%d",&n); 
	
	//tΪ�м���������ڽ������� 
	int t=0;

	//�������� 
	//a[i]����������Ҫ������ 
	
	int a[1000]={0};
	
	//b[i]���ڴ���a[i]�еķ��ظ���������� 
	
	int b[1000]={0};
	
	//c[i]���ڼ�¼����b[i]��ÿһ����ֵĴ��� 
	
	int c[1000]={0};
	
	//i,jΪѭ������
	 
	int i=0;
	
	int j=0;
	
	//k���ڼ�¼b[i]����������0�ʼ�� 
	int k=0;
	
	//�������� a[i]
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&a[i]);
	} 
	
	//��������,��a���鰴�մ�С�������򣬱��ڼ����ȵ����� 
	for(i=0;i<=n-1;i++)
	{
		for(j=1;j<=n-1;j++)
		{
			if(a[j]<a[j-1])
			{
				t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
		}
	}
	
	//��ʼ��b[i],c[i],k 
	b[0]=a[0];
	k=0;
	c[0]=1;
	
	//��ʼ��¼b[i]��c[i]��ͬʱ���k 
	 
	for(i=1;i<=n-1;i++)
	{
		if(a[i]==a[i-1])
		{
			c[k]+=1;
		}
		else
		{
			k=k+1;
			b[k]=a[i]; 
			c[k]=c[k]+1;
		}
	}
	
	//������ 
	for(i=0;i<=k;i++)
	{
		printf("%d:%d\n",b[i],c[i]);
	}
	return 0;
}
