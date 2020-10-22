#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int n, m; scanf("%d %d", &n, &m);
	set<string>d;//듣도못한
	set<string>b;//보도못한
	vector<string>answer;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		d.insert(s);
	}
	for (int i = 0; i < m; i++) {
		string ss; cin >> ss;
		b.insert(ss);
	}

	set<string>::iterator iter;
	for (iter = d.begin(); iter != d.end(); iter++) {
		if (b.find(*iter) != b.end())//있는 경우
		{
			answer.push_back(*iter);
		}
	}



	cout << answer.size() << endl;
	for (auto i : answer) cout << i << endl;

}