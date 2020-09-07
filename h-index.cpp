#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	int cnt = 0;
	sort(citations.begin(), citations.end());
	reverse(citations.begin(), citations.end());

	for (int i = citations.size(); i >= 0; i--) {
		for (int w : citations) {
			if (w >= i) cnt++;
		}
		if (cnt >= i) {
			answer = i;
			break;
		}
		else cnt = 0;
	}

	return answer;
}
int main() {
	vector<int>c;
	c.push_back(2);
	c.push_back(2);
	c.push_back(2);
	c.push_back(2);
	c.push_back(2);
	solution(c);
}