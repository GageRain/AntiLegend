#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
	
	char a[100]={0};

	//����ѭ������i,j�Լ���������t 
	int i=0;
	int j=0;
	int t=0;
	
	scanf("%s",a);
		
	int n=strlen(a);

	
	//���� 
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-2;j++)
		{
			if(a[j]>=a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}

	printf("%s",a);

	return 0;
	
}
