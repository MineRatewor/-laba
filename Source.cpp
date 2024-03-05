#include<iostream>
#include<iomanip>
using namespace std;

struct Node {
	int data;
	int index;
};

void input(Node*, int, int, int, int);
void print(Node*, int);
Node* getList(Node*, int, Node*,  int, int);
int getSize(Node*, int, Node*, int);
void main() {
	setlocale(LC_ALL, "RU");
	int n;
	cout << "Пожалуйста,введите количество элементов списка l1: " << endl; cin >> n;
	Node* l1 = new Node[n]{ 0 };
	int beginL1 = 0; int endL1 = 0;
	cout << "Вводите элементы списка l1:" << endl;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		input(l1, beginL1, endL1, n, num);
		endL1++;
	}
	cout << endl << "Список l1:" << endl;
	print(l1, n); cout << endl;

	int k = 0; int beginL2 = 0; int endL2 = 0;
	cout << "Пожалуйста,введите количество элементов списка l2: " << endl; cin >> k;
	Node* l2 = new Node[k]{};
	cout << "Введите элементы списка l2:" << endl;
	for (int i = 0; i < k; i++) {
		int num; cin >> num;
		input(l2, beginL2, endL2, k, num);
		endL2++;
	}
	cout << endl << "Список l2:" << endl;
	print(l2, k); cout << endl;
	int size = getSize(l1, n, l2, k); cout << size;
	Node* list = getList(l1, n, l2, k, size);
	cout << endl << "Список L:" << endl;
	print(list, size);
	

	delete[] l2;
	delete[] l1;
}
void input(Node* list, int begin, int end, int n, int data) {
	if (begin == end) {
		list[begin].data = data;
		list[begin].index = begin + 1;

	}
	else {
		if (end == n - 1) {
			list[end].data = data;
			list[end].index = begin;
		}
		else {
			list[end].data = data;
			list[end].index = end + 1;
			
		}

	}
}
void print(Node* list, int n) {
	for (int i = 0; i < n; i++) {
		cout << setw(3) << list[list[i].index].data;
	}
}

int getSize(Node*l1, int n, Node*l2, int k) {
	int size = 0;
	for (int i = 0; i < n; i++) {
		int flot = 0;
		for (int j = 0; j < k; j++) {
			if (l1[i].data == l2[j].data) {
				flot++;
			}
		}
		if (flot == 0) {
			size++;
		}
	}

	for (int i = 0; i < k; i++) {
		int flot = 0;
		for (int j = 0; j < n; j++) {
			if (l2[i].data == l1[j].data) {
				flot++;
			}
		}
		if (flot == 0) {
			size++;
		}
	}
	return size;
}
Node* getList(Node* l1, int n, Node* l2, int k, int size) {
	
	Node* list = new Node[size];
	int l = 0; 
	for (int i = 0; i < n; i++) {
		int flot = 0; 
		for (int j = 0; j < k; j++) {
			if (l1[i].data == l2[j].data) {
				flot++;
			}
		}
		if (flot == 0) {
			if (l == size - 1) {
				list[l].data = l1[i].data;
				list[l].index = 0;
				break;
			}
			else {
				list[l].data = l1[i].data;
				list[l].index = l + 1;
				l++;
			}
		}
	}


	for (int i = 0; i < k; i++) {
		int flot = 0;
		for (int j = 0; j < n; j++) {
			if (l2[i].data == l1[j].data) {
				flot++;
			}
		}
		if (flot == 0) {
			if (l == size - 1) {
				list[l].data = l2[i].data;
				list[l].index = 0;
				break;
			}
			else {
				list[l].data = l2[i].data;
				list[l].index = l + 1;
				l++;
			}
		}
	}
	return list;
}
