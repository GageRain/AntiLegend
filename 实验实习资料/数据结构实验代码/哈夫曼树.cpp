#include <stdio.h>
#include <stdlib.h>

typedef  struct
{  int w;
   int par,lch,rch;
   int code[10];//���� 
   int level;//���� 
}HufNode,*HufTree;

int s1=0,s2=0;//Ȩֵ��С���ڵ� 

void Select(HufTree HT,int x);

int main()
{
    int i=0,j=0,k=0;
	int n=0,val=0,sum=0,t=0;

	scanf("%d",&n);//Ҷ���� 
	HufTree HT;
	HT=(HufTree)malloc((2*n)*sizeof(HufNode));//0�ŵ�Ԫδ��,HT[2*n-1]��ʾ���ڵ� 
	for(i=1;i<2*n;i++)//��ʼ�� 
	{
		HT[i].lch=HT[i].rch=HT[i].par=HT[i].w=0;
		HT[i].code[0]=0,HT[i].level=0;
	}
	
	for(i=1;i<1+n;i++)//0��δ�� 
	{
		scanf("%d",&val);
		HT[i].w=val;
	}
	for(i=n+1;i<2*n;i++)
	{
		Select(HT,i-1);//ѡ����С�������޸��ڵ�Ľ�� 
		HT[s1].par=i;HT[s2].par=i;
		HT[i].lch=s1;HT[i].rch=s2;
		HT[i].w=HT[s1].w+HT[s2].w;
	}
	
	for(i=1;i<n+1;i++)//������Ȩֵ�����롢���ڲ��� 
	{
		j=i;
		while(HT[j].par)
		{
			t=j,j=HT[j].par;//tΪǰһ����� 
			if(HT[j].lch==t)//����,����Ϊ0 
			{
				HT[i].code[HT[i].level]=0;
			}
			else//�Һ��ӣ�����Ϊ1 
			{
				HT[i].code[HT[i].level]=1;
			}
			HT[i].level++;//����һ��
		}
		sum=sum+HT[i].level*(HT[i].w);
	}
	if(n==1) printf("��һ�㣬·��Ϊ100\n");
	else
	{
		printf("��Ȩ·��Ϊ%d\n",sum);
		for(i=1;i<n+1;i++)
		{
			printf("%d����Ϊ:%d		��Ӧ����Ϊ:",HT[i].w,HT[i].level);
			for(j=HT[i].level-1;j>-1;j--)
			{
				printf("%d ",HT[i].code[j]);
			}
			printf("\n");
		}
		
	}
	return 0;
}

void Select(HufTree HT,int x)
{
//ѡ���޸���㣬����Ȩֵ��С��������㣬��ֵ��s1��s2 
	int i,min1=100000,min2=100000;
	for(i=1;i<=x;i++)
	{//����С 
		if(HT[i].w<min1&&HT[i].par==0)
		{
			min1=HT[i].w;
			s1=i;
		}
	}
	for(i=1;i<=x;i++)
	{//�Ҵ�С 
		if(HT[i].w<min2&&i!=s1&&HT[i].par==0)
		{
			min2=HT[i].w;
			s2=i;
		}
	}
}

