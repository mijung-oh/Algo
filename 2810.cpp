#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<string>
#include<iostream>

using namespace std;

queue<char> q;

int main() {
	int n; scanf("%d", &n);
	string s;
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		q.push('*');
		q.push(s[i]);
		if (s[i] == 'L') {
			q.push(s[i]);
			i++;
			continue;
		}
	}
	q.push('*');

	int cnt = 0;
	while (!q.empty()) {
		if (q.front() == '*') {
			q.pop();
			if (!q.empty())
			{
				if (q.front() == 'S' || q.front() == 'L')
				{
					cnt++;
					q.pop();
				}
			}
			
		}
		else {
			q.push(q.front());
			q.pop();
			if (q.front() == 'L')
				break;
		}
		
	}
	
	printf("%d", cnt);

}