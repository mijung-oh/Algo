#include <stdio.h>
#include <unordered_map>
#include<map>
using namespace std;

int main() {
	unordered_map<int, int> map;
	
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t; scanf("%d", &t);
		map[t]++;
	}
	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int t; scanf("%d", &t);
		printf("%d ", map[t]);
	}
	

}
//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int arr[500002];
//int main(void)
//{
//	int N;
//	scanf("%d", &N);
//	for (int i = 0; i < N; i++)
//	{
//		scanf("%d", &arr[i]); //배열에 넣는다
//	}
//	int M; //M개의 경우 
//	scanf("%d", &M);
//	sort(arr, arr + N);//정렬
//	for (int i = 0; i < M; i++)
//	{
//		int num;
//		scanf("%d", &num);
//
//		int* low = lower_bound(arr, arr + N, num);
//		int* upper = upper_bound(arr, arr + N, num);
//		int result = upper - low;
//		printf("%d ", result);
//	}
//	//low=이상, upp=초과의 인덱스
//}