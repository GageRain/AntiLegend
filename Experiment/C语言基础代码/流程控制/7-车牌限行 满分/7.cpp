#include <stdio.h>

int main()
{
	int a,c,b,d;
	
	//a,b,c�ֱ��Ӧ��������ֵ�� 
	scanf("%d %d %d",&a,&b,&c);
	
	//dΪ����β�� 
	d=c%10;
	
	//���ж���򵥵���� 
	if(a==6||a==7)
	{
		printf("%d no",d);
	}
	else if(b<200)
	{
		printf("%d no",d);
	}
	
	//��������������������϶࣬���ǲ���ʹ��switch������ͨ���ֱ��ж�a��d�����Ӧ��ָ����Ʒ�����ʵ����ĺܷ��� 
	else if(b>=200&&b<400)
	{
		switch(a) 
		{
			case 1:switch(d) 
				{
					case 1:printf("%d yes",d);break;
					case 2:printf("%d no",d);break;
					case 3:printf("%d no",d);break;
					case 4:printf("%d no",d);break;
					case 5:printf("%d no",d);break;
					case 6:printf("%d yes",d);break;
					case 7:printf("%d no",d);break;
					case 8:printf("%d no",d);break;
					case 9:printf("%d no",d);break;
					case 0:printf("%d no",d);break;
					default:printf("error!");break;
				};
				break;
			case 2:switch(d) 
				{
					case 1:printf("%d no",d);break;
					case 2:printf("%d yes",d);break;
					case 3:printf("%d no",d);break;
					case 4:printf("%d no",d);break;
					case 5:printf("%d no",d);break;
					case 6:printf("%d no",d);break;
					case 7:printf("%d yes",d);break;
					case 8:printf("d no",d);break;
					case 9:printf("d no",d);break;
					case 0:printf("%d no",d);break;
					default:printf("error!");break;
				};
				break;
			case 3:switch(d) 
				{
					case 1:printf("%d no",d);break;
					case 2:printf("%d no",d);break;
					case 3:printf("%d yes",d);break;
					case 4:printf("%d no",d);break;
					case 5:printf("%d no",d);break;
					case 6:printf("%d no",d);break;
					case 7:printf("%d no",d);break;
					case 8:printf("%d yes",d);break;
					case 9:printf("%d no",d);break;
					case 0:printf("%d no",d);break;
					default:printf("error!");break;
				};
				break;
			case 4:switch(d) 
				{
					case 1:printf("%d no",d);break;
					case 2:printf("%d no",d);break;
					case 3:printf("%d no",d);break;
					case 4:printf("%d yes",d);break;
					case 5:printf("%d no",d);break;
					case 6:printf("%d no",d);break;
					case 7:printf("%d no",d);break;
					case 8:printf("%d no",d);break;
					case 9:printf("%d yes",d);break;
					case 0:printf("%d no",d);break;
					default:printf("error!");break;
				};break;
			case 5:switch(d) 
				{
					case 1:printf("%d no",d);break;
					case 2:printf("%d no",d);break;
					case 3:printf("%d no",d);break;
					case 4:printf("%d no",d);break;
					case 5:printf("%d yes",d);break;
					case 6:printf("%d no",d);break;
					case 7:printf("%d no",d);break;
					case 8:printf("%d no",d);break;
					case 9:printf("%d no",d);break;
					case 0:printf("%d yes",d);break;
					default:printf("error!");break;
				};break;
	    	default:printf("error!");break;
		}
	}
	else if(b>=400)
	{
		if(a==1||a==3||a==5)
		{
			switch(d)
			{
					case 1:printf("%d yes",d);break;
				 	case 2:printf("%d no",d);break;
					case 3:printf("%d yes",d);break;
					case 4:printf("%d no",d);break;
					case 5:printf("%d yes",d);break;
					case 6:printf("%d no",d);break;
					case 7:printf("%d yes",d);break;
					case 8:printf("%d no",d);break;
					case 9:printf("%d yes",d);break;
					case 0:printf("%d no",d);break;
					default:printf("error!");break;
			}
		}
		else if(a==2||a==4)
		{
			switch(d)
			{
					case 1:printf("%d no",d);break;
				 	case 2:printf("%d yes",d);break;
					case 3:printf("%d no",d);break;
					case 4:printf("%d yes",d);break;
					case 5:printf("%d no",d);break;
					case 6:printf("%d yes",d);break;
					case 7:printf("%d no",d);break;
					case 8:printf("%d yes",d);break;
					case 9:printf("%d no",d);break;
					case 0:printf("%d yes",d);break;
					default:printf("error!");break;
			}
		}
	}
	return 0;
}
