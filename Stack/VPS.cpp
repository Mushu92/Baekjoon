#include<iostream>
#include<string>
#include<stack>

using namespace std;

#define MAX_SIZE 100
int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		//string �Է�
		string inputstr;
		cin >> inputstr;
		int size = inputstr.length();
		bool flag=1;
		//stack
		stack<char> cstc;
		for (int j = 0; j < size; j++) {
			if (inputstr[j] == '(') cstc.push(inputstr[j]);

			else {//')'���
				if (!cstc.empty()) cstc.pop();
				else {
					flag = 0;//���� ��!
					break;
				}
			}
		}
		//�ݺ��� ���� ������ ����ִٸ� "YES"
		if(flag) flag = cstc.empty();
		//���
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
	system("pause");
	return 0;
}