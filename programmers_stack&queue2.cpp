#include <string>
#include <vector>
#include <queue>
using namespace std;

queue<int> waitq;//���Ʈ��
queue<int> ingq;//�ٸ� �ǳʴ� Ʈ��
queue<int> completeq;//�ٸ� ���� Ʈ��
int solution(int bridge_length, int weight, vector<int> truck_weights) {
	for (int i : truck_weights) {
		waitq.push(i);
	}
	int ing = 0;//�ٸ�����
	int time = 0;//����ð�
	int sum = 0;
	while (1) {
		time++;
		if (ing == bridge_length) {
			completeq.push(ingq.front());
			sum = sum - ingq.front();
			ingq.pop();
			ing = ing-bridge_length;
		}
		if (!waitq.empty() && (ingq.empty() || sum + waitq.front() <= weight) ){
			ingq.push(waitq.front());
			sum = sum + waitq.front();
			ing++;
			waitq.pop();
			continue;
		}
		ing++;
		if (completeq.size() == truck_weights.size()) {
			break;
		}

	}
	return time;
}
int main() {
	int b = 2;
	int w = 10;
	vector<int> t;
	t.push_back(7);
	t.push_back(4);
	t.push_back(5);
	t.push_back(6);
	int result = solution(b, w, t);
	printf("%d", result);
}