#include <stdio.h>
#include <math.h>

int main()
{
	//������� 
	int n=0;
	scanf("%d",&n);
	//��������ֱ��ʾ���ֺ���λ�ͣ� 
	int x[1000]={0};
	int y[1000]={0};
	//t��s���ڽ������� 
	int t=0;
	int s=0;
	//�������ֺͼ�����λ�� 
	for(int i=0;i<=n-1;i++)
	{
		scanf("%d",&x[i]);
		//r���ڼ�����λ�� 
		int r=0;
		r=x[i];
		//������λ�ͣ� 
		for(int j=1;r!=0;j++)
		{
			y[i]=y[i]+r%10;
			r=r/10;
		}
	}
	//�������� 
	for(int i=0;i<=n-1;i++)
	{
		//ÿһ��jѭ������һ���������� 
		for(int j=0;j<=n-i-2;j++)
		{
			if(y[j]<y[j+1])
			{
				//�������������ע�����ֺ���λ��Ҫͬʱ���� 
				t=y[j];
				s=x[j];
				y[j]=y[j+1];
				x[j]=x[j+1];
				y[j+1]=t;
				x[j+1]=s;
			}
			//��Ŀ����Ҫ�� 
			if(y[j]==y[j+1])
			{
				if(x[j]>=x[j+1])
		    	{
					t=y[j];
					s=x[j];
					y[j]=y[j+1];
					x[j]=x[j+1];
					y[j+1]=t;
					x[j+1]=s;
		    	}
			}
		}
	}
	//������ 
	for(int i=0;i<=n-1;i++)
	{
		printf("%d %d\n",x[i],y[i]);
	}
	return 0;
}
