#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	//��������������m��n 
	int m=0;
	int n=0;
	scanf("%d %d",&m,&n);
	
	//����ѭ������ 
	int i=0;
	int j=0;
	int l=0;
	
	//Flag������ʶ�Ƿ�������� 
	
	int flag=0;
	 
	//�������
	
	int a[100][100]={0};
	
	for(i=0;i<=m-1;i++)
	 {
	 	for(j=0;j<=n-1;j++)
	 	{
	 		scanf("%d",&a[i][j]);
	 	}
	 } 
	 
	 //ɨ��ÿ�е���Сֵ�����ж��Ƿ�Ϊ���е����ֵ,k,s���ڱ������������ 
	 int k=0;
	 int s=0;
	 int min=0;
	 int max=0;
	 
	 
	 for(i=0;i<=m-1;i++)
	 {
	 	for(j=0;j<=n-1;j++)
	 	{
	 		if(j==0)
	 		{
	 			min=a[i][j];
	 		}
	 		if(j>=1&&a[i][j]<=min)
	 		{
	 			min=a[i][j];
	 			k=j;
	 		}
	 	}
	 	
	 	for(l=0;l<=m-1;l++)
	 	{
	 		if(l==0)
	 		{
	 			max=a[l][k];
	 		}
	 		if(l>=1&&a[l][k]>=max)
	 		{
	 			max=a[l][k];
	 			s=l;
	 		}
	 	}
	 	if(max==min)
	 	{
	 		printf("%d %d %d\n",s,k,a[s][k]);
	 		flag+=1;
	 	}

	 }
	 if(flag==0)
	 {
	 	printf("no\n");
	 }
	 return 0;
}

