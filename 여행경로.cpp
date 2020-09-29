#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<string>> g; //그래프 g
int check[10001][10001] = {0};
vector<string> answer;

int start_check = 1; //start에 있으면 1

void dfs(string s)
{

    for (int i = 0; i < g.size(); i++)
    {
        if (g[i][0] == s)
        {

            if (check[i][0] == 1)
                return;

            check[i][0] = 1;
            queue<string> q;
            answer.push_back(s);

            for (int j = 1; j < g[i].size(); j++)
            {
                q.push(g[i][j]);
            }

            while (!q.empty())
            {
                string front = q.front();
                q.pop();
                dfs(front);
                if (start_check == 0)
                {
                    q.push(front);
                    start_check = 1;
                    if (q.size() == 1)
                        return;
                }
            }
        }
    }

    start_check = 0;
    return;
}

vector<string> solution(vector<vector<string>> tickets)
{

    int check = 0; //g안에 있으면 1

    for (int i = 0; i < tickets.size(); i++)
    {
        string start = tickets[i][0];
        string end = tickets[i][1];
        //g안에 start가 있는 경우
        for (int j = 0; j < g.size(); j++)
        {
            if (g[j][0] == start)
            {
                g[j].push_back(end);
                check = 1;
                break;
            }
        }
        if (check == 0)
        {
            //g안에 없는 경우
            vector<string> v{start, end};
            g.push_back(v);
        }
        check = 0;
    }

    //알파벳 앞서는 순서로 하기 위해 정렬
    for (int i = 0; i < g.size(); i++)
    {
        sort(g[i].begin() + 1, g[i].end());
    }

    for (int i = 0; i < g.size(); i++)
    {
        if (g[i][0] == "ICN") //ICN에서 출발
        {
            dfs(g[i][0]);
            break;
        }
    }

    return answer;
}