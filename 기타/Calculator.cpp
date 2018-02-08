#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

vector<string>  Convert(char* buf,int inputSize);
void Print_ans(vector<string> strarr);

int main() {
	//중위표기식을 후위표기식으로 변환하고 그 후 후위표기식 순서대로 계산!
	char buf[10000];
	vector<string> strarr;//후위표기식 저장용
	string InputString;
	cin >> InputString;
	int inputSize = InputString.size();
	for (int i = 0; i < inputSize; i++) {
		buf[i] = InputString.at(i);
	}
	//중위표기식 -> 후위표기식
	strarr = Convert(buf,inputSize);
	//후위표기법을 가지고 출력
	Print_ans(strarr);
	system("pause");
	return 0;
}
//연산자 우선 순위 0순위: *,/ 1순위:+,- 2순위 : (,)
// ( : 무조건 stack에 푸시
// 연산자 : stack의 마지막 연산자가 자신보다 순위가 높거나 같다면 pop해서 벡터에 저장 후 푸시
// ) : (를 만날 때 까지 pop해서 벡터에 저장
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
	//stack에 남아있는 연산자 처리
	while (!stc.empty()) {
		string s = "";
		s += stc.top();
		strarr.push_back(s);
		stc.pop();
	}
	return strarr;
}

// 계산과정 출력
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