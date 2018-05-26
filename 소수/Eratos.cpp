#include<iostream>
#include<cstdio>

using namespace std;

int main() {
	bool* PrimeArray;
	int M, N;
	scanf("%d %d",&M, &N);

	PrimeArray = new bool[N+1];
	//배열 초기화
	for (int i = 2; i <= N; i++) PrimeArray[i] = true;

	//에라토스테네스의 체에 맞게 소수를 구함
	for (int i = 2; (i*i) <= N; i++) {
		if (PrimeArray[i])
		{
			for (int j = i * i; j <= N; j += i) PrimeArray[j] = false;
		}
	}
	//출력
	for (int i = M; i <= N; i++) {
		if (PrimeArray[i]) printf("%d\n",i);
	}
	system("pause");
	return 0;
}