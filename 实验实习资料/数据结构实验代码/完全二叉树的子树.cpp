#include <stdio.h>
#include <math.h>

int main()
{
	int i=0,j=0,n=1,m=1,node=0;
	int ln=0,rn=0;//���ҽ�� 
	int high=1,h=1;//����
	while(1)
	{
		scanf("%d %d",&m,&n);
		if(m==0&&n==0)
		{
			break;
		}
		ln=0,rn=0,high=0,h=0;
		for(i=1;2*i-1<n;i=i*2)//�õ��ܲ���
		{
			high++;
		}
		for(i=1;2*i-1<m;i=i*2)//�õ�m���ڲ���
		{
			h++;
		}
		
		rn=m;
		for(i=0;i<high-h;i++)//m���һ�������Ľ�� 
		{
			rn=rn*2+1;
		}
		ln=int(pow(2,high-h))*m;
		
		if(n<ln)//���һ�����С����ڵ��ͬһ��
		{
			node=0;
		}
		else if(rn<n)//�ҽڵ�С�����һ����� 
		{
			node=rn-ln+1;
		}
		else//����֮��
		{
			node=n-ln+1;
		}
		printf("%d\n",int(pow(2,high-h))-1+node);
	}
	return 0;
}
