#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int minnum = 10000;

void dfs(string begin, string target, vector<string>w,int cnt) {
   
	if (begin == target) {
		if (minnum > cnt) minnum = cnt;
		return;
	}
  

	for (string s : w) {
		if (s == begin) continue;
		// //w�� ���� 1�� �ִµ� target�̶� ���� ������ �н�!
		// if (w.size() == 1 && begin != target) return;

		int string_cnt = 0;//string�ȿ��� ���� ���� ����

		for (int i = 0; i < s.length(); i++) {
			if (begin[i] == s[i]) string_cnt++;
		}
		//2���� ���� ��� �װɷ� ��ü�ϰ� �ٽ� dfs
		if (string_cnt == s.length()-1) {
			int idx = find(w.begin(), w.end(), s) - w.begin();
			vector<string> oow = w;
			oow.erase(oow.begin() + idx);
			int cnt2 = cnt;
			dfs(s, target,oow, ++cnt2);
		}
	}
    return;
}
int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	int cnt = 0;
    
    //vector�ȿ� target�� ���� ���
    int check=0;//check==0�̸� target�� ���� vector
    for(string s : words){
        if(s == target) check=1;
    }
    if(check == 0) return 0;
    
    //vector�ȿ� target�ִ� ���
    dfs(begin, target, words, cnt);
    
    //target�� ���������� ������� �� ���� ��� -> minnum�� �ٲ��� ����
    if(minnum==10000) return 0;
    
	return minnum;
}