#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// ע�⣡ ������ֻ����25�����ڵĽ׳� 

/*
	���д�������n���������Ҫ������n��ֵ��Ӧ����n<=1000��
	
	����˵���� n
	���˵���� n!
*/

// ����׳˵�ֵ  (ע�⣡long long int������� %lld�� 
int Factorial(int n){
	if(n == 0) return 1;
	long long int i;
	long long int fact = 1;
	for(i=1; i<=n; i++){
		fact = fact*i;
	}
	printf("%lld", fact);
	return 0;
} 

int main(){
	
	int n = 0;
	scanf("%d", &n);
	
	Factorial(n);
	
	return 0;
}
