#include <iostream>
#include <queue>
#include <list>

using namespace std;

int main()
{
	static int a[1000][1000]={0};
	int i=0,j=0,num=0;
	int n=0,m=0,t=0;
	int t1=0,t2=0;//���Ա�ʾ���������� 
	queue<int> q;
	int visit[1000]={0};
	cin>>n>>m;
	for(i=0;i<m;i++)//������������ͨ��֧���� 
	{
		cin>>t1>>t2;
		a[t1-1][t2-1]=1;
		a[t2-1][t1-1]=1;
	}
	for(i=0;i<n;i++)
	{
		visit[i]=1;
	}
	
	while(1)
	{
		if(q.empty())//����Ϊ������ 
		{
			i=0;
			while(!visit[i]&&i<n)//���һ��δ���ʹ��ĵ�
			{
				i++;
			}
			if(visit[i])//δ������ 
			{
				num++;
				q.push(i);
				visit[i]=0;
			}
			else//��ȫ���ʹ� 
			{
				break;
			}
		}
		else//����������������ڽӵ������ 
		{
			t=q.front();
			q.pop();
			for(i=0;i<n;i++)
			{
				if(visit[i]&&a[i][t])
				{
					visit[i]=0;
					q.push(i);
				}
			}
		}
	}
	cout<<num-1;
	return 0;
} 
