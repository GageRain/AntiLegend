#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// ��дһ����������λ�Ŀ�����������������ָ����һ�������ĸ�λ���ֵ�˳�򵹹��������ɵķ�����Ҳ��������

int main(){
	int n = 1000;
	int m,a,b,c,d,i,flag;

	while(n<10000 && n>=1000){
 		flag = 0;
		d = n%10;
		c = (n/10)%10;
		b = (n/100)%10;
		a = (n/1000);
		
		for(i=1; i<=n; i++){
			if(n%i == 0) ++flag;
		}
		if(flag == 2){
			flag = 0;
			m = 1000*d+100*c+10*b+a;
			for(i=1; i<=m; i++){
				if(m%i == 0) ++flag;
			}
			if(flag == 2) printf("%d\n",n);
		}
		++n;
	}
	return 0;
}
