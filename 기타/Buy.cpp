#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> arr;
	vector<long> db(2000001,0);
	db[1] = 1;
	int Tc;
	cin >> Tc;

	/*�׽�Ʈ ���̽�*/
	for (int i = 0; i < Tc; ++i) {
		int day;
		cin >> day;
		arr.push_back(day);
	}
	/*solve*/
	for (int i = 0; i < arr.size(); i++) {
		int size = arr[i];
		int result = 0;
		/*db���� �̹� �ִ� ���̸� �ٷ� ���*/
		if (db[size] != 0) result = db[size];
		else {
			/*�𸣴� ���̸� ��� �ϸ鼭 db���� �߰�*/
			for (int i = 1; i <= size; ++i) {
				/*¦�� ���*/
				if (i % 2 == 0) db[i] = result;
				else {/*Ȧ�� ���*/
					result += i;
					db[i] = result;
				}
			}
		}
		cout << result << endl;
	}
	system("pause");
	return 0;
}