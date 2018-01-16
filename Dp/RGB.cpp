#include<fstream>
#include<iostream>
#include<string>

using namespace std;
int Min(int a, int b);

int main() {
	int size;
	cin >> size;
	int **pay = new int *[size];//���� �� ĥ�ϴ� ���
	int **tpay = new int *[size];//�������� 
	for (int i = 0; i < size; i++) {
		pay[i] = new int[3];
		tpay[i] = new int[3];
	}
	//�򺰷� ��� �߰�
	int paycolor;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> paycolor;
			pay[i][j] = paycolor;
		}
	}

	for (int i = 0; i < size; i++) {
		if (i == 0) {
			tpay[i][0] = pay[i][0];
			tpay[i][1] = pay[i][1];
			tpay[i][2] = pay[i][2];
		}
		else {
			tpay[i][0] = Min(tpay[i - 1][1], tpay[i - 1][2]) + pay[i][0];
			tpay[i][1] = Min(tpay[i - 1][0], tpay[i - 1][2]) + pay[i][1];
			tpay[i][2] = Min(tpay[i - 1][0], tpay[i - 1][1]) + pay[i][2];
		}
	}
	cout << Min(tpay[size - 1][2], (Min(tpay[size - 1][0], tpay[size - 1][1]))) << endl;
	system("pause");
	return 0;	
}

int Min(int a, int b) {
	if (a < b) return a;
	else return b;
}