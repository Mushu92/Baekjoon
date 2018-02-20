#include<iostream>
#include<string>

using namespace std;

template<typename T> class stack {
private:
	T* arr;//�迭
	int arrsize;//�迭����
	int index;//���� index
public:
	stack<T>(int size) {
		this->arr = new T[size];
		this->arrsize = size;
		this->index = 0;
	}
	stack<T>() {
		this->arr = new T[10];//�⺻�� 10���� size�� ��´�
		this->arrsize = 10;
		this->index = 0;
	}
	void push(T element) {
		if (index == arrsize) {//arr�� ���������� 2��� �÷��ֱ�
			//�� �迭�� ���� �迭 ����
			T* temp = new T[index];
			for (int i = 0; i < index; i++) {
				temp[i] = arr[i];
			}
			//����� �÷��� �迭 ����
			arrsize *= arrsize;
			arr = new T[arrsize * 2];
			//������ �迭 ����
			for (int i = 0; i < index; i++) {
				arr[i] = temp[i];
			}
			delete[] temp;
		}
		arr[index] = element;
		index++;
	}
	T pop() {//���� ���� �� ��ȯ, ����
		if (index == 0) {
			return -1;
		}
		else {
			T arrtop = arr[index-1];
			arr[index-1] = NULL;
			index--;
			return arrtop;
		}
	}
	int size() {//���� ��ȯ
		return index;
	}

	bool empty() {//����ִٸ� return 1, �ƴϸ� 0
		if (index == 0) return 1;
		else return 0;
	}

	T top() {//���� ���� �� ��ȯ
		if (index == 0) return - 1;
		else {
			return arr[index - 1];
		}
	}
	~stack()//�Ҹ�
	{
		delete[] arr;
	}
};

int main() {
	int num;
	cin >> num;
	stack<int> mystack;

	for (int i = 0; i < num; i++) {
		string s;
		cin >> s;
		if (s == "push") {
			int inputnum;
			cin >> inputnum;
			mystack.push(inputnum);
		}
		else if (s == "top") cout << mystack.top() << "\n";
		else if (s == "empty") cout << mystack.empty() << "\n";
		else if (s == "pop") cout << mystack.pop() << "\n";
		else if (s == "size") cout << mystack.size() << "\n";;
	}
	system("pause");
	return 0;
}