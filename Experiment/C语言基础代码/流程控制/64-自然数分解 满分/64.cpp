#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	int n=0;
	scanf("%d",&n);
	int i=1;
	int j=1;
	
	//i����ѭ����ֱ���ҵ�����������i 
	for(i=1;;i++)
	{
		//�ж��Ƿ�������������Լ����һ��n�� 
		if(n*n==2*i-2+n)
		{
			//jѭ�������n�������������� 
			for(j=1;j<=n;j++)
			{
				printf("%d ",2*i-3+2*j);
			}
			break;
		}
	}
	return 0;
}
