#include<stdio.h>

int main()
{
	// n��¼���е�������num��¼������pre��ʾ��ǰ���ǰһ�temp��ʾ��ǰ��
	int n=0, num=1, pre=0, temp=0;  
	scanf("%d",&n);
	
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&temp);  			// ���뵱ǰ�� 
    	if(i>=2 && temp!=pre) num++;	// �жϵ�ǰ����ǰһ���Ƿ���ȣ��������numֵ��һ 
    	pre=temp;						// ��ǰһ����ڵ�ǰ�׼��������һ�� 
	}
	printf("%d",num);
	return 0;
}




