#include <iostream>

using namespace std;

int hsort(int a[],int i);//����ѡ����������С�ģ����ڵ�һλ������ԭ��Ԫ��λ�����佻��,���ر�����Ԫ��λ�� 
int t=1;
 
int main()
{
	int i=0,j=0,temp=0,last=100000;
	int n=0,a[100]={0},flag=0;
	cin>>n;
	flag=n;
	
	for(i=1;i<=n;i++)//0��δ�� 
	{
		cin>>a[i];
	}
	
	while(t!=0)//���ѭ������ 
	{
		t=0;
		if(n%2==0)//��һ��Ҷ��n,���丸���������Ҷ�ӣ������һ���ӦΪ�Һ���
		{
			if(a[n]<a[n/2])//��������,������Ƚϼ��� 
			{
				temp=a[n],a[n]=a[n/2],a[n/2]=temp;
			}
			flag=n-1;
		}
		
		for(i=flag;i>2;i=i-2)//�Ӻ���ǰ,ÿ���ƶ���λ
		{
			last=hsort(a,i);//�������Ƚ�������
		}
	}
	
	for(i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	
	return 0;
}

int hsort(int a[],int i)
{
	int temp=0;
	int x=a[i],y=a[i-1],z=a[(i-1)/2];
	if(z<=x&&z<=y)//���ж�����Ԫ���Ƿ�����С���ѣ������򷵻�0
	{
		return 0;
	}
	else//����������ʣ������Ԫ���н�С��һ������,���ر�������λ�� 
	{
		t++;
		if(y>x)//�Һ��Ӹ�С 
		{
			temp=a[(i-1)/2],a[(i-1)/2]=a[i],a[i]=temp;
			return i;
		}
		else//���Ӹ�С 
		{
			temp=a[(i-1)/2],a[(i-1)/2]=a[i-1],a[i-1]=temp;
			return i-1;
		}
	}
}
