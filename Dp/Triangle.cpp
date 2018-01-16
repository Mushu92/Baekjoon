#include<iostream>
#include<string>

using namespace std;
int Max(int a, int b);

int main() {
	int size;
	cin >> size;
	int** arr = new int*[size];
	int** res = new int*[size];
	//메모리 할당
	for (int i = 0; i < size; i++) {
		arr[i] = new int[size];
		res[i] = new int[size];
	}
	//cost
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int cost;
			if (i >= j) {
				cin >> cost;
				arr[i][j] = cost;
			}
			else break;
		}
	}
	//계산
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == 0) res[i][j] = arr[i][j];
			else {
				if (j == 0) res[i][j] = res[i - 1][j] + arr[i][j];
				else if (i == j) {
					res[i][j] = res[i - 1][j - 1] + arr[i][j];
					break;
				}
				else res[i][j] = Max(res[i - 1][j - 1], res[i - 1][j]) + arr[i][j];
			}
		}
	}
	//결과
	int max = res[size-1][0];
	for (int i = 1; i < size; i++) {
		if (res[size - 1][i] > max) max = res[size - 1][i];
	}
	cout << max << endl;
	return 0;
}

int Max(int a, int b) {
	if (a > b) return a;
	else return b;
}