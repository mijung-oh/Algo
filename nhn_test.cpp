#include<stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int N; scanf_s("%d", &N);
	vector<pair<int, int>> v;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		return a.first < b.first;
		});

	int result = v.front().second;
	int cur_idx = 0;
	int max_idx = 0;

	int end = v.back().first;
	int curH = v.front().second;
	while (cur_idx < v.size()-1) {
		int maxH = -1;

		for (int it = cur_idx +1; it < v.size(); it++) {
			if (curH < v[it].second) {
				maxH = v[it].second;
				max_idx = it;
				break;
			}
			else if (v[it].second >= maxH) {
				maxH = v[it].second;
				max_idx = it;
			}
		}
		// 가장 큰 높이가 현재 높이보다 큰 경우
		if (maxH > curH) {
			result += (v[max_idx].first - v[cur_idx].first - 1) * curH + maxH;
		}
		// 현재 높이보다 큰 경우가 없다면 2번째로 큰 높이로 채운다.
		else if (maxH <= curH) {
			result += (v[max_idx].first - v[cur_idx].first) * maxH;
		}
		curH = maxH;
		cur_idx = max_idx;
	}
	cout << result;
	return 0;

}