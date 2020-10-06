#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}

int solution(vector<int> people, int limit)
{
    sort(people.begin(), people.end(), cmp);
    deque<int> dq;
    int cnt = 0;

    for (int i : people)
    {
        dq.push_back(i);
    }

    while (!dq.empty())
    {
        if (dq.size() != 1 && dq.front() + dq.back() <= limit)
        {
            dq.pop_back();
            dq.pop_front();
            cnt++;
        }
        else
        {
            dq.pop_front();
            cnt++;
        }
    }
    return cnt;
}