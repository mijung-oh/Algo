// #include <string>
// #include <vector>
// #include <iostream>
// using namespace std;

// string solution(string number, int k)
// {
// 	string answer = "";
// 	int mk = number.length() - k; //만들어야 하는 문자열의 길이
// 	int maxIDX = 0;				  //큰 값의 index

// 	while (1)
// 	{
// 		//남은 문자열이 만들어야하는 문자열의 길이와 같으면 통째로 붙여주기
// 		if (number.length() == mk)
// 		{
// 			answer += number;
// 			break;
// 		}
// 		string s = number.substr(0, 1);
// 		if (s == "9")
// 		{
// 			number = number.substr(1);
// 			answer += s;
// 			mk--;
// 			if (mk == 0)
// 				break;

// 			continue;
// 		}

// 		maxIDX = 0;
// 		for (int i = 1; i < number.length(); i++)
// 		{
// 			string s2 = number.substr(i, 1);
// 			if (s < s2 && number.length() - i >= mk)
// 			{
// 				s = s2;
// 				maxIDX = i;
// 			}
// 		}

// 		mk--;
// 		answer += number[maxIDX];
// 		number = number.substr(maxIDX + 1);

// 		if (mk == 0)
// 			break;
// 	}
// 	return answer;
// }
// int main()
// {
// 	string string = "985632165";
// 	int k = 5;
// 	cout << solution(string, k);
// }

#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k)
{
	string answer = "";
	int mk = number.length() - k; //만들어야하는 문자열 길이
	stack<int> s;

	for (int i = 0; i < number.length(); i++)
	{
		
		if (!s.empty() && s.top() < number[i])
		{
			if(s.size()+number.length()-i == mk){
				break;
			}

			while(1){
				if(s.top()>number[i]) break;
				if (s.size() + number.length() - i == mk) break;
				s.pop();
			}
		}
		
		s.push(number[i]);
	}
	while(!s.empty()){
		answer.push_back(s.top());
		s.pop();
	}
	return answer;
}