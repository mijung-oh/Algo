#include <stdio.h>
#include <queue>
#include<algorithm>
#include <vector>
#include <iostream>
#define INF 99999

using namespace std;
vector<pair<int, int>> g[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int mindist[20001] = { 0 };//최단거리
int visited[20001] = { 0 };

void Dijkstra(int s) {
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		int d = pq.top().first;
		int next = pq.top().second;

		pq.pop();
		visited[next] = 1;

		for (auto i : g[next]) {
			int dochak = i.second;
			int gajung = i.first;

			if (visited[dochak] == 0 && mindist[dochak] > mindist[next] + gajung) {
				mindist[dochak] = mindist[next] + gajung;
				gajung = mindist[dochak];//노드의 가중치로 덮어씌움
				pq.push(make_pair(gajung, dochak));
			}
		}
	}
	return;
}

int main() {
	//v:정점개수, E:간선개수
	int v, E; scanf("%d %d", &v, &E);
	int st; scanf("%d", &st);//시작점

	for (int i = 0; i < E; i++) {
		int a, b, c; cin >> a >> b >> c;
		g[a].push_back(make_pair(b, c));//a-b거리 c
	}

	//초기화
	for (int i = 1; i <= v; i++)
		mindist[i] = INF;
	visited[st] = 1;
	mindist[st] = 0;

	Dijkstra(st);

	for (int i = 1; i <= v; i++) {
		if (mindist[i] == INF) printf("INF\n");
		else printf("%d\n", mindist[i]);
	}
	return 0;
}