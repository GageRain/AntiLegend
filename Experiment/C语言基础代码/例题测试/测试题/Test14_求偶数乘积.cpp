#include <stdio.h>

int main(){
	
	//��Ŀδ��ȷ��ʾn����������ż�����ʷ��������
	
	//����������n
	int n = 0; 
	scanf("%d",&n);
	
	//����num��num��ʾС�ڵ���n�����ż�� 
	int num = 0; 
	if(n%2 == 0) num = n;
	else num = n-1;
	
	//����ѭ������i
	int i = 2;
	//�����ɼ����m 
	int m = 1;

	for(i=2; i<=num; i = i+2) {
		m = m*i;
	}
	printf("%d",m);
	
	return 0;
} 
