#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
	��N��ƽ������ͨ����ʽ�ĵ������������Ƽ��㣺
	            	NG = 0.5*(LG + N*1.0/LG)
	ʽ��NG��ʾ��һ�εĲ²�ֵ��LG��ʾ��һ�β²�ֵ����һ�β²�ֵΪ1.0��LG��ʼֵ����
	��дһ����������������������ƽ��������дmain����������������д����ƽ����������
	
	��һ�β²�ֵ����LG�ĳ�ʼֵ���������ù�ʽ����NG�����NG��LG�Ĳ�ֵ���������β²�ֵ�Ƿ񼸺���ȡ�
	����ǣ�NG����Ϊƽ�������������µĲ²�ֵNG�����ϴεĲ²�LG���ظ��������̣�ֱ��NG��LG֮��С��0.005��
	�������ݣ�4��120.5��88��36.01��10 000��0.25��
*/

double fun(int N, double LG){
	double NG, del;
	NG = 0.0;
	del = fabs(NG-LG);
	
	while(del >= 0.005){
		NG = 0.5*(LG + N*1.0/LG);
		del = fabs(NG-LG);
		LG = NG;
	}
	
	return NG;
}

int main(){
	int N;
	double LG = 1.0;
	scanf("%d", &N);
	printf("%.2lf", fun(N, LG));
	return 0;
}
