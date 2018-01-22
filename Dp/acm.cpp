#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int round;
	cin >> round;
	vector<int> resvec;

	for (int i = 0; i < round; i++) {
		int house, rules;
		cin >> house >> rules;
		int *cost = new int[house + 1];//건물 소요 시간
		int *res = new int[house + 1];//결과 시간
		cost[0] = res[0] = 0;
		//건물 소요시간 넣어주기
		for (int j = 1; j <= house; j++) {
			int hcost;
			cin >> hcost;
			cost[j] = res[j] = hcost;
		}
		//룰 넣어주기
		for (int j = 0; j < rules; j++) {
			int p, l;
			cin >> p >> l;
			//점화식
			if (res[l] < res[p] + cost[l]) res[l] = res[p] + cost[l];
		}
		int fwin;//승리조건
		cin >> fwin;
		resvec.push_back(res[fwin]);
	}
	for (int i = 0; i < resvec.size(); i++) {
		cout << resvec[i] << endl;
	}
	system("pause");
	return 0;
}