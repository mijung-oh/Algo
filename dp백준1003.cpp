#include <stdio.h>
int dp[31] = { 0 };


int main() {
	
	for (int i = 0; i <30; i++) {
		if (i == 0 || i == 1) dp[i] = i;
		else dp[i] = dp[i - 1] + dp[i - 2];
	}


	int t; scanf("%d", &t);
	while (t--) {
		int k; scanf("%d", &k);
		if (k == 0) printf("1 0\n");
		else if (k == 1) printf("0 1\n");
		else
			printf("%d %d\n", dp[k-1], dp[k]);
	}
}