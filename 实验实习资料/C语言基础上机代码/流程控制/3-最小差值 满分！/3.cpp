#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
#include<string.h>

int main()
{
	//aΪ������ֵ�ĸ��� 
	int a=0;

	scanf("%d",&a);
	//x����Ϊ���������y����Ϊ����Ĳ�ֵ 
	int x[1000]={0};
	int y[1000]={0};
	//i��j����ѭ�� 
	int i=1;
	int j=1;
	//k���ڼ�¼��С��ֵ 
	int k=0;
	//������Сֵ���� 
	int min(int m,int n);
	
	//��ʼѭ������x�����ں�����y����k 
	for(i=0;i<=a-1;i++)
	{

		scanf ("%d",&x[i]);
	}
	//����k�ĳ�ʼֵ�����ں����Ƚ� 
	k=x[0]-x[1];
	//ȷ��kΪ�Ǹ�ֵ 
	if(k<0)
	{
		k=-k;
	}
	//ѭ�����ÿһ����ֵ�����Ƚϵó�����ֵ��С�Ĳ� 
	for(i=0;i<=a-1;i++)
	{
		for(j=0;j<=a-1;j++)
		{
			if(j>=1&&j!=i)
			{
				//��ÿһ��iѭ���У�x[i]�ǹ̶��ģ����ϱ仯x[j]�Ӷ����ÿһ����x[i]����Ĳ�ֵ 
				y[j]=x[i]-x[j];
				
				//ȷ����ֵ�Ǹ� 
				if(y[j]<0)
				{
					y[j]=-y[j];
				}
				//����һ��Ĳ�ֵ����һ���ֵ�Ƚϣ�����ȡ��Сֵ 
			k=min(k,y[j]);
			}
		}
	}
	//�����С��ֵ 
	printf("%d",k);
	return 0;
}

//����min��Сֵ���� 
int min(int m,int n)
{
	int min=0;
	if(m<=n)
	{
		min=m;
	}
	else
	{
		min=n;
	}
	return(min);
}


