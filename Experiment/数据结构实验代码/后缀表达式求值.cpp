#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stacknum//������ջ 
{
	int val;
	struct stacknum *next;
}stnnode,*stn;

stn push(stn s,int val);
stn pop(stn s);

int num=0;

int main()
{
	int i=0,j=0,n=0,out=0;
	char first[120];
	int num1=0,num2=0;
	stn s=NULL;//������
	
	scanf("%s",&first);

	while(first[i]!='\0')
	{
		if(first[i]>47&&first[i]<58)//������,0-48,9-57,ֱ����ջ 
		{
			n=first[i]-48;
			s=push(s,n);
		}
		else//��������������γ�ջ���� 
		{
			s=pop(s),num2=num;
			s=pop(s),num1=num;
			if(first[i]=='+')//�������㣬������Ϻ󽫽����ջ 
			{
				out=num1+num2;
			}
			else if(first[i]=='-')
			{
				out=num1-num2;
			}
			else if(first[i]=='*')
			{
				out=num1*num2;
			}
			else
			{
				out=num1/num2;
			}
			s=push(s,out);
		}
		i++;
	}
	
	printf("%d\n",out);
	return 0;
}

stn push(stn s,int val)
{
	stn p;
	p = (stn)malloc(sizeof(stacknum));
	p->val=val,p->next=NULL;
	p->next=s,s=p;
	return s;
}

stn pop(stn s)
{
	stn p;
	p=s;
	num=p->val;
	s=p->next;
	return s;
}
