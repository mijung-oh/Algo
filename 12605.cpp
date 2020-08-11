#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<queue>
#include<string>
#include<iostream>
using namespace std; 

int main() {
	deque<string>d;
	int n; scanf("%d\n", &n);

	for(int i=1; i<=n; i++){
		char s[100];
		gets_s(s);
		char* tok1 = strtok(s, " ");
		while (tok1 != NULL) {
			d.push_back(tok1);
			tok1 = strtok(NULL, " ");
		}
		printf("Case #%d: ", i);
		while (!d.empty()) {
			cout << d.back();
			printf(" ");
			d.pop_back();
		}
		printf("\n");
	}
}