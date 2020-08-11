#define _CRT_SECURE_NO_WARNINGS
#include <queue>
#include <string>
#include <iostream>

using namespace std;

int main() {
	deque<int> q;
	int n; scanf("%d", &n);
	char a[20];
	while (n--) {
		scanf("%s", a);
		string s; cin >> s;
		if (!strcmp("push_front",a))
		{
			int p; scanf("%d", &p);
			q.push_front(p);
		}
		else if (!strcmp("push_back",a))
		{
			int p; scanf("%d", &p);
			q.push_back(p);
		}
		else if (!strcmp("front",a))
		{
			if (!q.empty())
				printf("%d\n", q.front());
			else
				printf("-1\n");
		}
		else if (!strcmp("back",a))
		{
			if (!q.empty())
				printf("%d\n", q.back());
			else
				printf("-1\n");
		}
		else if (!strcmp("size",a))
		{
			printf("%d\n", q.size());
		}
		else if (!strcmp("empty",a))
		{
			if (q.empty())
				printf("1\n");
			else
				printf("0\n");
		}
		else if (!strcmp("pop_front",a))
		{
			if (q.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", q.front());
				q.pop_front();
			}
		}
		else if (!strcmp("pop_back",a))
		{
			if (q.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", q.back());
				q.pop_back();
			}
		}
	}
	return 0;
}