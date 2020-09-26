#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k)
{
	string answer = "";
	int mk = number.length() - k; //������ �ϴ� ���ڿ��� ����
	int maxIDX = 0;				  //ū ���� index

	while (1)
	{
		string s = number.substr(0, 1);
		maxIDX = 0;
		for (int i = 1; i < number.length(); i++)
		{
			string s2 = number.substr(i, 1);
			if (s < s2 && number.length() - i >= mk)
			{
				s = s2;
				maxIDX = i;
			}
		}

		mk--;
		answer += number[maxIDX];
		number = number.substr(maxIDX + 1);

		if (mk == 0)
			break;
	}
	return answer;
}
int main()
{
	string string = "985632165";
	int k = 5;
	cout << solution(string, k);
}