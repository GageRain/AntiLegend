#include <stdio.h>
#include <stdlib.h>

typedef struct Bit
{
	char ch;
	struct Bit *lch,*rch;//���Һ���ָ��	
}Bitnode,*Bitree;

Bitree CreatBit(Bitree t,char ch[]);
int i=0;

int main()
{
	Bitree T;
	char ch[100];
	scanf("%s",&ch);
	
	T=CreatBit(T,ch);
}

Bitree CreatBit(Bitree t,char ch[])
{
	Bitree p;
/*	if(ch[i]=='\0')
	{
		break;
	}
	else */if(ch[i]=='#')
	{
		t=NULL;
		i++;
	}
	else
	{
		p=(Bitree)malloc(sizeof(Bitnode));
		t=p;
		t->ch=ch[i];//���ɸ�
		i++; 
		t->lch=CreatBit(t->lch,ch);//����������
		printf("%c ",t->ch);
		t->rch=CreatBit(t->rch,ch);//���������� 
	}
	return t;

}
