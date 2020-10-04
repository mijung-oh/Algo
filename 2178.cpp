#include <stdio.h>
#include <queue>

using namespace std;
queue<pair<int,int>>q;

//³²ºÏµ¿¼­
int X[4] = { 1,-1,0,0 };
int Y[4] = { 0,0,1,-1 };

int map[101][101] = { 0, };
int cnt = 0;
int n, m;

void bfs(int x,int y) {

	q.push(make_pair(0, 0));

	while (!q.empty()) {
		int first = q.front().first;
		int second = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = first + X[i];
			int ny = second + Y[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
				map[nx][ny] == 1)
			{			
				q.push(make_pair(nx, ny));
				map[nx][ny] = map[first][second] + 1;
			}
		}
		
	}
	return;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	bfs(0, 0);
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}*/

	printf("%d", map[n-1][m-1]);
}