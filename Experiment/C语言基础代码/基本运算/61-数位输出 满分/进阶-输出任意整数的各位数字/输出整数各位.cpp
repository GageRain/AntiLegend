#include <stdio.h>

/*
    ����һ���Ǹ���������������������ĸ�λ���֣��ո���
*/


// ����һ������i������10^����λ����һλ���򷵻�1, ��λ���򷵻�10,��λ������100��
int identifyDigit(int i)
{
    int temp = i, digit = 1;
    while(temp > 9)
    {
        digit *= 10;
        temp /= 10;
    }
    return digit;
}

// ִ��main���� 
int main()
{
    int num = 0;
    scanf("%d", &num);
    int digit = identifyDigit(num);
    while(num != 0)
    {  
        printf("%d ", num/digit);
        num %= digit;
        digit /= 10;
    }
    
    return 0;
}
