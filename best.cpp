#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;




vector<int> solution(vector<string> genres, vector<int> plays) {
	map<string, int> m;
	priority_queue<pair<int, int> > pq;
	vector<pair<int, string>> max;

	vector<int> answer;

	for (int i = 0; i < genres.size(); i++) {
		m[genres[i]] += plays[i];
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		max.push_back(make_pair(it->second, it->first));
	}
	sort(max.begin(), max.end());
	reverse(max.begin(), max.end());


	for (auto it = max.begin(); it != max.end(); it++) {
		string s = it->second;//장르 선택
		//장르선택 후 해당 장르 내에서의 재생 횟수 pq에 넣기
		for (int i = 0; i < genres.size(); i++) {
			if (genres[i] == s) {
				pq.push(make_pair(plays[i], i));
			}
		}

		if (pq.size() == 1) {
			answer.push_back(pq.top().second);
			pq.pop();
			continue;
		}
		else {
			int first_plays = pq.top().first;
			int first = pq.top().second;
			pq.pop();
			int second_plays = pq.top().first;
			int second = pq.top().second;
			pq.pop();
			if (first_plays == second_plays) {
				if (first > second)
				{
					answer.push_back(second);
					answer.push_back(first);
				}
				else {
					answer.push_back(first);
					answer.push_back(second);
				}
			}
			else {
				answer.push_back(first);
				answer.push_back(second);
			}

			while (!pq.empty())
				pq.pop();
		}
	}

	return answer;
}
int main() {
	vector<string> g;
	g.push_back("classic");
	g.push_back("pop");
	g.push_back("rock");
	g.push_back("r&b");
	//g.push_back("pop");

	vector<int> p;
	p.push_back(10);
	p.push_back(20);
	p.push_back(30);
	p.push_back(40);
	
	vector<int> result = solution(g, p);
	for (int i : result)
		printf("%d ", i);
}