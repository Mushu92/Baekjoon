#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> arr;
	vector<long> db(2000001,0);
	db[1] = 1;
	int Tc;
	cin >> Tc;

	/*테스트 케이스*/
	for (int i = 0; i < Tc; ++i) {
		int day;
		cin >> day;
		arr.push_back(day);
	}
	/*solve*/
	for (int i = 0; i < arr.size(); i++) {
		int size = arr[i];
		int result = 0;
		/*db내에 이미 있는 값이면 바로 사용*/
		if (db[size] != 0) result = db[size];
		else {
			/*모르는 값이면 계산 하면서 db내용 추가*/
			for (int i = 1; i <= size; ++i) {
				/*짝수 경우*/
				if (i % 2 == 0) db[i] = result;
				else {/*홀수 경우*/
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