#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	stack<int> s;
	vector<int> v;
	queue<char> v2;
	int input[100010] = { 0 };

	for (int i = 1; i <= n; i++) {
		v.push_back(i);
		scanf("%d", &input[i]);
	}

	
	for (int i = 1; i <= n; i++) {
		if (s.empty()) {//처음
			while (1) {
				s.push(v.front());
				v.erase(v.begin());
				v2.push('+');
				if (s.top() == input[i])
					break;
			}
			s.pop();
			v2.push('-');
		}
		else if (s.top() == input[i]) {
			s.pop();
			v2.push('-');
		}
		else if (s.top() > input[i]) {//불가능
			printf("NO\n");
			return 0;
		}
		else {
			while (1) {
				s.push(v.front());
				v.erase(v.begin());
				v2.push('+');
				if (s.top() == input[i])
					break;
			}`
			s.pop();
			v2.push('-');
		}
	}

	while (!v2.empty()) {
		printf("%c\n", v2.front());
		v2.pop();
	}
	return 0;
}