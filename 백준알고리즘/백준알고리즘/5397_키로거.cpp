#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<stack>
#include<cmath>
using namespace std;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

void main() {
	init();

	int testcase; cin >> testcase;

	while (testcase--) {
		string str; cin >> str;

		stack<char> left, right;
		for (int i = 0; i < str1.size(); i++) {
			if (str[i] == '<' && !left.empty())
				right.push(left.pop());
			else if (str[i] == '>' && !right.empty())
				left.push(right.pop());
			else if (str[i] == '-' && !left.empty())
				left.pop()
			else
				left.push(str[i])

		}
		string left_string = "";
		string right_string = "";
		while (left)
			left_string += left.pop();
		while (right)
			right_string += right.pop();
		reverse(left_string);
		reverse(right_string);

		cout << left_string + right_string
		
	}
}