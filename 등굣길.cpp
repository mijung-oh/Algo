#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int dp[110][110] = { 0, };
	int check[110][110] = {0,};
    
	for(auto v : puddles){
        check[v[1]][v[0]]=1;//¿õµ¢ÀÌÀÏ °æ¿ì
    }
    
    dp[1][0]=1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			//¿õµ¢ÀÌ
			if (check[i][j]==1) {
				continue;
			}
            //Å×µÎ¸®
			// if (i == 1 || j == 1) {
			// 	dp[i][j] = 1;
			// }
			else {
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000007;
			}
		}
	}
    
	return dp[n][m];
}