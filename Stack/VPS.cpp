#include<iostream>
#include<string>
#include<stack>
#include<string.h>

using namespace std;

#define MAX_SIZE 100
int main() {
	int num;
	cin >> num;
	string* res = new string[num];
	int index = 0;
	for (int i = 0; i < num; i++) {
		//string 입력
		char input[MAX_SIZE];
		cin >> input;
		int size = strlen(input);
		//stack
		stack<char> cstc;
		for (int j = 0; j < size; j++) {
			if (input[j] == '(') cstc.push(input[j]);

			else if (input[j] == ')') {
				int count = 0;
				if (!cstc.empty()) {
					while (cstc.top() != '(') {
						count++;
						cstc.pop();
					}
					cstc.pop();
					while (count > 0) {
						cstc.push(')');
						count--;
					}
				}
				else cstc.push(input[j]);
			}
		}
		if (cstc.empty()) res[index++] = "YES";
		//'('가 남아있는 경우
		else res[index++] = "NO";
	}
	//출력
	for (int i = 0; i < index; i++) {
		cout << res[i] << endl;
	}
	delete[] res;
	system("pause");
	return 0;
}