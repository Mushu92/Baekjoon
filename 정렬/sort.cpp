#include<iostream>

using namespace std;

int* Sort(int* arrnum,int numsize);

int main() {
	int num;
	cin >> num;
	//�����Ҵ�
	int* arrnum = new int[num];
	for (int i = 0; i < num; ++i) {
		int inum;
		cin >> inum;
		arrnum[i] = inum;
	}
	//�������� ����
	arrnum = Sort(arrnum,num);
	//���
	for (int i = 0; i < num; i++) {
		cout << arrnum[i] << endl;
	}
	//�޸� ����
	delete[] arrnum;
	//system("pause");
	return 0;
}

int* Sort(int* arrnum,int numsize) {
	for (int i = 0; i < numsize; i++) {
		for (int j = i + 1; j < numsize; j++) {
			int temp;
			if (arrnum[i] > arrnum[j]) {
				temp = arrnum[i];
				arrnum[i] = arrnum[j];
				arrnum[j] = temp;
			}
		}
	}
	return arrnum;
}