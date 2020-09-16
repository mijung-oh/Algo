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
		// //w에 원소 1개 있는데 target이랑 같지 않으면 패스!
		// if (w.size() == 1 && begin != target) return;

		int string_cnt = 0;//string안에서 같은 문자 개수

		for (int i = 0; i < s.length(); i++) {
			if (begin[i] == s[i]) string_cnt++;
		}
		//2개가 같은 경우 그걸로 대체하고 다시 dfs
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
    
    //vector안에 target이 없는 경우
    int check=0;//check==0이면 target이 없는 vector
    for(string s : words){
        if(s == target) check=1;
    }
    if(check == 0) return 0;
    
    //vector안에 target있는 경우
    dfs(begin, target, words, cnt);
    
    //target은 존재하지만 만들어질 수 없는 경우 -> minnum은 바뀌지 않음
    if(minnum==10000) return 0;
    
	return minnum;
}