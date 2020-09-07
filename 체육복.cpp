// <version 1>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    //1. lost랑 reserve 둘 다 있는 경우 먼저 삭제
    for (int i = 0; i < lost.size(); i++)
    {
        for (int j = 0; j < reserve.size(); j++)
        {
            if (lost[i] == reserve[j])
            {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                break;
            }
        }
    }

    int check = 0;
    //2. lost 돌면서 전/후의 번호가 reserve에 존재하는지 확인
    while (1)
    {
        if (lost.empty() || reserve.empty())
            break;

        for (int i = 0; i < lost.size(); i++)
        {
            check = 0;
            if (!lost.empty())
            {
                //전
                int pre = lost[i] - 1;
                if (pre > 0)
                {
                    for (int j = 0; j < reserve.size(); j++)
                    {
                        if (!reserve.empty())
                        {
                            if (reserve[j] == pre)
                            {
                                lost.erase(lost.begin() + i);
                                reserve.erase(reserve.begin() + j);
                                check = 1;
                                break;
                            }
                        }
                    }
                }
                if (check == 1)
                    continue;
                //후
                int post = lost[i] + 1;
                if (post <= n)
                {
                    for (int j = 0; j < reserve.size(); j++)
                    {
                        if (!reserve.empty())
                        {
                            if (reserve[j] == post)
                            {
                                lost.erase(lost.begin() + i);
                                reserve.erase(reserve.begin() + j);
                                check = 1;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (check == 0)
            break;
    }
    int los = lost.size();
    answer = n - los;
    return answer;
}


// <version 2>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    int check = 0;
    ; //0: 여벌옷 가지고 있고 도난당함, 1:여벌옷 가지고 있음, 2:도난당함

    for (int start = 1; start <= n; start++)
    {
        //여벌옷 가지고 있는데 도난당한 경우
        for (int i = 0; i < lost.size(); i++)
        {
            if (lost[i] == start)
            {
                for (int j = 0; j < reserve.size(); j++)
                {
                    if (reserve[j] == start)
                    {
                        lost.erase(lost.begin() + i);
                        reserve.erase(reserve.begin() + j);
                        check = 0;
                        break;
                    }
                }
            }
            if (check == 0)
                break;
        }

        //여벌옷 가지고 있고 도난 안 당한 경우
        for (int i = 0; i < reserve.size(); i++)
        {
            if (reserve[i] == start)
            {
                //뒷사람
                for (int j = 0; j < lost.size(); j++)
                {
                    if (lost[j] == start + 1)
                    {
                        lost.erase(lost.begin() + j);
                        reserve.erase(reserve.begin() + i);
                        check = 1;
                        break;
                    }
                }
                //앞사람
                for (int j = 0; j < lost.size(); j++)
                {
                    if (lost[j] == start - 1)
                    {
                        lost.erase(lost.begin() + j);
                        reserve.erase(reserve.begin() + i);
                        check = 1;
                        break;
                    }
                }
            }
            if (check == 1)
                break;
        }

        //lost인경우
        for (int i = 0; i < lost.size(); i++)
        {
            if (lost[i] == start)
            {
                //뒷사람
                for (int j = 0; j < reserve.size(); j++)
                {
                    if (reserve[j] == start + 1)
                    {
                        lost.erase(lost.begin() + i);
                        reserve.erase(reserve.begin() + j);
                        check = 2;
                        break;
                    }
                }
                //앞사람
                for (int j = 0; j < reserve.size(); j++)
                {
                    if (reserve[j] == start - 1)
                    {
                        lost.erase(lost.begin() + i);
                        reserve.erase(reserve.begin() + j);
                        check = 2;
                        break;
                    }
                }
            }
            if (check == 2)
                break;
        }
    }

    int cnt = lost.size();
    int result = n - cnt;
    return result;
}