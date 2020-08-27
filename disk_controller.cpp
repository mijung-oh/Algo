#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int sum = 0;
    int time = 0;
    int size = jobs.size();
	priority_queue< int, vector<int>, greater<int> > q;
    // while(1){
        // for(int i=0; i<jobs.size(); i++){
        //     if(time == vector[i][0]){
        //         q.push(vector[i][1]);
        //     }
        // }
        // sum = sum + q.front();
        // time++;
    // }
    for(int i=0; i<jobs.size(); i++){
        q.push(jobs[i][1]);
        sum += q.front();
        q.pop();
    }
    
    sum = sum / size;
    return sum;
}