#include<stdio.h>
int main()
{
	//����a,����a����ʼ��a 
	char a = 0;
	a = getchar();
	
	//�жϴ�Сд������Ǵ�д��ĸ�򻻳�Сд�����Сд�򻻳ɴ�д 
	
	if(a>=65&&a<=90) {  //����Ǵ�д��ĸ��ASCII����Ĵ�д��ĸ��Χ�� 
	
		putchar(a+32); //���a   //��Сд��ĸ��ASCII�����32 
	}
	
	else if(a>=97&&a<=122){
		putchar(a-32); //���a 
	}
	
	else{
		printf("������Ĳ�������ĸ��");	
	}

	return 0;
}
