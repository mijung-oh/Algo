#include<stdio.h>
#include<stack>
#include<string>
#include<iostream>

using namespace std;

stack<char> s;

bool check(string string) {
	int len = string.length();
	int flag = 0;
	int k = 0;

	while (1) {
		if (string[k] == '(' || string[k] == '[' || string[k] == ')' || string[k] == ']')
		{
			flag = 1;//괄호있는 문장
			break;
		}
		printf("%d\n", k);
		k++;
	}
	printf("falg : %d\n\n", flag);

	if (flag == 1) {
		for (int i = 0; i < len; i++) {
			if (string[i] == ')' || string[i] == ']')//]나 }로 시작하는 문장은 바로 false 리턴!
				return false;
		}

		for (int i = 0; i < len; i++) {
			if (!s.empty() && s.top() == string[i]) {
				s.pop();
			}
			else
				s.push(string[i]);
		}
	}
	if (s.empty())
		return true;
	else
		return false;

}
int main() {
	while (1) {
		string string;
		cin >> string;

		if (check(string))
			printf("YES\n");
		else
			printf("NO\n");

		if (string[0] == '.')
			break;

	}

}