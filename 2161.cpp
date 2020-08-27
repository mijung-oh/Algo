#define _CRT_SECURE_NO_WARNINGS
#include <queue>

using namespace std;

queue<int> q;
queue<int> g;
int main() {
	int n; scanf("%d", &n);
	int check = 0;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (!(q.size() == 1)) {
		if (check == 0) {
			g.push(q.front());
			q.pop();
			check = 1;
		}
		else if (check == 1) {
			int front = q.front();
			q.pop();
			q.push(front);
			check = 0;
		}
	}
	while (!g.empty()) {
		printf("%d ", g.front());
		g.pop();
	}
	printf("%d\n", q.front());

}