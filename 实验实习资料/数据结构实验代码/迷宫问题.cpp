#include <stdio.h>
#include <stdlib.h>
typedef struct stack//����Stack��ջ
{
	int row;//������ 
	int col;//������ 
	int dir;//���� 
	struct stack *next;//ָ����һ�����
}Stack;

Stack *push(Stack *top,int row,int col,int dir);//��ջ���� 
Stack *pop(Stack *top);//��ջ����

int main(void)
{
	int i=0,j=0,m=0,n=0,dir=0,temp=0;
	int s1=0,s2=0,e1=0,e2=0;
	int arr[100][100]={0};
	Stack *top=NULL,*t = NULL;//��ʼ��ջ��
	scanf("%d %d",&m,&n);//m��n��
	scanf("%d %d",&s1,&s2);//���
	scanf("%d %d",&e1,&e2);//�յ� 
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);//�����Թ� 
		}
	}

	i=s1-1,j=s2-1,arr[i][j]=1;
	while(temp==0||top!=NULL)//ջ���գ���������,�߹���Ϊ1 
	{
		if(temp!=0&&i==e1-1&&j==e2-1)//�ߵ����� 
		{
			dir = 1,top = push(top,i,j,dir);
			break;
		}
		if(arr[i][j+1] == 0&&j+1<n)//��һ����
		{	
			dir = 1,top = push(top,i,j,dir);
			j++,arr[i][j]=1;
		}
		else if(arr[i+1][j] == 0&&i+1<m)//�ڶ�����
		{	
			dir = 2,top = push(top,i,j,dir);
			i++,arr[i][j]=1;
		}
		else if(arr[i][j-1] == 0&&j-1>-1)//��������
		{	
			dir = 3,top = push(top,i,j,dir);
			j--,arr[i][j]=1;
		}
		else if(arr[i-1][j] == 0&&i-1>-1)//��������
		{	
			dir = 4,top = push(top,i,j,dir);
			i--,arr[i][j]=1;
		}
		else//��·,��¼λ�ú���ջ 
		{
			arr[top->row][top->col] = 1;
			if(top->dir == 1) j--;
			else if(top->dir == 2) i--;
			else if(top->dir == 3) j++;
			else  i++;
			top = pop(top);
		}
		temp=1;
	}
	//������ 
	if(top == NULL)//��·���� 
	{
		printf("no");
	} 
	else
	{
		while(top->row!=s1-1||top->col!=s2-1)
		{
			t = push(t,top->row,top->col,top->dir);//��ջ������һջ 
			top = pop(top);
		}
		t = push(t,top->row,top->col,top->dir);

		while(t->row!=e1-1||t->col!=e2-1)
		{
			t->row = t->row + 1,t->col = t->col + 1;
			printf("(%d,%d,%d),",t->row,t->col,t->dir);
			t = pop(t);
		}
		printf("(%d,%d,%d)\n",++(t->row),++(t->col),t->dir);
	}
	return 0;
}

Stack *push(Stack *top,int row,int col,int dir)
{
	Stack *p = (Stack *)malloc(sizeof(Stack));//����һ���µĽڵ�
	p->row = row;
	p->col = col;
	p->dir = dir;
	p->next = top;
	top = p;//��p����ջ��
	return top;//����ջ�� 
}

Stack *pop(Stack *top)
{
	Stack *p = top;
	p = top;
    top = top->next;
    free(p);//�ͷ��ڴ�
    p=NULL;
	return top;//����ջ�� 
}
