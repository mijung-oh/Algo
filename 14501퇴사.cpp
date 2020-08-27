#include<stdio.h>

using namespace std;

int main() {
	int time[1010];
	int cost[1010];

	int max = -1;

	int n; scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d %d", &time[i], &cost[i]);
		if (n - time[i] + 1 < time[i]) {
			cost[i] = 0;//기간이 퇴사 후까지 지속되는 경우 제거
		}
	}

	int max_point;

	for (int i = 1; i <= n; i++) {
		if (cost[i] > max)
		{
			max = cost[i];
			max_point = i;
		}
	}//max값 찾기




}