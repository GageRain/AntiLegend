#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
	����3��4��5һ�𹹳���һ��������Ԫ�飬��������Ԫ������������
	��������������m��n��m>n��һ��������Ԫ����������й�ʽ������
						side1 = m^2-n^2
						side2 = 2*m*n
						hypotenuse = m^2+n^2
	��m=2��n=1ʱ�����ݹ�ʽ�Ͳ�������Ԫ�飨side1=3��side2=4��hypotenuse=5����
	
	��дһ�����򣬽�m��n��ֵ��Ϊ���룬��ͨ������Ĺ�ʽ�������Ĺ�����Ԫ���ֵ��ʾ������
*/

int main(){
	int m,n;
	scanf("%d %d", &m, &n);
	printf("%d %d %d", m*m-n*n, 2*m*n, m*m+n*n);
	
	return 0; 
} 
