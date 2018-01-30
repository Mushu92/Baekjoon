#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector<int> result;
	int num;
	cin >> num;
	while (num > 0) {
		result.push_back(num % 2);
		num /= 2;
	}
	for (int i = result.size()-1; i >= 0; --i) {
		cout << result[i];
	}
	cout << endl;
	system("pause");
	return 0;
}