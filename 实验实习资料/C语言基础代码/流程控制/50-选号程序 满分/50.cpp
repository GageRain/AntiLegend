#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

int main()
{
	int N=0;
	scanf("%d",&N);
	
	//p[i]Ϊqq�� 
	int p[1000]={0};
	
	//q[i]Ϊ��λ�� 
	int q[1000]={0};
	
	//r��������λ�� 
	int r=0;
	
	//iΪѭ������ 
	int i=0;
	
	//max��¼������λ��maxx��¼�����λ��Ӧ��qq�� 
	int max,maxx;
	
 	//Ѱ�� max��maxx 
	for(i=0;i<=N-1;i++)
	{
		scanf("%d",&p[i]);
		r=p[i];
		while(r!=0)
		{
			q[i]=q[i]+r%10;
			r=r/10;
		}
		if(i==0)
		{
			max=q[i];
			maxx=p[i];
		}
		if(i>=1&&q[i]>max)
		{
			max=q[i];
			maxx=p[i];
		}
		else if(i>=1&&q[i]==max)
		{
			if(maxx<p[i])
			{
				max=q[i];
				maxx=p[i];
			}
		}
	}
	printf("%d",maxx);
	return 0;
}
