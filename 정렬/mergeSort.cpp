#include<iostream>

using namespace std;

void mergeSort(int *inputarr, int left, int right, int arrsize);
void merge(int *inputarr, int left, int mid, int right, int arrsize);


int main() {
	ios::sync_with_stdio(false);
	int num;
	cin >> num;
	//동적할당
	int* arrnum = new int[num];
	for (int i = 0; i < num; ++i) {
		int inum;
		cin >> inum;
		arrnum[i] = inum;
	}
	mergeSort(arrnum, 0, num - 1, num);
	//출력
	for (int i = 0; i < num; ++i) {
		cout << arrnum[i] << endl;
	}
	//메모리 정리
	delete[] arrnum;
	//system("pause");
	return 0;
}

void mergeSort(int *inputarr, int left, int right, int arrsize) {
	//재귀 형식으로 파고들어감
	if (left < right) {//끝나는 조건
		int mid = (left + right) / 2;
		mergeSort(inputarr, left, mid, arrsize);//왼쪽(시작 Index)~중앙
		mergeSort(inputarr, mid + 1, right, arrsize);//중앙~오른쪽(마지막 Index)
		merge(inputarr, left, mid, right, arrsize);//합병
	}
}
void merge(int *inputarr, int left, int mid, int right, int arrsize) {
	int i = left; // 왼쪽 배열 시작
	int j = mid + 1;//오른쪽 배열 시작
	int k = left;//임시 배열에 저장
	int* temp_arr = new int[arrsize];

	//합병 시작
	while (i <= mid && j <= right) {
		if (inputarr[i] <= inputarr[j]) temp_arr[k++] = inputarr[i++];
		else temp_arr[k++] = inputarr[j++];
	}
	//둘 중 하나가 먼저 끝나면
	if (i > mid) {//오른쪽이 남은 경우
				  //순서대로 temp_arr에 저장
		for (int m = j; m <= right; ++m) {
			temp_arr[k++] = inputarr[m];
		}
	}
	else {//왼쪽이 남은 경우
		for (int m = i; m <= mid; ++m) {
			temp_arr[k++] = inputarr[m];
		}
	}
	//원본 배열에 복사
	for (int m = left; m <= right; ++m) {
		inputarr[m] = temp_arr[m];
	}
	delete[] temp_arr;
}