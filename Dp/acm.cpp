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
		int *cost = new int[house + 1];//�ǹ� �ҿ� �ð�
		int *res = new int[house + 1];//��� �ð�
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
			//��ȭ��
			if (res[l] < res[p] + cost[l]) res[l] = res[p] + cost[l];
		}
		int fwin;//�¸�����
		cin >> fwin;
		resvec.push_back(res[fwin]);
	}
	for (int i = 0; i < resvec.size(); i++) {
		cout << resvec[i] << endl;
	}
	system("pause");
	return 0;
}