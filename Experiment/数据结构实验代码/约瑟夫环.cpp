#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct linklist//�������� 
{
	int value;//���� 
	int num;//��� 
	struct linklist *next;//ָ����һ�����
}*LinkList;

LinkList InitList(LinkList L)//��ʼ������
{
    L = (LinkList)malloc(sizeof(LinkList));//ͷ���
	L->value=0;
	L->next =NULL;
	return L;
}

int main()
{
	LinkList L,p,q,r,s;
	int n=0,i=0,j=0,value=0,secret=0;
	L=InitList(L);//ͷָ�� 
	p=L;
	scanf("%d %d",&n,&secret);
	for(i=1;i<=n;i++)//������������� 
	{
		r=InitList(r);//����һ���µĽ��
		scanf("%d",&value);
		r->value = value,r->num=i;
		p->next = r;
		p = p->next;
		p->next = NULL;
	}
	
	q=p,p->next=L->next,p=p->next;
	while(q!=p)
	{
		secret=secret%n;
		if(secret==0) secret = secret+n;
		for(i=0;i<secret-1;i++)p=p->next,q=q->next;
		secret = p->value;
		printf("%d ",p->num);
		q->next =p->next,p=q->next; 
		n--;
	}
	printf("%d\n",p->num);
	return 0;
}
