#include<iostream>
#include<string>

using namespace std;
int Max(int a, int b);

int main() {
	int size;
	cin >> size;
	int *cost = new int[size];
	int *res = new int[size];
	//비용 넣어주기
	for (int i = 0; i < size; i++) {
		int score;
		cin >> score;
		cost[i] = score;
	}
	//점화식을 만족시키기 위해 초기화 해야하는 값들
	res[0] = cost[0];
	res[1] = Max(cost[0] + cost[1], cost[1]);
	res[2] = Max(cost[0] + cost[2], cost[1] + cost[2]);

	for (int i = 3; i < size; i++) {
		//점화식
		res[i] = Max(res[i - 2] + cost[i], res[i - 3] + cost[i - 1] + cost[i]);
		}
	cout << res[size - 1] << endl;
	return 0;
}

int Max(int a, int b) {
	if (a > b) return a;
	else return b;
}