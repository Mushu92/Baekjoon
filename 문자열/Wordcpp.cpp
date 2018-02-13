#include<iostream>
#include<string>
#include<cstring>
#include<string.h>

using namespace std;

int main() {
	//문자열 입력
	string s;
	//cin>>s는 공백을 포함해서 한줄을 받을 수 없기 때문에 이렇게 사용
	getline(cin, s);
	//토큰 분리를 위해서 문자열을 배열에 복사
	char* buf = new char[s.size() + 1];
	strcpy(buf, s.c_str());
	//토큰 분리
	char* context = NULL;
	char * token = strtok(buf, " ");
	int count = 0;
	while (token) {
		count++;
		token = strtok(NULL, " ");
	}
	cout << count << endl;
	//system("pause");
	return 0;
}