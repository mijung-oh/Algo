#include<stdio.h>
#include<queue>
using namespace std;

//1. queue의 속성을 따른다
//2. 첫번째 변수 : 들어오는 문서 수 / 두번째 변수 : 몇번째로 출력되는지 알고 싶은 값의 인덱스
//   세번째 배열 : 우선순위 배열
//3. 인쇄가 몇번째로 되는지 출력
queue<int> q;
int main()
{
	int testcase;
	int priority[110] = { 0 };
	int result[110] = { 0 };
	scanf("%d", &testcase);

	while (testcase--) {
		int index = 1;
		int n, m;//n:문서수, m:알고싶은 값의 인덱스
		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++) {
			scanf("%d", &priority[i]);
		}
		for (int i = 0; i < n; i++) {
			q.push(i);//임시로 값 넣어놓기 -> 출력되는 값 더 쉽게 알기 위해서
		}
		

		while (!q.empty()) {
		again:
			int front = q.front();
			for (int k = 0; k < n; k++) {
				if (front != k && priority[front] < priority[k]) {
					q.push(front);//맨 뒤로 보내기
					q.pop();
					goto again;
				}
				
			}
			result[index] = front;
			priority[front] = 0;//높은 우선순위 값 초기화
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


		//배열초기화
		for (int i = 0; i < n; i++) {
			priority[i] = 0;
			result[i + 1] = 0;
		}
	}
}