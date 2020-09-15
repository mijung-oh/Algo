#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int dp[500][500]={0};
    
    //dp배열 값 넣기
    for(int i=0; i<triangle.size(); i++){
        for(int j=0; j<triangle.size(); j++){
            if(j==0) dp[i][j] = dp[i-1][j]+triangle[i][j];
            else if(j==i) dp[i][j] = dp[i-1][j-1]+triangle[i][j];
            else{
                dp[i][j] = max(triangle[i][j]+dp[i-1][j-1],triangle[i][j]+dp[i-1][j] );
            }
        }
    }
    //최댓값 찾기
    int max = -1;
    int size = triangle.size()-1;
    for(int i=0; i<triangle.size(); i++){
        if(dp[size][i] > max)
            max = dp[size][i];
    }
    
    return max;
}