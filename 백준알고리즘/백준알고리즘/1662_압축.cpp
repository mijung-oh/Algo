#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
#include <vector>


using namespace std;

int main() {
	// true => 더해지지 않은 값 false => 더해진 값
	stack<pair<int, bool>> stack;

	string string1; cin >> string1;
	vector<pair<int, bool>> v;


	for (int i = 0; i < string1.length(); i++) {
		if (string1.at(i) == ')') {
			int sub_result = 0;
			while (stack.top().first != -1) {
				if (stack.top().second) {
					sub_result += 1;
				}
				else {
					sub_result += stack.top().first;
				}
				stack.pop();
			}
			// 괄호 반환
			stack.pop();
			int mul = stack.top().first; 

			stack.pop();
			
			// 곱한 문자 길이 stack에 넣기
			if (sub_result * mul != 0)
			{
				stack.push(make_pair(sub_result * mul, false));
			}


		}
		else if (string1.at(i) == '(') {
			stack.push(make_pair(-1, true));
		}
		else {
			
			stack.push(make_pair(int(string1.at(i)) - '0', true));
		}
	}

	int result = 0;
	while (!stack.empty()) {
		if (stack.top().second) {
			result += 1;
		}
		else {
			result += stack.top().first;
		}
		stack.pop();
	}
	cout << result;
	return 0;
}