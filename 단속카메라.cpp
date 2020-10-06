// #include <string>
// #include <vector>
// #include <algorithm>
// #include <iostream>

// using namespace std;

// //1. ��������
// //2. ù��°�� ���������� �ι�°�� ������������ ũ��, ���԰�����

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
/////////2��° Ǯ��

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
        if(c<routes[i][0])//���԰��� ���
        {
            cnt++;
            c = routes[i][1];//��� ��� �������� ���԰��� ã��
        }
            
    }
    
    return cnt;
}