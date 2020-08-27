//#include<stdio.h>
//
//int combi(int m, int n) {
//	if (n == m || n == 0) {
//		return 1;
//	}
//	else
//		return combi(m - 1, n - 1)*m / n;
//}
//
//int main() {
//	int t;
//	scanf("%d", &t);
// 
//	while (t--) {
//		int n, m;
//		scanf("%d %d", &n, &m);
//		printf("%d\n", combi(m, n));
//	}
//
//	return 0;
//}