#include<iostream>
#include<string>

using namespace std;

int main() {
	string inputstr;
	cin >> inputstr;
	int alpha[26] = { 0 }; //개수 저장
	//전부 대문자 변환, 갯수 증가
	for (int i = 0; i < inputstr.size(); i++) {
		inputstr[i] = toupper(inputstr[i]);
		int index = (int)inputstr[i] - 65;
		alpha[index]++;
	}
	// 최대 알파벳 확인
	int Max = alpha[0];
	int index=0;//출력용
	bool flag = 0;//? 찍기위함
	for (int i = 1; i < 26; i++) {
		if (alpha[i] > Max) {
			Max = alpha[i];
			index = i;
			flag = 0;
		}
		else if (Max != 0 && alpha[i] == Max) {
			flag = 1;
		}
	}
	if (flag != 1) cout << (char)(index + 65) << endl;
	else cout << "?" << endl;
	system("pause");
	return 0;
}