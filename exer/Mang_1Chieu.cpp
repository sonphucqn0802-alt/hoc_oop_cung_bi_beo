#include <iostream>
#include <cstdlib>
using namespace std;

class cArray {
     int* arr;
     int size;
public:
    cArray() {
        arr = new int[1];
        arr[0] = 0;
        size = 1;
    }
    cArray(int size) {
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
        this->size = size;
    }

    void input() {
        for (int i = 0; i < size; i++) {
            cout << "arr[" << i << "] = ";
            cin >> arr[i];
            cout << " ";
        }
        cout << "\n";
    }

    void output() {
        cout << "Mang: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    cArray RandomArray () {
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 100;
        }
        return *this;
    }

    void CountX (int x) {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] == x) {
                count++;
            }
        }
        cout << "So lan xuat hien cua " << x << " la: " << count << endl;
    }

    void CheckIncreaseArr () {
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                cout << "Mang khong tang" << endl;
                return;
            }
        }
        cout << "Mang tang" << endl;
    }

    void IncreaseArr() {
        for (int i = 0; i < size - 1; i++) {
          for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
              int temp = arr[i];
              arr[i] = arr[j];
              arr[j] = temp;
            }
          }
        }
    }

    void MinOdd () {
        int min = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] < min && arr[i] % 2 != 0) {
                min = arr[i];
            }
        }
        cout << "Min: " << min << endl;
    }

    ~cArray() {
        delete[] arr;
    } 
};



int main () {
    cArray arr1(5),arr2(19), arr3;
    arr1.RandomArray().output();
    arr1.IncreaseArr();
    arr1.output();
    arr1.CheckIncreaseArr();
    arr2.RandomArray().output();
    arr2.IncreaseArr();
    arr2.output();
    arr2.CheckIncreaseArr();
    arr3.input();
    arr3.output();
    arr3.IncreaseArr();
    arr3.output();
    arr3.CheckIncreaseArr();
    return 0;
}