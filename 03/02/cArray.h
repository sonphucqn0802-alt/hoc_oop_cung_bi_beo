#pragma once 

#include <bits/stdc++.h>
using namespace std;

class cArray {
private:
    int* arr;
    int n;
public:
    cArray() {
        arr = nullptr;
        n = 0;
    }
    ~cArray() {
        delete[] arr;
    }
    void Nhap() {
        cout << "Nhap so luong phan tu: ";
        cin >> n;
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            cout << "Nhap phan tu thu " << i+1 << ": ";
            cin >> arr[i];
        }
    }
    void Xuat() {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int DemSoLanXuatHien(int x) {
        int dem = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) {
                dem++;
            }
        }
        return dem;
    }
    bool KiemTraTangDan() {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }
    int TimPhanTuNhoNhat() {
        int min = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        return min;
    }
    int TimSoNguyenToLonNhat() {
        int max = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] > max && LaSoNguyenTo(arr[i])) {
                max = arr[i];
            }
        }
        return max;
    }
    void SapXepTangDan() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    void SapXepGiamDan() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] < arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    bool LaSoNguyenTo(int n) {
        if (n < 2) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};