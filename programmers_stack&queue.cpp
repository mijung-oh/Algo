// 문제가 개편되었습니다. 이로 인해 함수 구성이나 테스트케이스가 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<int> q;
vector<int> p;
vector<int> s;
vector<int> a;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	for (int i : progresses) 
	{
		q.push(i);
	}
	while (!q.empty()) {
		if (q.front() < 100) {
			while (!q.empty())
				q.pop();//q초기화

			for (int i = 0; i < progresses.size(); i++) {
				progresses.at(i) = progresses.at(i) + speeds.at(i);
				q.push(progresses.at(i));
			}
		}
		else if (q.front() >= 100) {
			int cnt = 0;
			while (!q.empty() && q.front() >= 100) {
				cnt++;
				q.pop();
			}
			progresses.erase(progresses.begin(), progresses.begin() + cnt);
			speeds.erase(speeds.begin(), speeds.begin() + cnt);

			answer.push_back(cnt);
		}
		if (progresses.empty()) {
			break;
		}
	}

	return answer;
}

int main() {
	p.push_back(40);
	p.push_back(93);
	p.push_back(30);
	p.push_back(55);
	p.push_back(60);
	p.push_back(65);

	s.push_back(60);
	s.push_back(1);
	s.push_back(30);
	s.push_back(5);
	s.push_back(10);
	s.push_back(7);

	a = solution(p, s);
	for (int i : a)
		printf("%d ", i);
}