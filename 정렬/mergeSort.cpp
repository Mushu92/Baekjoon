#include<iostream>

using namespace std;

void mergeSort(int *inputarr, int left, int right, int arrsize);
void merge(int *inputarr, int left, int mid, int right, int arrsize);


int main() {
	ios::sync_with_stdio(false);
	int num;
	cin >> num;
	//�����Ҵ�
	int* arrnum = new int[num];
	for (int i = 0; i < num; ++i) {
		int inum;
		cin >> inum;
		arrnum[i] = inum;
	}
	mergeSort(arrnum, 0, num - 1, num);
	//���
	for (int i = 0; i < num; ++i) {
		cout << arrnum[i] << endl;
	}
	//�޸� ����
	delete[] arrnum;
	//system("pause");
	return 0;
}

void mergeSort(int *inputarr, int left, int right, int arrsize) {
	//��� �������� �İ��
	if (left < right) {//������ ����
		int mid = (left + right) / 2;
		mergeSort(inputarr, left, mid, arrsize);//����(���� Index)~�߾�
		mergeSort(inputarr, mid + 1, right, arrsize);//�߾�~������(������ Index)
		merge(inputarr, left, mid, right, arrsize);//�պ�
	}
}
void merge(int *inputarr, int left, int mid, int right, int arrsize) {
	int i = left; // ���� �迭 ����
	int j = mid + 1;//������ �迭 ����
	int k = left;//�ӽ� �迭�� ����
	int* temp_arr = new int[arrsize];

	//�պ� ����
	while (i <= mid && j <= right) {
		if (inputarr[i] <= inputarr[j]) temp_arr[k++] = inputarr[i++];
		else temp_arr[k++] = inputarr[j++];
	}
	//�� �� �ϳ��� ���� ������
	if (i > mid) {//�������� ���� ���
				  //������� temp_arr�� ����
		for (int m = j; m <= right; ++m) {
			temp_arr[k++] = inputarr[m];
		}
	}
	else {//������ ���� ���
		for (int m = i; m <= mid; ++m) {
			temp_arr[k++] = inputarr[m];
		}
	}
	//���� �迭�� ����
	for (int m = left; m <= right; ++m) {
		inputarr[m] = temp_arr[m];
	}
	delete[] temp_arr;
}