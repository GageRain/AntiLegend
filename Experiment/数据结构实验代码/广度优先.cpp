#include <stdio.h>
#include <stdlib.h>
typedef struct QNode{
	int data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

LinkQueue initQueue(LinkQueue Q);
LinkQueue EnQueue(LinkQueue Q,int data);
LinkQueue DeQueue(LinkQueue Q);

int main()
{
	LinkQueue Q;
	Q=initQueue(Q);
	int n=0;
	int i=0,j=0,k=0,count=0,top=0;
	int graph[100][100]={0},visited[100]={0};
	scanf("%d",&n);
	
	for(i=0;i<n;i++) visited[i]=1;//�Ա��������г�ʼ��
	for(i=0;i<n;i++)//��������ͼ�ڽӾ��� 
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	
	
	for(i=0;i<n;i++)
	{
		top = i;
		if(visited[i])
		{
			visited[top]=0;//������㣬�ѷ���
			for(k=0;k<n;k++) graph[k][top]=0;//�ѷ��ʵĽ������ 
			Q=EnQueue(Q,top);
			count++;
			
			while(Q.front!=Q.rear)//���в��� 
			{
				top = Q.front->next->data;
				Q=DeQueue(Q);
				
				while(1)//���������ڽӵ�
				{
					j=0;
					while(graph[top][j]!=1&&j<n)
					{
						j++;//Ѱ�ҵ�һ��δ�����ʵĽ��
					}
		
					if(graph[top][j])//��δ���ʵ��ڽӵ� 
					{
						Q=EnQueue(Q,j);
						visited[j]=0;//������㣬�ѷ���
						for(k=0;k<n;k++) graph[k][j]=0;//�ѷ��ʵĽ������ 
					}
					else//�ڽӵ�ȫ�����ʹ�
					{
						break;
					}
				}
			}
			
		}
	}
	
	printf("\n%d",count);
	return 0;
}

LinkQueue initQueue(LinkQueue Q)
{
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	Q.front->next=NULL;
	Q.rear->next=NULL;
	return Q;
}

LinkQueue EnQueue(LinkQueue Q,int data)
{
	QueuePtr p=NULL;
	p = (QueuePtr)malloc(sizeof(QNode));
	p->data=data,p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return Q;
}

LinkQueue DeQueue(LinkQueue Q)
{
	int data=0;
	QueuePtr p;
	p=Q.front->next;
	data=p->data;
	printf("%d ",data+1);
	Q.front->next=p->next;
	if(Q.rear==p) Q.rear=Q.front;
	free(p);
	return Q;
}
