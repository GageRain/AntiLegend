#include<stdio.h>
#include<stdlib.h>
typedef struct linklist//�������� 
{
	int value;//��ֵ 
	int index;
	struct linklist *next;//ָ����һ����� 
}*LinkList;

LinkList InitList(LinkList L)//��ʼ������
{
    L = (LinkList)malloc(sizeof(LinkList));//ͷ���
	L->value = 0;
	L->index = 0;
	L->next =NULL;
	return L;
}

int main()
{
	//ʹ������������в���
	LinkList L1,L2,p,q,r,s;
	L1=InitList(L1);//ͷָ�� 
	L2=InitList(L2);

	int m=0,n=0,i=0,method=0,value=0,index=0;
	scanf("%d %d %d",&m,&n,&method);
	
	p=L1;
	for(i=0;i<m;i++)//�Ե�һ������������� 
	{
		r=(LinkList)malloc(sizeof(LinkList));//����һ���µĽ��
		scanf("%d %d",&value,&index);
		if(value == 0)
		{
			continue;
		}
		r->value = value;
		r->index = index;
		p->next = r;
		p = p->next;
		p->next = NULL;
	}
	
	q=L2;
	for(i=0;i<n;i++)//�Եڶ�������������� 
	{
		r=(LinkList)malloc(sizeof(LinkList));//����һ���µĽ��
		scanf("%d %d",&value,&index);
		if(value == 0)
		{
			continue;
		}
		if(method == 0)
		{
			r->value = value;
		}
		else
		{
			r->value = -value;
		}
		r->index = index;
		q->next = r;
		q = q->next;
		q->next = NULL;
	}
	
	p=L1->next,q=L2->next,r=L1,s=L1;
	while(p&&q)//�������� 
	{
		if(p->index < q->index)//����һ�Ĵ���С 
		{
			p = p->next,r = r->next;
		}
		
		else if(p->index == q->index)//������� 
		{
			p->value=p->value + q->value;
			if(p->value != 0)
			{
				r = r->next;
			}
			else//ϵ��Ϊ��ɾ����� 
			{
				s=p;
				r->next=p->next;
			}
			p=p->next,q = q->next;
		}
		
		else//����һ�Ĵ�����,���Ԫ�ز��뵽��һ���ǰ 
		{
			s=q;
			q=q->next;
			r->next=s,r=r->next,s->next=p;
		}
	}
	
	while(q)//�����������ȫ������ 
	{
		r->next=q;
		q = q->next;
	}
	
	p= L1->next,value = 1;
	
	if(p==NULL)
	{
		printf("0");
	}
	while(p)
	{
		if(1 != value&&p->value>0)//���ǵ�һ�����������������+
		{
			printf("+");
		}
		else if(1 == value)
		{
			value = 0;
		}
		
		if(p->value == 1 && p->index == 0)
		{
			printf("1");
		}
		else if(p->value == -1 && p->index == 0)
		{
			printf("-1");
		}
		
		else if(p->value !=1&&p->value !=-1)//��-1��1�������� 
		{
			printf("%d",p->value);
		}
		else if(p->value ==-1)
		{
			printf("-");
		}
		
		if(p->index !=0)
		{
			printf("x");
			if(p->index !=1)//�Դ����������� 
			{
				printf("^%d",p->index);
			}
		}
		
		p=p->next;
	}
	printf("\n");

	return 0;
}
