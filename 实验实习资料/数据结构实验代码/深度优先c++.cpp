#include <iostream>

using namespace std;

void DFS(int visit[],int a[100][100],int t);
int n=0;

int main()
{
	int a[100][100]={0};
	int i=0,j=0,t=0;
	int visit[100]={0};
	int m=0;//mΪ��ͨ��������
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
		visit[i]=1;
	}
	while(1)//�ݹ�
	{
		i=0;
		while(i<n&&!visit[i])//Ѱ�ҵ�һ��δ�����ʹ��ĵ� 
		{
			i++;
		}
		if(visit[i])//�н��Ϊ������ 
		{
			m++;
			visit[i]=0;
			cout<<i+1<<" ";
			DFS(visit,a,i);
		}
		else
		{
			break;
		}
	}
	cout<<"\n"<<m;
	return 0;
}

void DFS(int visit[],int a[100][100],int t)
{
	int i=0,j=0;
	while(1)//��������������ڽӵ����η��� 
	{
		for(i=0;i<n;i++)
		{
			if(a[i][t]&&visit[i])//�н��Ϊ������ 
			{
				visit[i]=0;
				cout<<i+1<<" ";
				DFS(visit,a,i);
			}
		}
		if(i==n)//���ڽӵ� 
		{
			break;
		}
	}
}
