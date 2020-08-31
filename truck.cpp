#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<int> waitq;
queue<int> ingq;
vector<pair<int, int>> ingv;
int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	int cnt = 0;
	int sum = 0;
	for (int i : truck_weights)
	{
		waitq.push(i);
	}
	int i = 0;
	while (1)
	{
		cnt++;
		if (!ingv.empty())
		{
			for (int j = 0; j < ingv.size(); j++)
			{
				if (ingv[j].first != 0)
					ingv[j].second++;
			}
		}
		//다리를 건너는 트럭에 넣어줄건지
		if (!waitq.empty())
		{
			if (sum + waitq.front() <= weight)
			{
				ingq.push(waitq.front());
				sum += waitq.front();
				ingv.push_back(make_pair(waitq.front(), 0));
				ingv[i].second++; //다리에서 움직인 거리
				waitq.pop();
				i++;
			}
		}

		for (int k = 0; k < ingv.size(); k++)
		{
			if (ingv[k].second == bridge_length && ingq.front() == ingv[k].first)
			{
				sum = sum - ingq.front();
				ingq.pop();
				ingv[k].first = 0;
				ingv[k].second = 0;
			}
		}

		if (ingq.empty() && waitq.empty())
			break;
	}
	return cnt + 1;
}
// #include <string>
// #include <vector>
// #include <queue>

// using namespace std;
// queue<int> q;
// int solution(int bridge_length, int weight, vector<int> truck_weights)
// {
// 	int time = 0;
// 	int sum = 0;
// 	for (int i = 0; i < bridge_length; i++)
// 	{
// 		q.push(0);
// 	}
// 	int i = 0;
// 	while (1)
// 	{
// 		time++;
// 		if (sum != 0)
// 		{
// 			sum -= q.front();
// 			q.pop();
// 			q.push(0);
// 			continue;
// 		}
// 		if (sum + truck_weights[i] <= weight)
// 		{
// 			sum += truck_weights[i];
// 			q.push(truck_weights[i]);
// 			truck_weights[i] = 0;
// 			q.pop();
// 			i++;
// 		}

// 		if (sum == 0)
// 			break;
// 	}

// 	return time;
// }