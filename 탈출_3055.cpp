#include<stdio.h>
#include <queue>
using namespace std;

int X[4] = { 0,0,1,-1 };
int Y[4] = { 1,-1,0,0 };
queue<pair<int, int>> wq;//물차는거
queue<pair<int, int>>q;//고슴도치
int r, c;//r행c열
char map[51][51];
char newmap[51][51];//갱신된 맵

int wtvisited[51][51] = { 0, };
int visited[51][51] = { 0, };
int dist[51][51] = { 0, };

int cnt = 0;

void water(void) {
	int size = wq.size();//물 개수
	while (size--) {
		int x = wq.front().first;
		int y = wq.front().second;

		wq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + X[i];
			int ny = y + Y[i];

			if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
				if (visited[nx][ny] == 1 || map[nx][ny] == 'D' || map[nx][ny] == 'X') continue;
				newmap[nx][ny] = '*';
			}
		}
	}
	//newmap으로 map 교체
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map[i][j] = newmap[i][j];
		}
	}

	return;
}
void bfs(int x, int y) {
	//x,y는 S의 위치
	q.push(make_pair(x, y));
	int qsize = 1;

	while (!q.empty()) {
		cnt++;
		//물 먼저 채우기
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j] == '*' && wtvisited[i][j] == 0)
				{
					wtvisited[i][j] = 1;
					wq.push(make_pair(i, j));
				}
			}
		}
		water();

		//S의 이동
		while (qsize--) {
			int qx = q.front().first;
			int qy = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = qx + X[i];
				int ny = qy + Y[i];

				if (nx >= 0 && ny >= 0 && nx < r && ny < c && visited[nx][ny] == 0 && map[nx][ny] != '*' && map[nx][ny] != 'X') {
					visited[nx][ny] = 1;
					dist[nx][ny] = dist[qx][qy] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
		qsize = q.size();
		//출력
		/*if (cnt < 50) {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					printf("%c ", map[i][j]);
				}
				printf("\n");
			}
		}
		printf("\n");*/
	}
	return;
}
int main() {
	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++) {
		scanf("%s", map[i]);
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			newmap[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'S') {
				bfs(i, j);
				break;
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'D') {
				if (dist[i][j] == 0) {
					printf("KAKTUS");
				}
				else {
					printf("%d", dist[i][j]);
				}
			}
		}
	}
	return 0;
}