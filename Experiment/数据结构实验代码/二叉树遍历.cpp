#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Bit
{
	char ch;
	struct Bit *lch,*rch;//���Һ���ָ��	
}Bitnode,*Bitree;

Bitree CreatBit(Bitree t,char fir[],char mid[],int start,int end,int root);
int f=0;

int main()
{
	Bitree T;
	int start=0,end=0,root=0;
	char mid[30],fir[30];
	scanf("%s",&fir);
	scanf("%s",&mid);
	root=strlen(mid);
	end=root;
	T=CreatBit(T,fir,mid,start,end,root);
}

Bitree CreatBit(Bitree t,char fir[],char mid[],int start,int end,int root)
{
	int i=0,j=0;
	t=(Bitree)malloc(sizeof(Bitnode));
	i=start;
	while(fir[f]!=mid[i]&&i<end)//�ӵ�ǰ����������Ѱ�Ҹ�����Ϊ��ǰ�����������еĵ�һ��Ԫ��
	{
		i++;
	}//���������У������Ϊ���������Ҳ�Ϊ������
	
	if(fir[f]&&fir[f]==mid[i])//�ҵ����ڵ�
	{
		t->ch=fir[f];//���ɸ�
			
		f++;
		start=0,end=i-1;//�ӵ�ǰ����ĸ���࿪ʼ,�������Ϊֹ 
		t->lch=CreatBit(t->lch,fir,mid,start,end,i);//����������
		start=i+1,end=root;//�ӵ�ǰ����ĸ��Ҳ࿪ʼ 
		t->rch=CreatBit(t->rch,fir,mid,start,end,root);//���������� 
		printf("%c",t->ch);
	}
	else//�Ҳ�����Ϊ�� 
	{
		t=NULL;
	}
	return t;

}
