#include<iostream>
#include<cstdio>

using namespace std;

int main() {
	bool* PrimeArray;
	int M, N;
	scanf("%d %d",&M, &N);

	PrimeArray = new bool[N+1];
	//�迭 �ʱ�ȭ
	for (int i = 2; i <= N; i++) PrimeArray[i] = true;

	//�����佺�׳׽��� ü�� �°� �Ҽ��� ����
	for (int i = 2; (i*i) <= N; i++) {
		if (PrimeArray[i])
		{
			for (int j = i * i; j <= N; j += i) PrimeArray[j] = false;
		}
	}
	//���
	for (int i = M; i <= N; i++) {
		if (PrimeArray[i]) printf("%d\n",i);
	}
	system("pause");
	return 0;
}