#include <stdio.h>

int main(){
	//��������array������Ԫ�ظ���Ϊ700/11����63 
	int array[700/11]; 
	//��������num 
	int num = 0;
	
	//����ѭ������i��j 
	int i = 1; 
	int j = 0; 
	
	//forѭ������1��700���ֱ��ж�ÿ�����Ƿ���11�ı�����������������array�У����򲻲��� 
	for(i=1; i<=700; i++){
		if(i%11 == 0) array[num++] = i;
	} 
	
	//�������Ԫ�� 
	for(j=0; j<=num-1; j++){
		printf("%d ",array[j]);
	}
	
	return 0;
}
