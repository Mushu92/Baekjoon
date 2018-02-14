#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void radixSort(vector<int> inputarr, int num);
int calindex(int input, int t);


int main() {
	vector<int> inputnum;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int input;
		cin >> input;
		inputnum.push_back(input);
	}
	radixSort(inputnum, 5);
	system("pause");
	return 0;
}

void radixSort(vector<int> inputarr, int num) {
	vector<queue<int> > sortarr(10);
	for (int i = 0; i < num; i++) {
		//자리수에 맞게 queue에 넣음
		for (int j = 0; j < inputarr.size(); j++) {
			int index = calindex(inputarr[j], i);
			sortarr[index].push(inputarr[j]);
		}
		inputarr.clear();
		//배열에 꺼냄
		for (int j = 0; j < sortarr.size(); j++) {
			if (sortarr[j].size() > 0) {
				while (!sortarr[j].empty()) {
					int a = sortarr[j].front();
					inputarr.push_back(a);
					sortarr[j].pop();
				}
			}
		}
	}
	for (int i = 0; i < inputarr.size(); i++) {
		cout << inputarr[i] << "\n";
	}
}

int calindex(int input, int t) {
	int count = 0;
	int result;
	while (count <= t) {
		result = input % 10;
		input /= 10;
		count++;
	}
	return result;
}