#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<array>
#include<cmath>
using namespace std;

bool desc(int a, int b) {
	return a > b;
}
int main() {
	//배열 두개 만들기
	int mat[10] = { 9,8,7,6,5,4,3,2,1,0 };//곱할 수
	array<int, 30>storage = {0};

	int result = 0;
	int k = 0;
	int n; scanf("%d", &n);
	while (n--) {
		string string;
		cin >> string;
		for (int i = 0; i < string.length(); i++) {
			storage[string[i] - 'A'] = storage[string[i] - 'A'] + pow(10, string.length() - i - 1);
		}
	}
	sort(storage.begin(), storage.end(), desc);

	while (1) {
		if (storage[k] == 0)
			break;
		result = result + storage[k] * mat[k];
		k++;
	}

	printf("%d", result);

}