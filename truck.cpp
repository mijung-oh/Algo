//#i#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<int> waitq;
queue<int> ingq;
vector<pair<int, int>> ingv;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int cnt = 0;
	int sum = 0;
	for (int i : truck_weights) {
		waitq.push(i);
	}
	int i = 0;
	while (1) {
		cnt++;
		if (!ingv.empty()) {
			for (int j = 0; j < ingv.size(); j++) {
				ingv[j].second++;
			}
		}
		if (!waitq.empty()) {
			if (sum + waitq.front() < weight) {
				ingq.push(waitq.front());
				sum += waitq.front();
				ingv.push_back(make_pair(waitq.front(), 0));
				ingv[i].second++;
				waitq.pop();
				i++;
			}
		}
		for (int k = 0; k < ingv.size(); k++) {
			if (ingv[k].second == bridge_length && ingq.front() == ingv[k].first) {
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
int main() {
	int b = 100;
	int w = 100;
	vector<int> v;
	v.push_back(10);
	v.push_back(10);
	v.push_back(10);
	v.push_back(10);
	v.push_back(10);
	v.push_back(10);
	v.push_back(10);
	v.push_back(10);
	v.push_back(10);
	v.push_back(10);
	int result = solution(b, w, v);
	printf("%d", result);
	return 0;
}