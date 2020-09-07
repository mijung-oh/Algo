#include<string>
#include<vector>
#include<algorithm>
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

//1. 완전탐색으로 number들로 만들 수 있는 숫자 만들어놓기
//2. 만들어진 숫자 소수판별하기.
using namespace std;

bool isPrime(int num) {
    if(num == 2) return true;
    
	for (int i = 2; i*i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int solution(string numbers) {
	int answer = 0;
	//1. 오름차순으로 변경하기 (max값 알기 위해)
	vector<string>v;

	for (int i = 0; i < numbers.length(); i++) {
		v.push_back(numbers.substr(i, 1));
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	//2. 2~max 소수판별
	//3. 그 소수의 각 원소가 원래 문자열에 포함 되는지 확인
	string numbers2;//"110"
	for (string s : v) {
		numbers2 += s;
	}
	int max = stoi(numbers2);
	int check = 0;//원래 문자열에 포함됐는지 확인(안됐으면 1)
    
	for (int i = 2; i <= max; i++) {
		string numbers3 = numbers2;
		if (isPrime(i)) {//소수일경우
			string s = to_string(i);//11
			for (int j = 0; j < s.length(); j++) {
				string si = s.substr(j, 1);
				if (numbers3.find(si) >= numbers3.length() || numbers3.find(si) < 0) {//포함안됨
					check = 1;
					break;
				}
				else {
					int index = numbers3.find(si);
					numbers3.erase(numbers3.begin() + index);
				}
			}

			if (check == 0) {
                cout << i << endl;
                answer++;		
            }
            check = 0;
		}
	}

	return answer;
}