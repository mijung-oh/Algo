#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;
int n, k;//n:시작 k:도착지
int k2;
int dist[100001] = { 0 };

void bfs(int c) {
	queue<int>q;
	q.push(c);

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		if (front < 0) continue;

		int pre = front - 1;
		int post = front + 1;
		int two = front * 2;

		//pre
		if (0 <= pre && pre < k2) {
			if (dist[pre] == 0 && pre != n) {
				dist[pre] = dist[front] + 1;
				q.push(pre);
			}
			else if (dist[front] + 1 < dist[pre]) {
				dist[pre] = dist[front] + 1;
				q.push(pre);
			}
		}

		//post
		if (0 <= post && post< k2) {
			if (dist[post] == 0 && post != n) {
				dist[post] = dist[front] + 1;
				q.push(post);
			}
			else if (dist[front] + 1 < dist[post]) {
				dist[post] = dist[front] + 1;
				q.push(post);
			}
		}

		//two
		if (0 <= two && two < k2){
			if (dist[two] == 0 && two != n) {
				dist[two] = dist[front] + 1;
				q.push(two);
			}
			else if (dist[front] + 1 < dist[two]) {
				dist[two] = dist[front] + 1;
				q.push(two);
			}
		}

	}
}

int main() {
	scanf("%d %d", &n, &k);
	k2 = k * 2;

	bfs(n);
	printf("%d", dist[k]);

}