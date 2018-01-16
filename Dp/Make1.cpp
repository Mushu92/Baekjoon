#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int num;
	cin >> num;
	vector<vector<int> > res;
	vector<int> arr;
	int i = 0;
	arr.push_back(num);
	res.push_back(arr);
	while (1) {
		arr.clear();
		for (int h = 0; h < res[i].size(); ++h) {
			if (res[i][h] % 3 == 0) arr.push_back(res[i][h] / 3);
			else if (res[i][h] % 2 == 0) arr.push_back(res[i][h] / 2);
			arr.push_back(res[i][h] - 1);
		}
		res.push_back(arr);
		vector<int>::iterator iter;
		iter = find(res[i].begin(), res[i].end(), 1);
		if (iter != res[i].end()) {
			cout << i << endl;
			break;
		}
		i++;
	}
	return 0;
}