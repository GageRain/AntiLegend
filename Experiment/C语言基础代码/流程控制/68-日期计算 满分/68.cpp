#include <stdio.h>

int main()
{
	int year, month, day;
	
	//������ݺ����� 
	scanf("%d %d",&year,&day);
	
	// �ж�ÿ���µ�������Ĭ��Ϊ�����꣬�������굥������ 
	int months[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	if(year%4==0 && year%100!=0 || year%400==0) months[1] = 28;
	
	for(month=1; month<=12; month++) 
	{
		if(day>months[month-1]) day-=months[month-1];
		else break;
	}
	printf("%d %d", month, day);
	return 0;
} 
