#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	//��������������n 
	int n=0;
	scanf("%d",&n);
	
	//��������sum �������ʼ��Ϊ0 
	int sum=0;
	
	//����ѭ������ 
	int i=1;
	int j=1;
	
	//��ʼ��p��p������sum�Ĺ��� 
	int p=n;
	
	//����ѭ����ֱ������sumΪ��λ����Ҳ��sum/10==0�� 
	for(i=1;i>=1;i++)
	{
	//��Ƕѭ����sum	
		for(j=1;p!=0;j++)
		{
		sum=sum+p%10;
		p=p/10;
		}
	 
	 //�ж�sum�Ƿ�Ϊ��λ���������������������³�ʼ��p��sum 
		if(sum/10!=0)
		{
			p=sum;
			sum=0;
		}
	//����������������ѭ�� 
		else
		{
			break;
		}

	}
	printf("%d",sum);
	return 0;
}
