#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	//a[i]Ϊ����ֵ 
	int a[1000]={0};
	
	//i,j��Ϊѭ������ 
	int i=0;
	int j=0;
	
	//k���ڼ�¼��������Ϊ2 
	int k=1;
	
	//score��¼�÷֣���ʼֵΪ0 
	int score=0;
	
	//����a[i]��ͬʱ�жϵ÷ֲ���¼��ֱ������0ֹͣѭ�� 
	for(i=0;i>=0;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1)
		{
			score=score+1;
		}

		// ��a[i]==2��ʱ����Ҫ�ж�ǰ���м���Ҳ����2����ʱ������������һ��jѭ������a[i]��ǰ�ƣ�ֱ�����ֲ���2��һ��a[j]����ʱ���ε÷�Ϊ2*��i-j) 
		else if(a[i]==2)
		{
			k=1; 
			for(j=0;j>=0;j++)
			{
				if(a[i-j-1]==2&&i-j-1>=0)
				{
					k=k+1;
				}
				else
				{
					score=score+2*k;
					break;
				}
			}
		}
		else if(a[i]==0)
		{
			break;
		}
	}
	printf("%d",score);
	return 0;
}
