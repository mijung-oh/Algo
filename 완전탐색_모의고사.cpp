#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int one[5] = { 1,2,3,4,5 };
	int two[8] = { 2,1,2,3,2,4,2,5 };
	int three[10] = { 3,3,1,1,2,2,4,4,5,5 };

	int cnt[3] = { 0 };
	for (int i = 0; i < answers.size(); i++) {
		int index_one = i % 5;
		int index_two = i % 8;
		int index_three = i % 10;

		if (answers[i] == one[index_one])
			cnt[0]++;
		if (answers[i] == two[index_two])
			cnt[1]++;
		if (answers[i] == three[index_three])
			cnt[2]++;

	}
	// priority_queue<pair<int,int>, vector<pair<int.int>>, less<pair<int,int>>>q;
	priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> q;

	q.push(make_pair(cnt[0], 1));
	q.push(make_pair(cnt[1], 2));
	q.push(make_pair(cnt[2], 3));
	int first = q.top().first;
	int front = q.top().second;
	answer.push_back(front);
	q.pop();
	while (!q.empty()) {
		if (first == q.top().first)
		{
			answer.push_back(q.top().second);
			q.pop();
		}
		else {
			q.pop();
		}

	}
	sort(answer.begin(), answer.end());
	return answer;
}
int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	solution(v);
}