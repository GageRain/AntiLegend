#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

int main()
{
	
	//��������a,b,c 
	int a = 1;
	int b = 64;
	int c = 24;
	
	
	/*
	���Թ�ϵ�������ֵ���Լ���ϵ������͸�ֵ����������ȼ�
	
	�����ϣ�dΪ0��e��f��Ϊ��0����,��ϵ����������ڸ�ֵ�����
	*/
	
	int d = a > b;
	int e = a < c;
	int f = b == b; 
	
	//������������ 
	printf("%d %d %d", d , e , f );
	
	return 0; 
	 
	
	//���ʣ�������e,f��0���ɣ�Ϊʲô����1�� 
} 

