#include<fstream>
#include<iostream>
#include<string>

using namespace std;

//�޷�
int main() {
	ofstream fout("test.txt");
	cout << ">Input Year" << endl;
	int year, month;
	cin >> year;
	cout << ">Input Month" << endl;
	cin >> month;
	fout << "<" << year << "-";
	fout.fill('0');
	fout.width(2);
	fout << month << ">" << endl;
	fout << "�� �� ȭ �� �� �� ��" << endl;


	int day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int days = 0;
	int first_date = 0;
	int count = 0;

	//���� ��� if 2012��� 2011�� �� �ϼ� ���
	days = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
	//2012 �ش� month�� �ϼ� ���
	for (int i = 0; i < month - 1; i++) {
		if (i == 1) {//���� Ȯ��
			if ((year % 4 == 0 && year % 100 != 0) | year % 400 == 0) day[1] = 29;
			else day[1] = 28;
		}
		days += day[i];
	}
	/*������ ������ �� ���� Ȯ�� 0:�� ���� ����*/
	first_date = days % 7;
	cout << first_date << endl;
	for (int i = 0; i <= first_date; i++) {
		fout << "   ";//�ش� ���ϱ��� ��ĭó��
		count++;//7�� ���� �����ٷ� �ѱ�� �뵵
	}
	for (int i = 1; i <= day[month - 1]; i++) {
		if (count >= 7) {
			fout << endl;
			count = 0;
		}
		fout.fill(' ');
		fout.width(2);
		fout << i <<" ";
		count++;
	}
	fout << endl;
	system("pause");
	return 0;
}