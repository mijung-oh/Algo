#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int cnt = 0;
	vector<char>v;

	for (auto s : skill_trees) {
		for (int i = 0; i < s.length(); i++) {
			if (skill.find(s[i]) != string::npos) {
				//존재하면
				v.push_back(s[i]);
			}
		}

		int check = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] != skill[i]) {
				check = 1;
				break;
			}
		}
		if (check == 0) cnt++;
		check = 0;
		v.clear();

	}

	return cnt;
}
int main() {

	vector<string> tree{ "BACDE", "CBADF", "AECB", "BDA" };
	string sk = "CBD";
	cout << solution(sk, tree);
	return 0;
}