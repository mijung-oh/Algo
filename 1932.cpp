#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int triangle[501][501] = { 0, };
	int dp[501][501] = { 0, }; 
	int n; scanf("%d", &n);
	int M = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i+1; j++) {
			scanf("%d", &triangle[i][j]);
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (i == 0) dp[i][j] = triangle[i][j];
			else if (j == 0) dp[i][j] = dp[i - 1][j] + triangle[i][j];
			else if (j == i) dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			else {
				dp[i][j] = max(dp[i - 1][j - 1] + triangle[i][j], dp[i - 1][j] + triangle[i][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (M < dp[n - 1][i]) {
			M = dp[n - 1][i];
		}
	}

	printf("%d", M);
}