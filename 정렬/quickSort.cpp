#include<iostream>

using namespace std;

void quickSort(int* inputarr, int low, int high);
int partition(int* inputarr, int low, int high);

int main() {
	int num;
	cin >> num;
	//Init
	int* inputarr = new int[num];
	for (int i = 0; i < num; i++) {
		int inum;
		cin >> inum;
		inputarr[i] = inum;
	}
	//퀵 소팅
	quickSort(inputarr, 0, num - 1);
	//출력
	for (int i = 0; i < num; i++) {
		cout << inputarr[i] << "\n";
	}
	delete[] inputarr;
	system("pause");
	return 0;
}

void quickSort(int* inputarr, int low, int high) {

	if (high > low) {
		int pivotpoint = partition(inputarr, low, high);
		quickSort(inputarr, low, pivotpoint - 1);
		quickSort(inputarr, pivotpoint + 1, high);
	}
}

int partition(int* inputarr, int low, int high) {
	int j = low;
	int pivotpoint;
	int pivotitem = inputarr[low];
	for (int i = low + 1; i <= high; i++) {
		if (inputarr[i] < pivotitem) {
			j++;
			int temp = inputarr[j];
			inputarr[j] = inputarr[i];
			inputarr[i] = temp;
		}
	}
	pivotpoint = j;
	inputarr[low] = inputarr[j];
	inputarr[j] = pivotitem;
	return pivotpoint;
}