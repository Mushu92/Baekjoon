#include<iostream>
#include<string>
#include<cstring>
#include<string.h>

using namespace std;

int main() {
	//���ڿ� �Է�
	string s;
	//cin>>s�� ������ �����ؼ� ������ ���� �� ���� ������ �̷��� ���
	getline(cin, s);
	//��ū �и��� ���ؼ� ���ڿ��� �迭�� ����
	char* buf = new char[s.size() + 1];
	strcpy(buf, s.c_str());
	//��ū �и�
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