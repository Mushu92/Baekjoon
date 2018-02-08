#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int FlagCheck(char* buf, int Size);
int ConvertNum(int num);
bool Check16(int num);
int CalInt(char* buf, int Size, int flag);
float CalFloat(char* buf, int Size, int flag);

int main() {
	char buf[10000];
	//�Է�
	string InputString;
	cin >> InputString;
	int Size = InputString.size();
	for (int i = 0; i < Size; i++) {
		buf[i] = InputString.at(i);
	}

	int flag = FlagCheck(buf, Size);

	//���
	switch (flag) {
		case 1:
			if (Size - 2 > 8) {//��ȿ���� �Ѱ� ���°��
				cout << "Error" << endl;
				return 0;
			}
			else if (Size - 2 == 8) {//���,���� �Ǵ��ؾ��ϴ� ���
				int num = buf[2];
				if (Check16(num)) {//����
					buf[2] = num - 8;
					cout << -CalInt(buf, Size, flag) << endl;//���� ó��
				}
				else {//���
					cout << CalInt(buf, Size, flag) << endl;
				}
			}
			else {
				cout << CalInt(buf,Size,flag) << endl;
			}
			break;
			
		case 2:
			cout << CalInt(buf, Size, flag) << endl;
			break;
		case 3:
			cout << CalInt(buf, Size, flag) << endl;
			break;
		case 4:
			cout << -CalInt(buf, Size, flag) << endl;
			break;
		case 5:
			cout << CalFloat(buf, Size, flag) << endl;
			break;
		case 6:
			cout << -CalFloat(buf, Size, flag) << endl;
			break;
	}
	system("pause");
	return 0;
}

/* Flag�˻� ��� 1:16���� 2: 8���� 3: 10����(+) 4: 10����(-) 5:Float(+) 6: Float(-)*/
int FlagCheck(char* buf, int Size) {
	int flag;
	if (buf[0] == '0') {
		if (buf[1] == 'x') flag = 1;
		else flag = 2;
	}
	else {
		flag = 3;
		if (buf[0] == '-') flag = 4;
		for (int i = 0; i < Size; i++) {
			if (buf[i] == '.') {
				flag = 5;
				if (buf[0] == '-') {
					flag = 6;
				}
				break;
			}
		}
	}
	return flag;
}

/*Char�� int�� �ٲٱ� ���ؼ� �ƽ�Ű�� ��� 16������ ��쿡�� ������ϴ� ���� �޶���Ѵ�
  0~9 : -48, A~F = -55 */
int ConvertNum(int num) {
	if (num - 48 > 10) return num- 55;
	else return num - 48;
}

/*16������ ��� 32bit�� ��ȣ��Ʈ Ȯ��*/
bool Check16(int num) {
	num=ConvertNum(num);
	int binary = 0, count = 0;
	while (num) {
		binary = num % 2;
		num /= 2;
		count++;
	}
	if (count == 4 && binary == 1) return true;
	else return false;
}

//16����, 8����, 10���� ���
int CalInt(char* buf, int Size,int flag) {
	int result = 0;
	int calsize=0;
	int mult=0;
	switch (flag) {
		case 1:
			calsize += 2;
			mult = 16;
			break;
		case 2:	
			mult = 8;
			break;
		case 3:
			mult = 10;
			if (buf[0] == '+') {
				calsize++;
			}
			break;
		case 4:
			mult = 10;
			calsize ++;
			break;
	}
	for (int i = Size - 1; i >= calsize; --i) {
		int cton = buf[i];
		cton = ConvertNum(cton);
		//�ڸ��� ���� 10���� ��ȯ
		int cres = 1;
		for (int j = 0; j < Size - i - 1; j++) {
			cres *= mult;
		}
		result += cton*cres;
	}
	return result;
}

//Float�� ���
float CalFloat(char* buf, int Size, int flag) {
	char front[100],behind[100];
	int frontSize = 0, behindSize = 0, calsize =1 ;
	float fresult = 0;

	if (flag == 5) {
		if (buf[0] != '+') calsize--;
	}

	for (int i = 0; i < Size; i++) {
		if (buf[i] == '.') {
			for (int j = 0; j < i; j++) {
				front[j] = buf[j];
				frontSize++;
			}
			for (int j = i + 1; j < Size; j++) {
				behind[j - i - 1] = buf[j];
				behindSize++;
			}
		}
	}

	for (int i = frontSize - 1; i >= calsize; --i) {
		int cton = front[i];
		cton = ConvertNum(cton);
		//�ڸ��� ���� 10���� ��ȯ
		float cres = 1.0;
		for (int j = 0; j < frontSize - i - 1; j++) {
			cres *= 10.0;
		}
		fresult += cton*cres;
	}
	for (int i = behindSize - 1; i >= 0; --i) {
		int cton = behind[i];
		if (cton - 48 > 10) cton -= 55;
		else cton -= 48;
		//�ڸ��� ���� 10���� ��ȯ
		float cres = 0.1;
		for (int j = 0; j < behindSize - i - 1; j++) {
			cres /= 10.0;
		}
		fresult += cton*cres;
	}
	return fresult;
}