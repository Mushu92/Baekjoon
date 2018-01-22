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
		int house, rules, in[1001] = { 0 };//in�� ������ �ǹ��� �Ѽ�(���� ���Ŀ� �̿�)
		cin >> house >> rules;
		vector<vector<int> > warr;//�������Ŀ�
		priority_queue<int> pq;//�������Ŀ�
		int *cost = new int[house + 1];//�ǹ� �ҿ� �ð�
		int *res = new int[house + 1];//��� �ð�
		warr.resize(house + 1);
		cost[0] = res[0] = 0;
		//�ǹ� �ҿ�ð� �־��ֱ�
		for (int j = 1; j <= house; j++) {
			int hcost;
			cin >> hcost;
			cost[j] = res[j] = hcost;
		}
		//�� �־��ֱ�
		for (int j = 0; j < rules; j++) {
			int p, l;
			cin >> p >> l;
			vector<int> insert;
			//��������
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
		int fwin;//�¸�����
		cin >> fwin;
		resvec.push_back(res[fwin]);
	}
	for (int i = 0; i < resvec.size(); i++) {
		cout << resvec[i] << endl;
	}
	//system("pause");
	return 0;
}