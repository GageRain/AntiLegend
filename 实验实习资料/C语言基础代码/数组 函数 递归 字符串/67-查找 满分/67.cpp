#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int main()
{
	//��������������n�Ͳ�������k
	int n=0;
	int k=0;
	scanf("%d %d",&n,&k);
	
	//������ʶ����m
	int m=0; 
	
	//������ѭ���������飬������Ƿ����k����������������i ,ͬʱm��һ 
	int a[1000]={0};
	int i=0;
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==k)
		{
			printf("%d ",i);
			m+=1;
		}
	} 
	
	//���⣺��û��������k��Ҳ��m=0�������-1 
	if(m==0) 
	{
		printf("-1");
	} 
	
	return 0;	
}
