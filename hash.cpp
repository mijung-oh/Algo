#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int l; scanf("%d", &l);
	int sum = 0;
	int r = 31, M = 1234567891;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		int k = s[i] - 'a' + 1;
		sum += k * pow(r, i);
		if (sum >= M) {
			sum = sum % M;
		}
	}
	printf("%d", sum);
	return 0;
}