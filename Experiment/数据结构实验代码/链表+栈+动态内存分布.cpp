#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack//����Stack��ջ
{
	int value;//��ֵ 
	struct stack *next;//ָ����һ��Stack
}Stack;

Stack *push(Stack *top,int num);//��ջ���� 
Stack *pop(Stack *top);//��ջ����
void showStack(Stack *top);//չʾջ��Ԫ�� 
void showTop(Stack *top);//����ջ��Ԫ�� 

int main(void)
{
	int num=0,revalue=0;
	char input[10]="";//ѡ����� 
	const char exit_str[] = "exit";//�˳�������������ַ� 
	Stack *top = NULL;//��ʼ��ջ��
	printf("��ѡ��Ҫ���еĲ�������ջ������1����ջ������2������ջ��������3\n");
	
	do
	{
	scanf("%s",&input);//ѡ�����
	
	if(strcmp(input,"1") == 0)//ѡ����ջ 
	{
	printf("��ѡ����ջ��������һ������\n");
	do
	{
	revalue=scanf("%d",&num);
	if(revalue == 0)//scanf���յ�ֵ���� 
	{
	printf("�����������������\n");
	fflush(stdin);//������棬��ֹһֱ��ȡ������ֵ 
	}
	}while(revalue==0);
	top = push(top,num);//��ջ
	}
	
	else if(strcmp(input,"2") == 0)//ѡ���ջ
	{
	printf("��ѡ���ջ\n");
	top=pop(top);//��ջ
	}
	
	else if(strcmp(input,"3") == 0)//ѡ�񷵻�ջ�� 
	{
	printf("��ѡ�񷵻�ջ��Ԫ��\n");
	showTop(top); //����ջ��Ԫ�� 
	}
	
	else if(strcmp(input,exit_str) == 0)//������exit 
	{
	printf("ѡ���˳�����\n");
	break;
	}
	
	else
	{
	printf("����������������룡\n");
	}
	
	showStack(top);//չʾջ��Ԫ��
	printf("������˳��Ļ�������exit,���������ѡ��Ҫ���еĲ���\n");
	}while(1);//�ظ�ִ�г��� 
	
	printf("��л����ʹ�ã�\n");
	return 0;
}

Stack *push(Stack *top,int num)
{
	Stack *p = (Stack *)malloc(sizeof(Stack));//����һ���µĽڵ�
	p->value = num;
	p->next = top;
	top = p;//��p����ջ��
	printf("%d����ջ\n",num);
	return top;//����ջ�� 
}

Stack *pop(Stack *top)
{
	Stack *p = top;
	if(top == NULL)//��ջ 
	{
	printf("ջ����û�и���Ԫ��,��ջʧ��\n");
	}
	else//���ջ��Ԫ�� 
	{
	p = top;
	printf("%d�ѳ�ջ\n",p->value);
    top = top->next;
    free(p);//�ͷ��ڴ�
	return top;//����ջ�� 
	}
}

void showStack(Stack *top)
{
	Stack *p = NULL;
	if(top != NULL)//���ǿ�ջ 
	{
	printf("��������ջ��Ԫ�ص�չʾ\n");
	for(p = top; p; p = p->next)//�Ƚ�������������ջ��Ԫ�� 
        {
            printf("%d\n", p->value);
        }
	printf("Ԫ��չʾ�����\n");
	}
	else
	{
	printf("����һ����ջ\n");
	}
}

void showTop(Stack *top)
{
	if(top == NULL)//��ջ 
	{
	printf("ջ��û��Ԫ��\n");
	}
	else
	{
	printf("%d\n",top->value);
	}
}
