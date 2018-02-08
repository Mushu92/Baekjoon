#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

vector<string>  Convert(char* buf,int inputSize);
void Print_ans(vector<string> strarr);

int main() {
	//����ǥ����� ����ǥ������� ��ȯ�ϰ� �� �� ����ǥ��� ������� ���!
	char buf[10000];
	vector<string> strarr;//����ǥ��� �����
	string InputString;
	cin >> InputString;
	int inputSize = InputString.size();
	for (int i = 0; i < inputSize; i++) {
		buf[i] = InputString.at(i);
	}
	//����ǥ��� -> ����ǥ���
	strarr = Convert(buf,inputSize);
	//����ǥ����� ������ ���
	Print_ans(strarr);
	system("pause");
	return 0;
}
//������ �켱 ���� 0����: *,/ 1����:+,- 2���� : (,)
// ( : ������ stack�� Ǫ��
// ������ : stack�� ������ �����ڰ� �ڽź��� ������ ���ų� ���ٸ� pop�ؼ� ���Ϳ� ���� �� Ǫ��
// ) : (�� ���� �� ���� pop�ؼ� ���Ϳ� ����
vector<string> Convert(char* buf,int inputSize) {
	vector<string> strarr;
	stack<char> stc;
	string num = "";
	for (int i = 0; i < inputSize; i++) {
		if (buf[i] == '(') stc.push(buf[i]);
		else if (buf[i] == '+' || buf[i] == '-') {
			if (num != "") {
				strarr.push_back(num);
				num = "";
			}
			if (!stc.empty()) {
				if (stc.top() == '*' || stc.top() == '/' || stc.top() == '+' || stc.top() == '-') {
					string s = "";
					s += stc.top();
					strarr.push_back(s);
					stc.pop();
					stc.push(buf[i]);
				}
				else stc.push(buf[i]);
			}
			else stc.push(buf[i]);
		}
		else if (buf[i] == '*' || buf[i] == '/') {
			if (num != "") {
				strarr.push_back(num);
				num = "";
			}
			if (!stc.empty()) {
				if (stc.top() == '*' || stc.top() == '/') {
					string s = "";
					s += stc.top();
					strarr.push_back(s);
					stc.pop();
					stc.push(buf[i]);
				}
				else stc.push(buf[i]);
			}
			else stc.push(buf[i]);
		}
		else if (buf[i] == ')') {
			if (num != "") {
				strarr.push_back(num);
				num = "";
			}
			while (stc.top() != '(') {
				string s = "";
				s += stc.top();
				strarr.push_back(s);
				stc.pop();
			}
			stc.pop();
		}
		else {
			num += buf[i];
			if (i == inputSize - 1) {
				strarr.push_back(num);
			}
		}
	}
	//stack�� �����ִ� ������ ó��
	while (!stc.empty()) {
		string s = "";
		s += stc.top();
		strarr.push_back(s);
		stc.pop();
	}
	return strarr;
}

// ������ ���
void Print_ans(vector<string> strarr) {
	stack<string> strstc;
	for (int i = 0; i < strarr.size(); i++) {
		if (strarr[i] == "+" || strarr[i] == "-" || strarr[i] == "*" || strarr[i] == "/") {
			string s1 = strstc.top();
			strstc.pop();
			string s2 = strstc.top();
			strstc.pop();
			s2 = "(" + s2 + strarr[i] + s1 + ")";
			strstc.push(s2);
		}
		else strstc.push(strarr[i]);
	}
	cout << strstc.top() << endl;
}