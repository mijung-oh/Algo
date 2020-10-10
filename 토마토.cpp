#include<stdio.h>
#include <queue>

using namespace std;

int m, n;
int X[4] = { 0,0,1,-1 };
int Y[4] = { 1,-1,0,0 };
int dist[1001][1001] = { 0, };

void bfs(int to[1001][1001]) {
	queue<pair<int,int>>q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (to[i][j] == 1) {
				//익은 토마토
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + X[i];
			int ny = y + Y[i];

			if (to[nx][ny] == 0 && nx >= 0 && ny >= 0 && nx <n && ny < m) {
				q.push(make_pair(nx, ny));
				to[nx][ny] = 1;
				dist[nx][ny] = dist[x][y] + 1;
			}
		}

	}

}
int main() {
	scanf("%d %d", &m, &n);
	int tomato[1001][1001] = { 0, };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &tomato[i][j]);
		}
	}
	bfs(tomato);

	int max = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] > max)
				max = dist[i][j];
			if (dist[i][j] == 0) {
				printf("-1");
				return 0;
			}
		}
	}

	printf("%d", max);
	return 0;
}