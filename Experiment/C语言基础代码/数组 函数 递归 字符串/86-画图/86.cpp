#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
	
	//�������������ͱ��� 
	int num[100][100]={0};
	int sum=0;
	int n,i,j,k;
	int s[100][4]={0};
	//����nֵ 
    scanf("%d", &n);
    
    //ѭ����������s 
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 4; j++)
			scanf("%d",&s[i][j]);
	}
    //��1��ʾ��ɫ ��������ʾ��ɫ 
	for (i = 0; i < n; i++)
	{
        for (j =s[i][0]; j < s[i][2]; j++)
		{
			for (k = s[i][1]; k < s[i][3]; k++)
				num[j][k] = 1;
		}
	}
	
	//����ͼ�ε����
	for (i = 0,sum=0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			sum += num[i][j];
		}
	}

	printf("%d", sum);
}
