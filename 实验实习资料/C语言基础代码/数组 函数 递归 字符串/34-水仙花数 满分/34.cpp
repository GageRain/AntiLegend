#include <stdio.h>

//����һ�������������Ƿ���ˮ�ɻ��� 
int isFlower(int i)
{
	int flag=1; //�����ж�main��if��� 
	int ret=i;  //����i��ֵ 
	int a=0, sum=0;
		while( i>0 )
		{
			a = i%10;
			sum += a*a*a;
			i = i/10;
		} //���sum����λ�����η��Ӻ� 
		
		if ( sum != ret ) flag = 0;
	
	return flag;
}

int main ()
{	
	int a,b,num=0;
	scanf("%d %d", &a, &b); 
	for(int t=a; t<=b; t++) //t������λ��
	{ 
		if(isFlower(t)) num++;
	}
	printf("%d", num);
	return 0; 
 }

