#include <stdio.h>
#include <string>
#include <map>
#include <iostream>
using namespace std;

map<string, string>m;//부모
map<string, int>mf;

//부모리턴하는 함수
string Find(string x) {
	if (x == m[x]) return x;
	else {
		string p = Find(m[x]);
		m[x] = p;
		return p;
	}
}

void Union(string x, string y) {
	string X = Find(x);
	string Y = Find(y);

	if (X != Y) {
		m[Y] = X;
		mf[X] += mf[Y];
		mf[Y] = mf[X];
	}//X가 부모

	return;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		m.clear();
		mf.clear();
		int num; scanf("%d", &num);

		while (num--) {
			string s, s2; cin >> s >> s2;
			if (m.find(s) != m.end() && m.find(s2) != m.end() && m[s] == m[s2]) continue;

			if (m.find(s) == m.end()) {
				if (mf.find(s) == mf.end())
					mf[s]++;
				m[s] = s;
			}
			if (m.find(s2) == m.end()) {
				if (mf.find(s2) == mf.end())
					mf[s2]++;
				m[s2] = s2;
			}
			

			Union(s, s2);
			printf("%d\n", mf[Find(s)]);
			
		}

	}
	return 0;
}