#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// ��°ͺղ���ĸ�����֤ 

// �ж�n�Ƿ��������������򷵻�1�����򷵻�0 
int IsPriNum(int n){
	// ��С��1�����Ȼ�������� 
	if(n <= 1) return 0;
	
	// flag���n�������ĸ�������n>1��flag=2�����Ϊ���� 
	int flag = 0, i = 1;
	for(i=1; i<=n; i++){
		if(n%i == 0) flag++;
	}
	if(flag == 2) return 1;
	return 0;
}

// ����һ��ż��n�����n = a + b(����a��bΪ����)�����ж��ֿ��ܣ������b-a����ֵ��С��һ�� 
void GolCon(int n){
	int i = n/2;
	int j = 0;
	for(i=n/2; i>0; i--){
		if(IsPriNum(n-i) && IsPriNum(i)){
			printf("%d %d", i, n-i);	
			break;
		} 
	}
}

// ��Ϊʾ����main���� 
int main(){
	int n = 0;
	scanf("%d", &n);
	GolCon(n);
	
	return 0;
}
