#include <stdio.h>

using namespace std;

int map[51][51] = { 0, };//1:땅 0:바다
int checked[51][51] = { 0, };//지나간 곳이면 1

							 //방향
int X[8] = { 0,0,-1,1,-1,1,-1,1 };
int Y[8] = { -1,1,0,0,-1,-1,1,1 };

//섬의 개수

void dfs(int x, int y) {

	checked[x][y] = 1;

	if (map[x][y] == 0) return;

	for (int k = 0; k < 8; k++) {
		int nx = x + X[k];
		int ny = y + Y[k];

		if (nx >= 0 && ny >= 0 && checked[nx][ny] != 1) {
			dfs(nx, ny);
		}
	}
	return;

}

int main() {
	
	while (1) {
		//초기화
		int cnt = 0;

		int w, h; scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && checked[i][j] != 1) {
					//checked[i][j] = 1;
					
					dfs(i, j);
					cnt++;
				}
			}
		}

		printf("%d\n", cnt);

		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				checked[i][j] = 0;
				map[i][j] = 0;
			}
		}
	}
}