#include<iostream>

using namespace std;
int Fibo(int num);

int main() {
	int num;
	cin >> num;
	cout << Fibo(num) << endl;
	system("pause");
	return 0;
}

int Fibo(int num) {
	int* numarray = new int[num+1];
	numarray[0] = 0;
	numarray[1] = 1;
	for (int i = 2; i <=num; i++) {
		numarray[i] = numarray[i - 2] + numarray[i - 1];
	}
	return numarray[num];
}