#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stack>
using namespace std;
stack<int>q;

int main() {
	int n; scanf("%d", &n);
	int cnt = 0;
	
	for (int i = 0; i < n; i++) {
		int h; scanf("%d", &h);
		q.push(h);
	}
	int max = -1;
	while (!q.empty()) {
		if (max<q.top())
		{
			cnt++;
			max = q.top();
		}
		q.pop();
	}
	printf("%d\n", cnt);
	return 0;
}