#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
	��д���򣬽�һ���ַ������е������ַ�ƴ�ӳ�һ���������������ָ���������9�������������������ƽ���������磬��������ַ�����Ϊ��aj?3v87.y=:61w!0]#���������387610��622.58��
	
	����˵���� �����ֵ��ַ����� (ASCII�룺48����57�� 

	���˵���� ���е����� �������ֵ�ƽ����(С�������λ)
*/

int main(){
	
	char str[99] = {'\0'};
	gets(str);
	
	int num[99] = {0};
	long long int number = 0;
	
	int i=0, j=0, mark=0;
	int k=0;
	
	for(i = 0; str[i] != '\0'; i++){
		k = (int)(str[i] - '0');
		if(k<=9 && k >0 && mark ==0){
			num[j] = k;
			mark = 1;
			j++;
		} else if(k<=9 && k>=0 && mark == 1){
			num[j] = k;
			j++;
		}
	}
	
	for(i=j-1; i>=0; i--){
		number = number + (long long int)pow(10,j-1-i)*num[i];
	}
	
	for(i=0; i<=j-1; i++){
		printf("%d", num[i]);
	}
	
	printf("\n%.2lf", sqrt((double)number));
	
	return 0;
	
}
