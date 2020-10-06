// #include <string>
// #include <vector>
// #include <algorithm>
// #include <iostream>

// using namespace std;

// //1. 오름차순
// //2. 첫번째의 진출지점이 두번째의 진입이점보다 크면, 포함관계임

// int solution(vector<vector<int>> routes) {
//     sort(routes.begin(), routes.end());
//     int cnt=1;
//     int c = routes[0][1];
    
//     for(int i=1; i<routes.size(); i++){
//         if(routes[i][0] <= c){
//             c = min(c, routes[i][1]);
//         }
//         else{
//             cnt++;
//             c = routes[i][1];
//         } 
            
//     }
    
//     return cnt;
// }
/////////2번째 풀이

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool cmp(vector<int>a, vector<int>b) 
{
    return a[1]<b[1];
}

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), cmp);
    int cnt=0;
    int c =-30001;
    
    for(int i=0; i<routes.size(); i++){
        if(c<routes[i][0])//포함관계 벗어남
        {
            cnt++;
            c = routes[i][1];//벗어난 노드 기준으로 포함관계 찾기
        }
            
    }
    
    return cnt;
}