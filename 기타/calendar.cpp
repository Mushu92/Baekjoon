#include<fstream>
#include<iostream>
#include<string>

using namespace std;

//달력
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
	fout << "일 월 화 수 목 금 토" << endl;


	int day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int days = 0;
	int first_date = 0;
	int count = 0;

	//날수 계산 if 2012라면 2011년 총 일수 계산
	days = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
	//2012 해당 month전 일수 계산
	for (int i = 0; i < month - 1; i++) {
		if (i == 1) {//윤년 확인
			if ((year % 4 == 0 && year % 100 != 0) | year % 400 == 0) day[1] = 29;
			else day[1] = 28;
		}
		days += day[i];
	}
	/*이전달 마지막 날 요일 확인 0:일 부터 쭉쭉*/
	first_date = days % 7;
	cout << first_date << endl;
	for (int i = 0; i <= first_date; i++) {
		fout << "   ";//해당 요일까지 빈칸처리
		count++;//7일 기준 다음줄로 넘기는 용도
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