#include<iostream>

using namespace std;

int* Sort(int* arrnum,int numsize);

int main() {
	int num;
	cin >> num;
	//동적할당
	int* arrnum = new int[num];
	for (int i = 0; i < num; ++i) {
		int inum;
		cin >> inum;
		arrnum[i] = inum;
	}
	//오름차순 정리
	arrnum = Sort(arrnum,num);
	//출력
	for (int i = 0; i < num; i++) {
		cout << arrnum[i] << endl;
	}
	//메모리 정리
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