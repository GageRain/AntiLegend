#include<stdio.h>
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

void DFS(int graph[100][100],int visited[100],int top);

int n=0,m=0,order[10]={0},side[100][2]={0},number=0;//ȫ�ֱ�����mΪorder��������numberΪside������ 

int main()
{
	int i=0,j=0,k=0,count=0,top=0;
	int graph[100][100]={0},visited[100]={0};
	int choice=0;//ѡ����Ȼ������ȱ���
	
	printf("�������ڽӾ���ά����\n");
	scanf("%d",&n);
	
	printf("�������ڽӾ���\n");
	for(i=0;i<n;i++) visited[i]=1;//�Ա��������г�ʼ��
	for(i=0;i<n;i++)//�����ڽӾ��� 
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	
	printf("�����������ʽ��1Ϊ������ȣ�2Ϊ������ȣ�\n");
	scanf("%d",&choice);//ѡ�������ʽ 
	
	if(choice == 1)//������� 
	{
		for(i=0;visited[i]!=0||i<n;i++)
		{
			if(visited[i]!=0) count++;//�����ͨ��֧�� 
			top=i;
			DFS(graph,visited,top);
		}
	}
	
	else//������� 
	{
		LinkQueue Q;//�������в���ʼ�� 
		Q=initQueue(Q);
		
		for(i=0;i<n;i++)
		{
			top = i;
			if(visited[i])
			{
				visited[top]=0;//������㣬�ѷ���
				for(k=0;k<n;k++) graph[k][top]=0;//�ѷ��ʵĽ������ 
				Q=EnQueue(Q,top);
				count++;//�����ͨ��֧�� 
				
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
							side[number][0]=top,side[number][1]=j,number++;
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
	}
	printf("\n�����ͨ��֧�� ��\n%d",count);//�����ͨ��֧�� 
	printf("\n�������˳��\n ");
	for(i=0;i<n;i++)
	{
		printf("%d ",order[i]);
	}
	
	printf("\n����߼���\n ");
	if(number)//�б� 
	{
		for(i=0;i<number;i++)
		{
			printf("(%d,%d) ",side[i][0]+1,side[i][1]+1);
		}
	}
	else//ȫΪ������
	{
		printf("ȫΪ������");	
	} 
	return 0;
}

void DFS(int graph[100][100],int visited[100],int top)
{
	int i=0,temp=top,num=0;
	while(visited[top])
	{
		visited[top]=0;//������㣬�ѷ���
		order[m]=top+1,m++;
		for(i=0;i<n;i++) graph[i][top]=0;//�ѷ��ʵĽ������ 
		
		while(1)//���������ڽӵ�
		{
			i=0;
			while(graph[top][i]!=1&&i<n)
			{
				i++;//Ѱ�ҵ�һ��δ�����ʵĽ��
			}

			if(graph[top][i])//��δ���ʵ��ڽӵ� 
			{
				num++;
				side[number][0]=top,side[number][1]=i,number++;//��¼�����ڽӵ�  
				top=i;//��¼��һ��� 
				DFS(graph,visited,top);
				top=temp;
			}
			else//�ڽӵ�ȫ�����ʹ�
			{
				break;
			}
		}
	}
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
	order[m]=data+1,m++;//��¼���
	Q.front->next=p->next;
	if(Q.rear==p) Q.rear=Q.front;
	free(p);
	return Q;
}
