#include <stdio.h>
#include <math.h>

int main()
{
	//����a,b,c;ͬʱ��������Ҳ��Ϊѭ������
	int a=1;
	int b=0;
	int c=0;
	
    //���岢����n
	int n=0;
	scanf("%d",&n);
	//����ѭ����ʹ��a,b,c��ѭ����9���������ÿ�������������ϵ���� ��ע��a��c����Ϊ���λ�����ɵ���0�� 
	for(a=1;a<=9;a++)
	{
		for(b=0;b<=9;b++)
		{
			for(c=1;c<=9;c++)
			{
				if(a*101+b*20+c*101==n)
				{
					printf("%d %d %d\n",a,b,c);

				}

			}
		}
	} 
	return 0;
} 
