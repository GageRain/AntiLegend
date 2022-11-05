#include <stdio.h>

/*
   ����һ�����ڵ������գ�1900��֮������ڣ� ���������ڼ������ռ�Ϊ0
   
   ��Ŀ������ 
     ����Ҫ��2013��2��4�������ڼ����Ϳ���1900��2013��䣬���˶��ٸ�ƽ�ꡢ���ٸ����꣬
     ��Ϊƽ����365�죬��365��1��mod7��������ÿ��һ��ƽ�꣬ͬ�������������ȥ�꣬��������+1��ͬ��ÿ��һ�����꣬��������+2��
     �������Ǵ�ʱֻ��Ҫ���1900��2��4�������ڼ���Ȼ�����ǰ��ƽ��������ۼƵ����ֺ�ģ7����
     ���ݲ������ϣ���֪1900��1��1��������һ���Դ�Ϊ��׼���м���
     
   ע����ʵ�������ڼ���һЩ�̶��Ĺ�ʽ��������ʦ���ã����Ծ���ô���� 
*/

// �ж���ƽ�껹�����꣬�����ƽ���򷵻�1������������򷵻�2
int identifyYear(int year)
{
    if((year%4==0 && year%100!=0) || year%400==0) return 2;  // ����
    else return 1;                                           // ƽ��
}

// �����1900�굽ָ�����year֮�䣬ƽ��+1������+2���ۼƵĺ�
int getSumYear(int year) // year >= 1900
{
    int sum = 0;
    for(int i = 1901; i<=year; i++)
    {
        sum += identifyYear(i);
    }
    return sum;
}

int main()
{
    int year=0, month=0, day=0, weekday=0;  
    scanf("%d %d %d",&year,&month,&day);
    
    // ����1900��1��1��������һ�����ȼ����1900���month��day�������ڼ�����ʱ������ģ7��
    // ��������Ϊ��ʱ��ʦҪ���������飬����������������ܶ� 
    if(month==1) weekday = day;
    else if(month==2) weekday = day+31;
    else if(month==3) weekday = day+31+28;
    else if(month==4) weekday = day+31+28+31;
    else if(month==5) weekday = day+31+28+31+30;
    else if(month==6) weekday = day+31+28+31+30+31;
    else if(month==7) weekday = day+31+28+31+30+31+30;
    else if(month==8) weekday = day+31+28+31+30+31+30+31;
    else if(month==9) weekday = day+31+28+31+30+31+30+31+31;
    else if(month==10) weekday = day+31+28+31+30+31+30+31+31+30;
    else if(month==11) weekday = day+31+28+31+30+31+30+31+31+30+31;
    else if(month==12) weekday = day+31+28+31+30+31+30+31+31+30+31+30;

    // Ȼ���ټ����1900�굽ָ�����year֮�䣬ƽ��+1������+2���ۼƵĺͣ���������������������
    weekday += getSumYear(year);

    // ���ģ7�����Ƕ�Ӧ��������
    weekday %= 7;

    printf("%d", weekday);

    return 0;
}
