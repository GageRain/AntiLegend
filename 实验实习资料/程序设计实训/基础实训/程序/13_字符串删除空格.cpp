#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	��д���򣬶��ڶ����һ���ַ�����ɾ���������еĿո����磬���ַ�����xidian university ���еĿո�ɾ���󣬵õ���xidianuniversity����
	
	����˵��: ���ո���ַ���
	
	���˵��: ɾ���ո����ַ���
*/

// ָ�������ɾ���ַ������пո� 
void Trim(char *chs){
	char *temp = chs;
	while(*temp){
		// �ж��Ƿ�Ϊ�ո������������븳ֵ��chs����һλ
		if(*temp != ' ' && *temp != '\t'){
			*chs++ = *temp;
		}
		temp++;
	}
	*chs = '\0';
}

int main(){
	char str[99] = {'\0'};
	gets(str);
	
	Trim(str);
	
	// ����µ��ַ��� 
	printf("%s", str);
	
	return 0;
} 
