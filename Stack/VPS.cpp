#include<iostream>
#include<string>
#include<stack>

using namespace std;

#define MAX_SIZE 100
int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		//string 입력
		string inputstr;
		cin >> inputstr;
		int size = inputstr.length();
		bool flag=1;
		//stack
		stack<char> cstc;
		for (int j = 0; j < size; j++) {
			if (inputstr[j] == '(') cstc.push(inputstr[j]);

			else {//')'경우
				if (!cstc.empty()) cstc.pop();
				else {
					flag = 0;//검증 끝!
					break;
				}
			}
		}
		//반복문 이후 스택이 비어있다면 "YES"
		if(flag) flag = cstc.empty();
		//출력
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
	system("pause");
	return 0;
}