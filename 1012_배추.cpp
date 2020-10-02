#include <stdio.h>

using namespace std;

int b[51][51] = { 0, };//배추밭
int visited[51][51] = { 0, };
//상하좌우
int X[4] = { 0,0,-1,1 };
int Y[4] = { -1,1,0,0 };

void dfs(int x,int y) {
	if (visited[x][y] == 1) return;
	if (b[x][y] == 0) return;

	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + X[i];
		int ny = y + Y[i];

		if(nx>=0 && ny >=0)
			dfs(nx, ny);
	}
	return;
}


int main() {
	int t; scanf("%d", &t);


	while (t--) {
		
		int cnt = 0;//지렁이마리수
		
		int m, n, k; scanf("%d %d %d", &m, &n, &k);

		//배추위치 체크
		while (k--) {
			int x, y; scanf("%d %d", &x, &y);
			b[x][y] = 1;
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (b[i][j] == 1 && visited[i][j] != 1)
				{
					dfs(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);

		//초기화
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				visited[i][j] = 0;
				b[i][j] = 0;
			}
		}
	}
}