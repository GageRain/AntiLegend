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
	for(int t=100; t<=999; t++) //t������λ��
	{ 
		if(isFlower(t)) printf("%d\n",t);
	}
	return 0; 
 }

