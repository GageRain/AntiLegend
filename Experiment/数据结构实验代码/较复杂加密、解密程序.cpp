#include <stdio.h>
#include <string.h>
void EncodeFunc(char* pSource,char* pKey,char* pEncrypted);//���ܺ��� 
void DecodeFunc(char* pEncrypted,char* pKey,char* pSource);//���ܺ��� 
int main()
{
	int i=0,j=0,num=0,t=0,lenK=0,len=0;
	char Source[100]="",Key[100]="",Encrypted[100]="";
	char *pSource=Source,*pKey=Key,*pEncrypted=Encrypted;
	char x[5]="";
	const char exit_str[] = "exit";
	printf("��ѡ����Ҫ���ܻ��ǽ��ܣ�����������1����������2\n"); 
	while(t!=3)
	{
	scanf("%s",&x);
	
	if(strcmp(x,"1") == 0)//���� 
	{
	//�������������� 
	printf("����������Ҫ���ܵ�����\n");
	fflush(stdin);
	gets(Source);
	printf("����������ܳ�\n");
	fflush(stdin);
	gets(Key);
	lenK=strlen(Key);
	//�ж��ܳ��Ƿ�Ϸ������������ܹ��� 
	for(i=0;i<lenK;i++)
	{
	if(Key[i]<48 || Key[i]>57)//�ж��Ƿ�Ϊ���� 
	{
	printf("��������ܳ�ֻ��Ϊ����\n");
	break;
	}
	else//�����ַ���Ϊ���ֲ��ܼ��� 
	{
	t++;
	}
	}
	if(t==lenK)
	{
	EncodeFunc(pSource,pKey,pEncrypted);
	printf("���ܺ�Ľ��Ϊ:\n");
	printf("%s\n",Encrypted);
	}
	}
	
	
	else
	{
	if(strcmp(x,"2") == 0)//���� 
	{
	//�������������� 
	printf("��������Ҫ���ܵ�����\n"); 
	fflush(stdin);
	gets(Encrypted);
	printf("����������ܳ�\n");
	fflush(stdin);
	gets(Key);
	lenK=strlen(Key);
	//�ж��ܳ��Ƿ�Ϸ������������ܹ��� 
	for(i=0;i<lenK;i++)
	{
	if(Key[i]<48 || Key[i]>57)//�ж��Ƿ�Ϊ���� 
	{
	printf("��������ܳ�ֻ��Ϊ����\n");
	t=0;
	break;
	}
	else//�����ַ���Ϊ���ֲ��ܼ��� 
	{
	t++;
	}
	}
	
	if(t==lenK)
	{
	DecodeFunc(pEncrypted,pKey,pSource);
	printf("���ܺ�Ľ��Ϊ:\n");
	printf("%s\n",Source);
	}
	}
	
	
	else
	{
	if(strcmp(x,exit_str) == 0)//�˳� 
	{
	break;
	}
	else
	{
	printf("�����������������\n"); 
	}
	}
	}
	t=0;
	printf("������˳��Ļ�������exit,���������ѡ����ܻ��ǽ���\n");
	}
	printf("��л����ʹ��\n");
	return 0;
}
//���ܺ���	
void EncodeFunc(char* pSource, char* pKey, char* pEncrypted)
{
	int i=0,j=0,lenS=0,lenK=0;
	lenS=strlen(pSource);//��¼�����ַ����ĳ��� 
	lenK=strlen(pKey);
	for(i=0;i<lenS;i++)
	{
	//��������ĸ 
	if(pSource[i]>64 && pSource[i]<91)//��д��ĸ 
	{
	pEncrypted[i]=pSource[i]+pKey[j]-48;
	if(pEncrypted[i]>90)//����90���ַ���ȥ26 
	{
	pEncrypted[i]-=26;
	}
	}
	else if(pSource[i]>96&&pSource[i]<123)//Сд��ĸ 
	{
	pEncrypted[i]=pSource[i]+pKey[j]-48;
	if(pEncrypted[i]>122)//����122���ַ���ȥ26 
	{
	pEncrypted[i]-=26;
	}
	}
	else
	{
	pEncrypted[i]=pSource[i];//������ĸ�򲻼��� 
	}
	j++;
	j=j%lenK;//�ܳ�ȡ����ͷ�ټ���ȡ 
	}
}

//���ܺ��� 
void DecodeFunc(char* pEncrypted,char* pKey,char* pSource)
{
	int i=0,j=0,lenE=0,lenK=0;
	lenE=strlen(pEncrypted);//��¼�����ַ����ĳ��� 
	lenK=strlen(pKey);
	for(i=0;i<lenE;i++)
	{
	//��������ĸ 
	if(pEncrypted[i]>64&&pEncrypted[i]<91)//Сд��ĸ 
	{
	pSource[i]=pEncrypted[i]-pKey[j]+48;
	if(pSource[i]<65)//С��65���ַ�����26 
	{
	pSource[i]+=26;
	}
	}
	else if(pEncrypted[i]>96&&pEncrypted[i]<123)//��д��ĸ 
	{
	pSource[i]=pEncrypted[i]-pKey[j]+48;
	if(pSource[i]<97)//С��97���ַ�����26 
	{
	pSource[i]+=26;
	}
	}
	else
	{
	pSource[i]=pEncrypted[i];//������ĸ�򲻽��� 
	}
	j++;
	j=j%lenK;//�ܳ�ȡ����ͷ�ټ���ȡ 
	}
}
