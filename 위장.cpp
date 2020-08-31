#include <string>
#include <vector>
#include <map>

using namespace std;

map<string,int> m;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for(vector<string> s:clothes){
        m[s[1]]++;
    }
    map<string,int>::iterator it;
    for(it=m.begin(); it != m.end(); it++){
        answer *= (it->second+1);//а╤гу
    }
    return answer-1;
}