#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
bool cmp(const string& a, const string& b);

int main() {
	string input[20000];
	string inputstr;
	int tnum;
	cin >> tnum;

	for (int i = 0; i<tnum; i++) {
		cin >> inputstr;
		input[i] = inputstr;
	}
	sort(input, input+tnum, cmp);
	string check = input[0];
	cout << check << endl;
	for (int i = 1; i<tnum; i++) {
		if (check != input[i]) {
			cout << input[i] << endl;
			check = input[i];
		}
	}
	system("pause");
	return 0;
}

bool cmp(const string& a, const string& b) {
	if (a.length() == b.length()) return a < b;
	else return a.length() < b.length();
}