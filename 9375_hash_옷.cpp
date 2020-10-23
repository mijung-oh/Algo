#include<stdio.h>
#include<map>
#include<string>
#include<iostream>

using namespace std;

int main() {
	
	int t; scanf("%d", &t);
	while (t--) {
		map<string, int>m;
		int n; scanf("%d", &n);
		int ans = 1;
		while (n--) {
			string s, s2; cin >> s >> s2;
			m[s2]++;
		}
		map<string, int>::iterator it;
		for (it = m.begin(); it != m.end(); it++) {
			ans *= (it->second + 1);
		}
		printf("%d\n", ans - 1);
	}

	/*auto i = map.find("headgear");
	if (i != map.end()) {
		cout << i->first << ' ' << i->second;
	}*/

}