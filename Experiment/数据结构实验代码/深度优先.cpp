#include<stdio.h>
void DFS(int graph[100][100],int visited[100],int top);

int n=0;//ȫ�ֱ��� 

int main()
{
	int i=0,j=0,count=0,top=0;
	int graph[100][100]={0},visited[100]={0};
	scanf("%d",&n);
	
	for(i=0;i<n;i++) visited[i]=1;//�Ա��������г�ʼ��
	for(i=0;i<n;i++) 
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	 
	for(i=0;visited[i]!=0||i<n;i++)
	{
		if(visited[i]!=0) count++; 
		top=i;
		DFS(graph,visited,top);
	}
	printf("\n%d",count);
	return 0;
}

void DFS(int graph[100][100],int visited[100],int top)
{
	int i=0,temp=top;
	while(visited[top])
	{
		visited[top]=0;//������㣬�ѷ���
		printf("%d ",top+1);
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
				top=i;
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
