// <cstring>
// char* strstr(str1, str2) : str1���� str2�� ��ġ�ϴ� ���ڿ��� �ִ��� Ȯ���ϴ� �Լ�
// ������ �ش� ��ġ�� �����͸� ��ȯ
// ������ null pointer ��ȯ
#define NULL __null
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

int main() {
	char s1[50]; scanf("%s", s1);
	char s2[50]; scanf("%s", s2);
	
	char *ptr = strstr(s1, s2);
	while (ptr != NULL) {
	
        printf("%s\n", ptr);
		ptr = strstr(ptr + 1, s2);
		printf("hi\n");
		
	}

}