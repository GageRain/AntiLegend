#include<stdio.h>
#include<stdlib.h>
typedef struct linklist//�������� 
{
	int value;//��ֵ 
	struct linklist *next;//ָ����һ��Stack
}*LinkList;
LinkList InitList(LinkList L)//��ʼ������
{
    L = (LinkList)malloc(sizeof(LinkList));//ͷ���
	L->value = 0;
	L->next =NULL;
	return L;
}
int main()
{
	LinkList L,p,q,r,s;
	int m=0,n=0,i=0,j=0,value=0,index=0;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&n);
		L=InitList(L);//ͷָ�� 
		p=L;
		for(j=0;j<n;j++)//������������� 
		{
			r=(LinkList)malloc(sizeof(LinkList));//����һ���µĽ��
			scanf("%d",&value);
			r->value = value;
			p->next = r;
			p = p->next;
			p->next = NULL;
		}
		p=L,s=L,q=p->next;
		p->next=r,p=r;
		while(p!=q)
		{
			s=q;
			while(s->next != p)
			{
				s=s->next;
			}
			p->next=s,s->next=NULL,p=s;
		}
		while(L->next)
		{
			printf("%d ",L->next->value);
			L=L->next;
		}
		printf("\n");
	}	
	return 0;
}
