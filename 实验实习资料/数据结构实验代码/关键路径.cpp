#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int i=0,j=0,t=0,n=0,a[100][100]={0},temp=0;
	int max[100]={0};//��������ÿ��������翪ʼʱ��
	int indegree[100]={0},count=0,visit[100]={0};
	stack<int> s;
	
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
			if(a[i][j])//����� 
			{
				indegree[j]++;
			}
		}
		visit[i]=1;
	}
	//��������˼�룬ʹ��ջ�������Ϊ��ĵ���ջ����ջʱ����ָ
	//������翪ʼʱ��Ϊ����󳤶�
	for(i=0;i<n;i++)
	{
		if(!indegree[i])//�Ƚ����Ϊ��ĵ���ջ 
		{
			s.push(i);
			visit[i]=0,count++;
		}
	}
	
	while(!s.empty())
	{
		t=s.top();//��ջǰ��¼ջ��������ָ������ȼ�һ���жϼ�һ���Ƿ����Ϊ��
		s.pop();
		for(i=0;i<n;i++)
		{
			if(visit[i]&&a[t][i])
			{	
				indegree[i]--;
				temp=a[t][i]+max[t];
				if(temp>max[i])
				{
					max[i]=temp;
				}
				if(!indegree[i])
				{
					s.push(i);
					visit[i]=0,count++;
				}
				a[t][i]=0;
			}
		}
	}
	if(count!=n)
	{
		cout<<"NO";
	}
	else
	{
		for(temp=max[0],i=0;i<n;i++)
		{
			if(max[i]>temp)
			{
				temp=max[i];
			}
		}
		cout<<temp<<endl;
	}
	return 0;
}
