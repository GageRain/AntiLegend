#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdio.h"

int main()
{
	//a�Ķ����Ʊ�ʾ��11��b�Ķ����Ʊ�ʾ��1��c�Ķ����Ʊ�ʾ��10�� 
	int a = 3;
	int b = 1;
	int c = 2;
	
	//���ڷֱ�a,e,f����4λ������6λ������1λ�������Ϸֱ�����16��������64������С��1/2 
	int d = a<<4;
	int e = b<<6;
	int f = c>>1;
	
	//��������� 
	printf("%d %d %d",d,e,f);
	
	return 0; 
}
