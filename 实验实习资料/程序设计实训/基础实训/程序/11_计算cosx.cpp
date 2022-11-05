#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
	���Ƴ������ø����Ľ��ƹ�ʽ����cosx�Ľ���ֵ��ֱ�����һ��ľ���ֵС��10�ĸ�6�η���
	
	����˵���� ����x
	���˵���� cosx
*/

// ����׳˵ĺ���
int Factorial(int n){
	if(n == 0) return 1;
	int i = 1;
	int factorial = 1;
	for(i=1; i<=n; i++){
		factorial = factorial*i;
	}
	return factorial;
} 

// ����cosx�ĺ��� ��Ҫ�õ�Factorial������ 
double Cosine(double x){ 
	int i = 2; // i���ڼ���i�Ľ׳˺�x��i�η� 
	double t = 1.00; // t���ڱ�ʾÿһ���ֵ 
	double f = -1.00; // f����ֵ���䣬�����Ա仯������ʵ��������� 
	double cosx = 1.00; // cosx������ֵ 
	while(fabs(t) >= 1e-6){
		t = f*pow(x, i)/Factorial(i);
		f = f*(-1);
		cosx = cosx + t;
		i = i+2;
	}
	
	return cosx;
}

int main(){
	double x = 0.00;
	scanf("%lf", &x);
	
	printf("%lf", Cosine(x));
	return 0;
}
