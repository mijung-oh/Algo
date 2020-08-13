// <cstring>
// char* strstr(str1, str2) : str1에서 str2와 일치하는 문자열이 있는지 확인하는 함수
// 있으면 해당 위치의 포인터를 반환
// 없으면 null pointer 반환
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