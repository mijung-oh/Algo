#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	int make, max_index;
	make = number.size() - k;
	int max = -1;
	int size = number.size();

	while (1) {
		max = -1;
		if (make == number.size())
		{
			answer += number;
			break;
		}
		for (int i=0; i < number.size() - make + 1; i++) {
			string s = number.substr(i, make);
			//�ִ� ���� ã��
			if (max < stoi(s)) {
				max = stoi(s);
				max_index = i;
			}
			else if (max == stoi(s))
				continue;
		}
		answer += number[max_index];
		make--;
		number = number.substr(max_index+1);
		if (make == 0)
			break;

	}
	return answer;
}
int main() {
	string s = "10000";
	int k = 2;
	string result = solution(s, k);
	cout << result;
}