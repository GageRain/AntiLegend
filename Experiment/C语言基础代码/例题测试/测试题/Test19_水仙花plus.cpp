#include <stdio.h>
#include <math.h>

//����һ�������������Ƿ���ˮ�ɻ��� 
int isFlower(int i, int x)
{	
	int flag=1;	//�����ж�main��if��� 
	int ret=i;	//����i��ֵ 
	int a=0;	//�����λ���� 
	int sum=0;	//��� 
	int b=1;	//�����λ��n���� 
	int p=0;	//����	

	while(i>0)
	{
		a=i%10;
		for(p=0;p<x;p++)
		{
			b*=a;	//bΪ����λ��n����
		} 
		sum+=b;
		i/=10;
		b=1;
	}//���sum����λ�����η��Ӻ� 
		
	if ( sum != ret )
	{
		flag=0;
	} 		
	return flag;
}

int main ()
{	
	int n;
	scanf("%d",&n);
	
	int k=1;
	for(int j=1; j<n; j++)
	{
		k*=10;
	} //����һ����ʼ��ֵ 
	 
	for(int t=k; t<k*10; t++)
	{
		if(isFlower(t,n)) printf("%d\n",t);
	}
	// t����nλ��
	return 0; 
 }

