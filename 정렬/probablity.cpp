#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main() {
	int tcase, input;
	cin >> tcase;
	vector<int> inarr;
	vector<int> formid;
	vector<int> num;
	vector<int>::iterator iter;

	int sum = 0;
	for (int i = 0; i < tcase; i++) {
		cin >> input;
		sum += input;//������ ����
		formid.push_back(input);
		iter = find(inarr.begin(), inarr.end(),input);
		if (iter == inarr.end()) {
			inarr.push_back(input);
			num.push_back(1);
		}
		else {
			int index = iter - inarr.begin();
			num[index]++;
		}
	}
	//������  ���
	float sansul = floor(sum/(float)tcase + 0.5);
	//�ֺ� ���
	int Max = num[0];
	int Maxnum = inarr[0];
	int Min1 = inarr[0];
	int Min2 = NULL;
	for (int i = 1; i < num.size(); i++) {
		if (num[i] > Max) {
			Max = num[i];
			Min1 = inarr[i];
			Min2 = NULL;
		}
		else if (num[i] == Max) {
			if (inarr[i] < Min1) {
				int temp = Min1;
				Min1 = inarr[i];
				Min2 = temp;
			}
			else {
				if (Min2 == NULL) Min2 = inarr[i];
				else if (inarr[i] < Min2) {
					Min2 = inarr[i];
				}
			}
		}
	}
	//Min2�� NULL�̸� Min1�� �ֺ� Min2�� NULL�� �ƴ϶�� Min2
	//�߾Ӱ�, ����
	sort(formid.begin(), formid.end());
	int mid = formid[ceil(formid.size() / 2)];
	int bum = formid[formid.size() - 1] - formid[0];
	cout << sansul << endl;
	cout << mid << endl;
	if (Min2 != NULL)cout << Min2 << endl;
	else cout << Min1 << endl;
	cout << bum << endl;
	
 	system("pause");
	return 0;
}