#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// ��ŵ������ 

// �����ʽ ��P-->Q����ʾ��P���ƶ���Q�� 
void Move(char c1, char c2){
	printf("%c-->%c\n", c1, c2);
}

// ��ŵ������ĵݹ��㷨����ʾ��a����n�������ƶ���c���� 
void Hanoi(int n, char a, char b, char c)
{
	// ��ֻ��һ�����ӣ�ֱ�Ӵ�a�ƶ���c 
	if(n==1) Move(a,c); 
	
	else{
		// �ݹ飺��a����n-1��Բ���ƶ���b���ӣ�����Բ�̲����� 
		Hanoi(n-1, a, c, b); 
		// ������һ��Բ�̴�a���Ƶ�c��
		Move(a, c); 
		// �ݹ飺��b����n-1��Բ���Ƶ�c��
		Hanoi(n-1, b, a, c);  
	}
}
int main()
{
	// �������������ӵĸ���
	int num;
	scanf("%d",&num); 
	// �ݹ鲢������ 
	Hanoi(num,'A','B','C');
	return 0;
}
