#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int sum=0;
    stack<int> s;
    
    sort(people.begin(), people.end());
    // reverse(people.begin(), people.end());
    
    for(int i = people.size()-1; i >= 0; i--){
        if(people[i]==0) continue;
        
        sum += people[i];
        people[i]=0;
        
        for(int j=i-1; j>=0 ; j--){
            if(people[j] != 0 && sum + people[j] <= limit){
                sum += people[j];
                people[j]=0;
                break;
            }
        }
        
        s.push(sum);
        sum = 0;
    }
    
    return s.size();
}