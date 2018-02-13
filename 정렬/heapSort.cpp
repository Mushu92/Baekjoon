#include<iostream>

using namespace std;
class heap {
private:
	int heapindex = 0;
	int* heaparr;
public:
	heap(int heapSize) {
		this->heaparr = new int[heapSize+1];
	}
	void insert(int element) {
		heapindex++;
		heaparr[heapindex] = element;

		//부모가 자식보다 큰 경우 swap
		int cur = heapindex;
		while (cur / 2 != 0 && heaparr[cur / 2] > element) {
			int temp = element;
			heaparr[cur] = heaparr[cur / 2];
			cur /= 2;
		}
		//최종 자리
		heaparr[cur] = element;
	}
	void sort() {
		while (heapindex != 0) {
			//root = 제일 최소
			cout << heaparr[1] << "\n";//out!
			int cur = heaparr[heapindex];
			heapindex--;
			switch (heapindex) {
			case 1:
				heaparr[1] = heaparr[2];
				break;
			case 2:
				if (heaparr[2] < cur) {
					heaparr[1] = heaparr[2];
					heaparr[2] = cur;
				}
				else heaparr[1] = cur;
				break;
			default:
				int parent = 1;
				int child = parent * 2;
				while (child <= heapindex) {
					if (heaparr[child] > heaparr[child + 1]) child++;

					if (heaparr[child] < cur) {
						heaparr[child / 2] = heaparr[child];
						heaparr[child] = cur;
					}
					else {
						heaparr[child / 2] = cur;
						break;
					}
					child *= 2;
				}
			}
		}
	}
};

int main() {
	int num;
	cin >> num;
	heap h = heap(num);
	for (int i = 0; i < num; i++) {
		int input;
		cin >> input;
		h.insert(input);
	}
	h.sort();
	system("pause");
	return 0;
}