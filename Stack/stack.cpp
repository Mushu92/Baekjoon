#include<iostream>
#include<string>

using namespace std;

template<typename T> class stack {
private:
	T* arr;//배열
	int arrsize;//배열길이
	int index;//저장 index
public:
	stack<T>(int size) {
		this->arr = new T[size];
		this->arrsize = size;
		this->index = 0;
	}
	stack<T>() {
		this->arr = new T[10];//기본은 10으로 size를 잡는다
		this->arrsize = 10;
		this->index = 0;
	}
	void push(T element) {
		if (index == arrsize) {//arr가 꽉차있으면 2배로 늘려주기
			//빈 배열에 현재 배열 복사
			T* temp = new T[index];
			for (int i = 0; i < index; i++) {
				temp[i] = arr[i];
			}
			//사이즈를 늘려서 배열 생성
			arrsize *= arrsize;
			arr = new T[arrsize * 2];
			//기존의 배열 복사
			for (int i = 0; i < index; i++) {
				arr[i] = temp[i];
			}
			delete[] temp;
		}
		arr[index] = element;
		index++;
	}
	T pop() {//제일 뒤의 값 반환, 제거
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
	int size() {//갯수 반환
		return index;
	}

	bool empty() {//비어있다면 return 1, 아니면 0
		if (index == 0) return 1;
		else return 0;
	}

	T top() {//제일 위의 값 반환
		if (index == 0) return - 1;
		else {
			return arr[index - 1];
		}
	}
	~stack()//소멸
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