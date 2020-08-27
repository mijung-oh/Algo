#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
vector<pair<int, int>> v;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	int k = 0;
	int check = 0;//ū �켱������ ���� ���

	for (int i : priorities) {
		q.push(make_pair(i, k));//��⿭
		k++;
	}
	while (!q.empty()) {
		check = 0;
		int front = q.front().first;
		int front_second = q.front().second;//�ε��� ����

		for (int i = 0; i < priorities.size(); i++) {
			if (priorities[i] > front)//�켱������ �� ������ ���� ���
			{
				q.pop();
				q.push(make_pair(front, front_second));
				check = 1;
				break;
			}
		}
		if (check == 0) {
			v.push_back(make_pair(front, front_second));
			priorities[front_second] = 0;
			q.pop();
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (v[i].second == location) {
			answer = v[i].second;
			break;
		}
	}
	return answer;
}
int main() {
	vector<int>v;
	v.push_back(2);
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	int l = 2; 
	int result = solution(v, l);
	printf("%d\n", result);
}