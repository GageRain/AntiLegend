#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int a[100][100]={0};
	int visit[100]={0},t=0;
	int i=0,j=0,n=0,m=0;//m��ʾ��ͨ�����ĸ��� 
	queue<int> q;
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
		visit[i]=1;//��ʼ��������δ���ʹ� 
	}
	
	while(1)
	{
		if(q.empty())//������Ϊ��ʱ��ѯ��һ��δ���ʵĽ�㣬����������� 
		{
			for(i=0;i<n;i++)
			{
				if(visit[i]!=0)
				{
					break;
				}
			}
			
			if(visit[i])//��δ�����ʵ�Ԫ�� 
			{
				m++;//��ͨ����+1 
				q.push(i);//����� 
				visit[i]=0;
			}
			else//����Ԫ�ؾ������� 
			{
				break;
			}
		}
		
		else//���в���������ȴ�ӡȻ�����ڽӵ����������
		{
			t=q.front();
			q.pop();
			cout<<t+1<<" ";
			for(i=0;i<n;i++)
			{
				if(a[i][t]&&visit[i])
				{
					q.push(i);
					visit[i]=0;
				}
			}
		}	
	}
	cout<<"\n"<<m<<endl;
	return 0;
} 
