#include<stdio.h>
int main()
{
	int i ,j;
	float score, sum, ave;
	for (i = 1;i <= 3;i++)
	{
		sum = 0;
		printf("������һ��ѧ���ĳɼ�\n");
		for (j = 1;j <= 4;j++)
		{
			scanf("%f" ,&score);
			sum += score;
		}
		ave = sum / 4;
		printf("��%dλͬѧ��ƽ���ɼ�Ϊ��%f", i, ave);
	}
	return 0;
}

