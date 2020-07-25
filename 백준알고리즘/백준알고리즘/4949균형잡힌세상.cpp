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
		k++;
		if (k == len - 1)
			break;
	}

	if (flag == 1) {
		int start;
		for (int i = 0; i < len; i++) {
			if (string[i] == '(' || string[i] == '[')
			{
				s.push(string[i]);
				start = i;
				break;
			}
		}//첫번째 괄호 넣어주기(empty에서 에러 안나게 하기 위해)

		for (int i = start + 1; i < len; i++) {
			if (!s.empty()) {
				if (s.top() == '(' && string[i] == ')')
				{
					s.pop();
					continue;
				}
				else if (s.top() == '[' && string[i] == ']') {
					s.pop();
					continue;

				}
				else if (s.top() == '(') {
					if (string[i] == ']' || string[i] == '[' || string[i] == '(')
					{
						s.push(string[i]);
						continue;
					}

				}
				else if (s.top() == '[') {
					if (string[i] == '(' || string[i] == '[' || string[i] == ')')
					{
						s.push(string[i]);
						continue;
					}
				}
			}
		}
	}
	else
		return true;

	if (s.empty())
		return true;
	else
		return false;

}
int main() {
	while (1) {
		string string;
		getline(cin, string);
		if (string[0] == '.') {
			printf("yes\n");
			return 0;
		}

		if (check(string))
			printf("yes\n");
		else
			printf("no\n");
	}

}