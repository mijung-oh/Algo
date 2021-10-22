#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int N, W;
	cin >> N >> W;
	vector<int> v(W);

	for (int i = 0; i < W; i++)
		cin >> v[i];

	int result = 0;
	for (int i = 1; i < W-1; i++) {
		int left_max = 0;
		int right_max = 0;
		// 왼쪽 검사
		for (int j = 0; j < i; j++) left_max = max(v[j], left_max);
		// 오른쪽 검사
		for (int j = i + 1; j < W; j++) right_max = max(v[j], right_max);

		result += max(0, min(left_max, right_max) - v[i]);
	}
	cout << result;
}