#include<iostream>

using namespace std;

void countingSort(int* countarr, int num);

int main() {
	int num;
	cin >> num;
	int countarr[10001] = { 0 };
	for (int i = 0; i < num; i++) {
		int inputnum;
		cin >> inputnum;
		countarr[inputnum]++;
	}	
	countingSort(countarr, num);
	system("pause");
	return 0;
}

void countingSort(int* countarr, int trynum) {
	for (int i = 0; i <= 10000; i++) {
		if (countarr[i] != 0) {
			int size = countarr[i];
			while (size > 0) {
				cout << i << "\n";
				size--;
			}
		}
	}
}