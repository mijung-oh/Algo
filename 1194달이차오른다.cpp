#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

char mr[55][55];
int cnt = 0;
char have[30] = {'0'};
int rstart, cstart;

int dfs(int rs, int cs);
int main()
{

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", mr[i]);
    }

    //������ġ ã��
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mr[i][j] == '0')
            {
                rstart = i;
                cstart = j;
                break;
            }
        }
    }

    int result = dfs(rstart, cstart);
    printf("%d\n", result);
    return 0;
}

int dfs(int rs, int cs)
{
    //�����¿� �� ���������
    if (mr[rs + 1][cs] == '#' && mr[rs][cs + 1] == '#' &&
        mr[rs - 1][cs] == '#' && mr[rs][cs - 1] == '#')
    {
        return -1;
    }

    if (mr[rs + 1][cs] == '.' || mr[rs + 1][cs] == '0')
    { //��
        rs = rs + 1;
        cnt++;
        dfs(rs, cs);
    }
    else if (mr[rs + 1][cs] == 'A' || mr[rs + 1][cs] == 'B' || mr[rs + 1][cs] == 'C' || mr[rs + 1][cs] == 'D' || mr[rs + 1][cs] == 'E' || mr[rs + 1][cs] == 'F')
    { //��

        if (have[mr[rs + 1][cs] - 'A'] != '0') //���� ������ ����
        {
            rs = rs + 1;
            cnt++;
            dfs(rs, cs);
        }
        // cnt=0;
        // rs=rstart;
        // cs=cstart;
        // dfs(rs,cs);
    }
    else if (mr[rs + 1][cs] == 'a' || mr[rs + 1][cs] == 'b' || mr[rs + 1][cs] == 'c' || mr[rs + 1][cs] == 'd' || mr[rs + 1][cs] == 'e' || mr[rs + 1][cs] == 'f')
    { //��
        if (have[mr[rs + 1][cs] - 'a'] != mr[rs + 1][cs])
        {
            cnt++;
            have[mr[rs + 1][cs] - 'a'] = mr[rs + 1][cs];
            rs = rs + 1;
            dfs(rs, cs);
        }
    }

    else if (mr[rs - 1][cs] == '.' || mr[rs - 1][cs] == '0') //��
    {
        rs = rs - 1;
        cnt++;
        dfs(rs, cs);
    }
    else if (mr[rs - 1][cs] == 'A' || mr[rs - 1][cs] == 'B' || mr[rs - 1][cs] == 'C' || mr[rs - 1][cs] == 'D' || mr[rs - 1][cs] == 'E' || mr[rs - 1][cs] == 'F')
    {                                          //��
        if (have[mr[rs - 1][cs] - 'A'] != '0') //���� ������ ����
        {
            rs = rs - 1;
            cnt++;
            dfs(rs, cs);
        }
    }
    else if (mr[rs - 1][cs] == 'a' || mr[rs - 1][cs] == 'b' || mr[rs - 1][cs] == 'c' || mr[rs - 1][cs] == 'd' || mr[rs - 1][cs] == 'e' || mr[rs - 1][cs] == 'f')
    { //��
        if (have[mr[rs - 1][cs] - 'a'] != mr[rs - 1][cs])
        {
            cnt++;
            have[mr[rs - 1][cs] - 'a'] = mr[rs - 1][cs];
            rs = rs - 1;
            dfs(rs, cs);
        }
    }

    else if (mr[rs][cs - 1] == '.' || mr[rs][cs - 1] == '0') //��
    {
        cs = cs - 1;
        cnt++;
        dfs(rs, cs);
    }
    else if (mr[rs][cs - 1] == 'A' || mr[rs][cs - 1] == 'B' || mr[rs][cs - 1] == 'C' || mr[rs][cs - 1] == 'D' || mr[rs][cs - 1] == 'E' || mr[rs][cs - 1] == 'F')
    {                                          //��
        if (have[mr[rs][cs - 1] - 'A'] != '0') //���� ������ ����
        {
            cs = cs - 1;
            cnt++;
            dfs(rs, cs);
        }
    }
    else if (mr[rs][cs - 1] == 'a' || mr[rs][cs - 1] == 'b' || mr[rs][cs - 1] == 'c' || mr[rs][cs - 1] == 'd' || mr[rs][cs - 1] == 'e' || mr[rs][cs - 1] == 'f')
    { //��
        if (have[mr[rs][cs - 1] - 'a'] != mr[rs][cs - 1])
        {
            cnt++;
            have[mr[rs][cs - 1] - 'a'] = mr[rs][cs - 1];
            cs = cs - 1;
            dfs(rs, cs);
        }
    }

    else if (mr[rs][cs + 1] == '.' || mr[rs][cs + 1] == '0') //��
    {
        cs = cs + 1;
        cnt++;
        dfs(rs, cs);
    }
    else if (mr[rs][cs + 1] == 'A' || mr[rs][cs + 1] == 'B' || mr[rs][cs + 1] == 'C' || mr[rs][cs + 1] == 'D' || mr[rs][cs + 1] == 'E' || mr[rs][cs + 1] == 'F')
    {                                          //��
        if (have[mr[rs][cs + 1] - 'A'] != '0') //���� ������ ����
        {
            cs = cs + 1;
            cnt++;
            dfs(rs, cs);
        }
    }
    else if (mr[rs][cs + 1] == 'a' || mr[rs][cs + 1] == 'b' || mr[rs][cs + 1] == 'c' || mr[rs][cs + 1] == 'd' || mr[rs][cs + 1] == 'e' || mr[rs][cs + 1] == 'f')
    { //��
        if (have[mr[rs][cs + 1] - 'a'] != mr[rs][cs + 1])
        {
            cnt++;
            have[mr[rs][cs + 1] - 'a'] = mr[rs][cs + 1];
            cs = cs + 1;
            dfs(rs, cs);
        }
    }
    else if (mr[rs][cs] == '1')
    {
        return cnt;
    }
}