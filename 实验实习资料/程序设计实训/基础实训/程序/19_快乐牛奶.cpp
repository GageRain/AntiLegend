#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// ������Ŀ���������ţ�������չ�ָ��ţ�̵���ͼ۸� 

int main(){
	int N=0, M=0, price=0, num=0;
	scanf("%d %d", &N, &M);
	int P[5000] = {0}; // �۸� 
	int A[5000] = {0}; // ���� 
	
	int i=0;
	for(i=0;i<=M-1;i++){
		scanf("%d %d", &P[i], &A[i]);
	}
	
	// BubbleSorting
	int j = 0, t = 0;
	i = 0;
	// ð������:������aΪ�����׼��������a��b����ͬ����Ϊһ��ͬʱ���� 
	for(i=0;i<=M-1;i++){
		for(j=0;j<=M-2;j++){
			if(P[j]>P[j+1]){
				t = P[j];
				P[j] = P[j+1];
				P[j+1] = t;
				t = A[j];
				A[j] = A[j+1];
				A[j+1] = t;
			}
		}
	}
	
	for(i=0; i<=M-1; i++){
		if(num+A[i] < N){
			num += A[i];
			price += P[i]*A[i];
		}
		
		if(num+A[i] >= N){
			price += P[i]*(N-num);
			num = N;
			break;
		}
	} 
	
	printf("%d", price);
	
	return 0;
}

 
