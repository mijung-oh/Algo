#include <string>
#include <vector>

using namespace std;

int visited[200] = { 0 };

void dfs(int start, vector<vector<int>> computers) {
	if (visited[start]) return;

	visited[start] = 1;
	for (int i = 0; i < computers.size(); i++) {
		if (computers[start][i] == 1 && !visited[i]) {
			dfs(i, computers);
		}
	}
	return;
}
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < computers.size(); i++) {
		if (!visited[i])
		{
			dfs(i, computers);
			answer++;
		}
	}
	return answer;
}