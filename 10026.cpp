#include<stdio.h>
#include <queue>

using namespace std;

int visited[110][110] = { 0 };
char RGB[110][110] = { 0 };
int ci, cj;

int mx[4] = { 0,0,-1,1 };
int my[4] = { -1,1,0,0 };


bool dfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push(make_pair(i,j));
	visited[i][j] = 1;
	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		if(visited[x][y]==0 && )
	}
	else if (RGB[i][j] != c) {
		visited[i][j] = 0;
		return false;
	}

}

int main() {
	int n; scanf("%d", &n);
	for (int ii = 0; ii < n; ii++) {
		for (int jj = 0; jj < n; jj++) {
			scanf("%d", &RGB[ii][jj]);
		}
	}
	dfs(0, 0, RGB[0][0]);
}