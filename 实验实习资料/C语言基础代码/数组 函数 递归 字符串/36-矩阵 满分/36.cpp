#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	//�����������У��У���m 
	int m=0;
	scanf("%d",&m);
	
	//t�������򽻻����� 
	int t=0;
	
	//a[i][j]Ϊ����ľ��� 
	int a[100][100]={0};
	
	//b[i]Ϊ��ĺ�ֵ 
	int b[1000]={0};
	
	//����ѭ������ 
	int i,j,k;
	
	//������� 
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	//��ÿ�еĺͣ�������b[i]��1����m�� 
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=m;j++)
		{
			b[i]+=a[i][j];
		}
	}
	
	//��ÿ�еĺͣ�������b[i]��m+1����2*m�� 
		for(i=1;i<=m;i++)
	{
		for(j=1;j<=m;j++)
		{
			b[i+m]+=a[j][i];
		}
	}
	
	//�������Խ��ߺ͸��Խ���֮�ͣ�������b[i]��2*m+1��2*m+2�� 
	for(i=1;i<=m;i++)
	{
		b[2*m+1]+=a[i][i];
	}
	for(i=1;i<=m;i++)
	{
		b[2*m+2]+=a[i][m-i+1];
	}
	
	//�������� 
	for(i=1;i<=2*m+1;i++)
	{
		for(j=1;j<=2*m+1;j++)
		{
			if(b[j]<b[j+1])
			{
				t=b[j];
				b[j]=b[j+1];
				b[j+1]=t;
			}
		}
	}
	
	//��������ע��ո� 
		for(i=1;i<=2*m+2;i++)
	{
		printf("%d ",b[i]);
	}
	
	return 0;
	
}
