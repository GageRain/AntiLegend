/*
	��Ŀ�����������ȡ�������е����С��ֵ������z = x > y �� x : y ��Ϊx��y�е����ֵ�� 
	
	��֮ǰ���ж�������������ϣ��򷵻�ð��֮ǰ��ֵ�����򷵻�ð�ź����ֵ 
*/

#include "stdio.h"
 
int main()
{
	//����������� 
	int a , b , z; 
	
	//��������x,y��ֵ�����ں����z��ֵ 
	int x = 1;
	int y = 0;
	
	
	//����a��b
	printf("Please give the value of a and b:\n"); 
	scanf("%d %d",&a,&b);
	
	//��Ŀ�����������a��b��С��ϵ��ֵ��z 
	z = a > b ? x : y;
	
	//����z������ֵ�����ж�a��b�Ĵ�С��ϵ 
	if(z == x)
	{
		printf("a > b");
	}
	else if(z == y)
	{
		printf("a <= b");
	}
	
	return 0;
	
	
}
