#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int get_basicnum(int n, int idx) {
	int sum = 0;
	for (int i = 0; i < idx; i++) {
		sum += n * pow(10, i);
	}
	return sum;
}

int solution(int N, int number) {

	vector<vector<int>>v(8,vector<int>(8,0));
	//v={5,55,555, '''}
	for (int i = 0; i < 8; i++) {
		v[i].push_back(get_basicnum(N, i+1));
	}

	 for(int i=1; i<8; i++){//일반 5,55,555돌기
	     for(int j=0; j<i; j++){
	         for(auto k : v[j]){
	             for(auto w : v[i-j-1]){
	                 v[i].push_back(k+w);
	                 v[i].push_back(k-w);
	                 v[i].push_back(k*w);
	                 if(w != 0)
	                     v[i].push_back(k/w);
	             }
	         }
	     }
	 }
	//최소연산 찾기
	for (int i = 0; i < v.size(); i++) {
		for (auto j : v[i]) {
			if (j == number) return i + 1;
		}
	}


}
int main() {
	int n = 5;
	int num = 12;
	solution(n, num);
}