#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

int main()
{
	
	//��ʼ��ֵ�������ؼ����� 
	int a[10] = {6,15,18,27,38,45,50,80,88,95};
	
	int low , high , mid , found , n;
	
	//��ʼ���ؼ����� 
	low = 0;
	high = 9;
	found = 0;
	
	//������Ҫ���������� 
	printf("Please give the number you would like to search:\n");
	scanf("%d",&n) ;
	
	while(low<=high)
	{
		mid = (low+high)/2;
		
		//�ҵ�n������ѭ�� 
		if(a[mid] == n)
		{
			found = 1;
			break;
		}
		
		//��Ȼ����ı�˵�ֵ 
		else if(a[mid]>n)
		{
			high = mid-1;
		} 
		
		else if(a[mid]<n)
		{
			low = mid+1;
		}
		
	} 
	
	//�ҵ�������������ţ��ű�+1) 
	if(found == 1)
	{
		printf("The number you are searching is listed at number %d",mid+1);

	}
	
	//δ�ҵ�����������"Not existed�� 
	else
	{
		printf("Not existed");
	}
	
	return 0;
} 
