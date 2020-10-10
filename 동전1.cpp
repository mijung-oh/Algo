#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	int dp[100001] = { 0};
	int c[101] = { 0 };
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		int won = c[i];
		for (int j = won; j <= k; j++) {
			dp[j] = dp[j] + dp[j - won];
		}
	}

	printf("%d", dp[k]);

	return 0;

}