#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int sum = 0;
int visited[50] = {0};
int triangle[50] = {0};
int cnt = 0;

void tri(void)
{
    for (int i = 1; i <= 45; i++)
    {
        triangle[i] = (i * (i + 1)) / 2;
    }
}
int bruteforce(int n)
{
    for (int i = 1; i <= 44; i++)
    {
        for (int j = i; j <= 44; j++)
        {
            for (int k = j; k <= 44; k++)
            {
                sum = triangle[i] + triangle[j] + triangle[k];
                if (sum == n)
                    return 1;
                else
                    continue;
            }
        }
    }
    return 0;
}
int main()
{
    tri();
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        if (bruteforce(n) == 1)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}