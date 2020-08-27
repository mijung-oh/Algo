#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int T[17], P[17];
    int pro[17] = {0};
    int dp[17][17] = {0};
    int check[17][17] = {0};

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &T[i], &P[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (T[j] >= n - j + 1)
            {
                check[i][j] = 1; //사용할 수 있는 p 체크
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (T[j] < n - j + 2)
            { //퇴사후가 아닐 경우
                if (T[i] <= j - i && T[j] == 1)
                {
                    dp[i][j] = dp[i][j - 1] + P[j];
                }
                else if (T[i] <= j - i && T[j] != 1)
                {
                }
                else
                {
                    dp[i][j] = P[i];
                }
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    int max = -1;
    /*for (int i = 1; i <= n; i++) {
		printf("%d\n", dp[i][n]);
		if (max < dp[i][n]) {
			max = dp[i][n];
		}
	}*/

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    //printf("%d", max);
}