#include<stdio.h>
#include<queue>
using namespace std;

//1. queue�� �Ӽ��� ������
//2. ù��° ���� : ������ ���� �� / �ι�° ���� : ���°�� ��µǴ��� �˰� ���� ���� �ε���
//   ����° �迭 : �켱���� �迭
//3. �μⰡ ���°�� �Ǵ��� ���
queue<int> q;
int main()
{
	int testcase;
	int priority[110] = { 0 };
	int result[110] = { 0 };
	scanf("%d", &testcase);

	while (testcase--) {
		int index = 1;
		int n, m;//n:������, m:�˰���� ���� �ε���
		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++) {
			scanf("%d", &priority[i]);
		}
		for (int i = 0; i < n; i++) {
			q.push(i);//�ӽ÷� �� �־���� -> ��µǴ� �� �� ���� �˱� ���ؼ�
		}


		while (!q.empty()) {
		again:
			int front = q.front();
			for (int k = 0; k < n; k++) {
				if (front != k && priority[front] < priority[k]) {
					q.push(front);//�� �ڷ� ������
					q.pop();
					goto again;
				}

			}
			result[index] = front;
			priority[front] = 0;//���� �켱���� �� �ʱ�ȭ
			q.pop();
			index++;
		}

		for (int i = 1; i <= n; i++) {
			if (result[i] == m)
			{
				printf("%d\n", i);
				break;
			}
		}


		//�迭�ʱ�ȭ
		for (int i = 0; i < n; i++) {
			priority[i] = 0;
			result[i + 1] = 0;
		}
	}
}