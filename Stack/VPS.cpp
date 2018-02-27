#include<iostream>
#include<string>
#include<stack>

using namespace std;
bool CheckVPS(string str);
int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		//string �Է�
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
		//'('�� ������ push
		if (str[j] == '(') cstc.push(str[j]);

		else {//')'��� 
			//���ÿ� '('�� �ִٸ� �ϳ� ����
			if (!cstc.empty()) cstc.pop();
			else {//���� ����� "NO"�� ���� �Ϸ�
				return 0;
			}
		}
	}
	//�ݺ��� ���� ������ ����ִٸ� "YES"
	return cstc.empty();
}