#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>cnt;
int visited[101][101] = { 0, };
int X[4] = { 0,0,1,-1 };
int Y[4] = { 1,-1,0,0 };
int M, N;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
void dfs(int x, int y, int v, int idx, vector<vector<int>> p) {
	if (visited[x][y] != 1) visited[x][y] = 1;
	cnt[idx]++;

	for (int i = 0; i < 4; i++) {
		int nx = x + X[i];
		int ny = y + Y[i];

		if (nx >= 0 && ny >= 0 && nx < M && ny < N && p[nx][ny] == v && visited[nx][ny] != 1) {
			dfs(nx, ny, v, idx, p);
		}
	}


}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	int turn = 0;
	int v_index = 0;//cnt인덱스
	M = m; N = n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] != 0 && visited[i][j] == 0) {
				int value = picture[i][j];
				cnt.push_back(0);
				dfs(i, j, value, v_index, picture);
				v_index++;
			}
		}
	}


	vector<int> answer(2);
	answer[0] = cnt.size();
	if (cnt.size() == 0) answer[1] = 0;
	else answer[1] = *max_element(cnt.begin(), cnt.end());

	return answer;
}
int main() {
	vector<vector<int>> pp{ {0} };
	vector<int> a;
	a = solution(1,1, pp);
	printf("%d %d", a[0], a[1]);
	
}