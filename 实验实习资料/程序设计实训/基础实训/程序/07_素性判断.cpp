#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// ��дһ�������ж������һ�������Ƿ�Ϊ������

int main(){
	int n, i, flag;
	scanf("%d",&n);
	flag = 0;
	if(n<=1) printf("��������"); 
	for(i=1; i<=n; i++){
		if(n%i == 0) ++flag;
	}
	
	if(flag == 2){
		printf("������");
		return 0;
	}
	
	printf("��������"); 
	
	return 0; 
}
