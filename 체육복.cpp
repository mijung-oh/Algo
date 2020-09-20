#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int state[31]={0};
    for(int i=1; i<=n; i++){
        state[i]=1;//기본
    }
    for(int i:lost){
        state[i] -=1;
    }
    for(int i:reserve){
        state[i] +=1;
    }
    
    for(int i=1; i<=n; i++){
        if(state[i]==0){
            if(state[i-1]==2){
                //앞사람한테 빌리기
                state[i-1] -=1;
                state[i] +=1;
            }
            else if(state[i+1]==2){
                //뒷사람한테 빌리기
                state[i+1] -=1;
                state[i] +=1;
            }
        }
    }
    int cnt=0;
    for(int i=1; i<=n; i++){
        if(state[i]!=0) cnt++;
    }
    return cnt;
}