#include<string>
#include<vector>
#include<algorithm>
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

//1. ����Ž������ number��� ���� �� �ִ� ���� ��������
//2. ������� ���� �Ҽ��Ǻ��ϱ�.
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
	//1. ������������ �����ϱ� (max�� �˱� ����)
	vector<string>v;

	for (int i = 0; i < numbers.length(); i++) {
		v.push_back(numbers.substr(i, 1));
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	//2. 2~max �Ҽ��Ǻ�
	//3. �� �Ҽ��� �� ���Ұ� ���� ���ڿ��� ���� �Ǵ��� Ȯ��
	string numbers2;//"110"
	for (string s : v) {
		numbers2 += s;
	}
	int max = stoi(numbers2);
	int check = 0;//���� ���ڿ��� ���Եƴ��� Ȯ��(�ȵ����� 1)
    
	for (int i = 2; i <= max; i++) {
		string numbers3 = numbers2;
		if (isPrime(i)) {//�Ҽ��ϰ��
			string s = to_string(i);//11
			for (int j = 0; j < s.length(); j++) {
				string si = s.substr(j, 1);
				if (numbers3.find(si) >= numbers3.length() || numbers3.find(si) < 0) {//���Ծȵ�
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