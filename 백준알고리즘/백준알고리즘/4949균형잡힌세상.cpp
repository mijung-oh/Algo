#include<stdio.h>
#include<stack>
#include<string>
#include<iostream>
using namespace std;

stack<char> s;

bool check(string st) {
	int len = st.length();
	for (int i = 0; i < len; i++) {
		if (st[i] == '(' || st[i] == '[')
		{
			s.push(st[i]);
			continue;
		}
		else if (st[i] == ')') {
			if (!s.empty() && s.top() == '(')
			{
				s.pop();
				continue;
			}
			else if (s.empty()) {
				return false;
			}
			else
			{
				s.push(st[i]);
				continue;
			}
		}
		else if (st[i] == ']')
		{
			if (!s.empty() && s.top() == '[')
			{
				s.pop();
				continue;
			}
			else if (s.empty()) {
				return false;
			}
			else
			{
				s.push(st[i]);
				continue;
			}
		}
		else
			continue;

	}

	if (s.empty())
		return true;
	else
		return false;
}

int main() {
	int i = 0;
	string st;

	while (1) {
		st = "";
		getline(cin, st);
		if (st.length() == 1 && st[0] == '.')
			break;

		if (check(st))
			printf("yes\n");
		else
			printf("no\n");


		if (!s.empty()) {
			while (!s.empty())
				s.pop();
		}
	}

	return 0;

}