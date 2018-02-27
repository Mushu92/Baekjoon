#include<iostream>
#include<string>
#include<stack>

using namespace std;
bool CheckVPS(string str);
int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		//string 입력
		string inputstr;
		cin >> inputstr;
		if (CheckVPS(inputstr)) cout << "YES\n";
		else cout << "NO\n";
	}
	system("pause");
	return 0;
}

bool CheckVPS(string str) {
	int size = str.length();
	stack<char> cstc;
	for (int j = 0; j < size; j++) {
		//'('는 무조건 push
		if (str[j] == '(') cstc.push(str[j]);

		else {//')'경우 
			//스택에 '('가 있다면 하나 제거
			if (!cstc.empty()) cstc.pop();
			else {//없는 경우라면 "NO"로 검증 완료
				return 0;
			}
		}
	}
	//반복문 이후 스택이 비어있다면 "YES"
	return cstc.empty();
}