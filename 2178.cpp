#include <stdio.h>

using namespace std;
int map[101][101] = { 0, };

//우상하좌
//int X[4] = { 0,-1,1,0 };
//int Y[4] = { 1,0,0,-1 };

int X[4] = { 0,0,1,-1 };
int Y[4] = { 1,-1,0,0 };

int n, m;
int cnt = 987654321;

void dfs(int x, int y, int go, int visited[101][101]) {
	//마지막에 온 경우
	if (x == n-1 && y == m-1) {
		if (go + 1 < cnt) cnt = go + 1;
		return;
	}

	go++;

	for (int i = 0; i < 4; i++) {
		int nx = x + X[i];
		int ny = y + Y[i];


		if (nx >= 0 && ny >= 0 && nx < n && ny < m && visited[nx][ny] != 1 && map[nx][ny] != 0)
		{
			visited[nx][ny] = 1;
			dfs(nx, ny, go, visited);
			visited[nx][ny] = 0;
		}
	}
	return;
}

int main() {
	scanf("%d %d", &n, &m);
	int visited[101][101] = { 0, };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	

	dfs(0, 0, 0, visited);

	printf("%d\n", cnt);
}