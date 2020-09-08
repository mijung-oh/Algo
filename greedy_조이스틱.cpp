#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    int index=0;
    for(int i=0; i<name.length(); i++){
        if(name[i] == 'A') continue;
        
        char c=name[i];
        int A_m=c-'A';//A에서부터의 횟수
        int Z_m='Z'-c+1;//A에서 뒤로가는 횟수
        int min = (A_m < Z_m)? A_m : Z_m;
                
        int right = i-index;
        int left = index+name.length()-i;
        int min_d;
        if(right == left)  min_d=right;
        else 
            min_d = (right<left)? right:left;
        // cout << "min " << min << endl;
        // cout << "min_d " << min_d << endl;
        answer += min+min_d;
        index=i;
    }
    return answer;
}