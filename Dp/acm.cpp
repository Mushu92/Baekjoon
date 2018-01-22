#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main() {
	int round;
	cin >> round;
	vector<int> resvec;

	for (int i = 0; i < round; i++) {
		int house, rules, in[1001] = { 0 };//in은 들어오는 건물의 총수(위상 정렬에 이용)
		cin >> house >> rules;
		vector<vector<int> > warr;//위상정렬용
		priority_queue<int> pq;//위상정렬용
		int *cost = new int[house + 1];//건물 소요 시간
		int *res = new int[house + 1];//결과 시간
		warr.resize(house + 1);
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
			vector<int> insert;
			//위상정렬
			warr[p].push_back(l);
			in[l]++;
		}
		for (int j = 1; j <= house; j++) {
			if (!in[j]) pq.push(-j);
		}
		while (pq.size()) {
			int here1 = -pq.top();
			pq.pop();
			for (int j = 0; j < warr[here1].size(); j++) {
				int here2 = warr[here1][j];
				if (res[here2] < res[here1] + cost[here2]) {
					res[here2] = res[here1] + cost[here2];
				}
				in[here2]--;
				if (!in[here2]) pq.push(-here2);
			}
		}
		int fwin;//승리조건
		cin >> fwin;
		resvec.push_back(res[fwin]);
	}
	for (int i = 0; i < resvec.size(); i++) {
		cout << resvec[i] << endl;
	}
	//system("pause");
	return 0;
}