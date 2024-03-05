#include <iostream>
#include <iomanip>
using namespace std;
const int N = 9;

void input(int[]);
void input(double[]);
void input(char[]);
void print(int[]);
void print(double[]);
void print(char[]);
template <typename T>
void sort(T[], int);
template <typename T>
void merge(T[]);

int main() {
    setlocale(LC_ALL, "RU");
    double arr[N]{};
    input(arr);
    cout << "Ваш массив:" << endl;
    print(arr);
    merge(arr);
    cout << "Отсортированный массив:" << endl;
    print(arr);

    return 0;
}


void input(int arr[]) {
    cout << "Пожалуйста, введите элементы массива:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << endl;
}
void input(double arr[]) {
    cout << "Пожалуйста, введите элементы массива:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << endl;
}

void input(char arr[]) {
    cout << "Пожалуйста, введите элементы массива:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << endl;
}


void print(int arr[]) {
    for (int i = 0; i < N; i++) {
        cout << setw(5) << arr[i];
    }
    cout << endl;
}
void print(double arr[]) {
    for (int i = 0; i < N; i++) {
        cout << setw(5) << arr[i];
    }
    cout << endl;
}
void print(char arr[]) {
    for (int i = 0; i < N; i++) {
        cout << setw(5) << arr[i];
    }
    cout << endl;
}

template <typename T>
void merge(T arr[]) {
    if (N % 2 == 0) {
        T A[N / 2]{};
        T B[N / 2]{};
        int size = N / 2;
        for (int i = 0; i < size; i++) {
            A[i] = arr[i];
        }
        int k = 0;
        for (int i = size; i < N; i++) {
            B[k] = arr[i];
            k++;
        }
        sort(A, size);
        sort(B, size);
        int x = 0;
        int l = 0;
        for (int i = 0; i < N; i++) {
            if (x == size) {
                arr[i] = B[l];
                l++;
            }
            else if (l == size) {
                arr[i] = A[x];
                x++;
            }
            else if (A[x] < B[l]) {
                arr[i] = A[x];
                x++;
            }
            else {
                arr[i] = B[l];
                l++;
            }
        }
    }
    else {
        int sizeA = N / 2 + 1;
        int sizeB = N / 2;
        T A[N / 2 + 1]{};
        T B[N / 2 + 1]{};

        for (int i = 0; i < sizeA; i++) {
            A[i] = arr[i];
        }
        int k = 0;
        for (int i = sizeA; i < N; i++) {
            B[k] = arr[i];
            k++;
        }

        sort(A, sizeA);
        sort(B, sizeB);

        int x = 0;
        int l = 0;
        for (int i = 0; i < N; i++) {
            if (x == sizeA) {
                arr[i] = B[l];
                l++;
            }
            else if (l == sizeB) {
                arr[i] = A[x];
                x++;
            }
            else if (A[x] < B[l]) {
                arr[i] = A[x];
                x++;
            }
            else {
                arr[i] = B[l];
                l++;
            }
        }
    }
}

template <typename T>
void sort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        T min = arr[i];
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < min) {
                T tmp = arr[j];
                arr[j] = min;
                min = tmp;
            }
        }
        arr[i] = min;
    }
}