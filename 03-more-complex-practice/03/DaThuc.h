#pragma once

#include <bits/stdc++.h>

using namespace std;

class DaThuc {
private:
    int bac;
    double* heSo;
public:
    DaThuc() {
        bac = 0;
        heSo = nullptr;
    }
    ~DaThuc() {
        delete[] heSo;
    }
    void Nhap() {
        cout << "Nhap bac cua da thuc: ";
        cin >> bac;
        heSo = new double[bac + 1];
        for (int i = 0; i <= bac; i++) {
            cout << "Nhap he so cua x^" << i << ": ";
            cin >> heSo[i];
        }
    }
    void Xuat() {
        for (int i = 0; i <= bac; i++) {
            if (heSo[i] != 0) {
                if (i == 0) {
                    cout << heSo[i];
                } else if (i == 1) {
                    cout << heSo[i] << "x";
                } else {
                    cout << heSo[i] << "x^" << i;
                }
                if (i < bac) {
                    cout << " + ";
                }
            }
        }
        cout << endl;
    }
    double TinhGiaTri(double x) {
        double ketQua = 0;
        for (int i = 0; i <= bac; i++) {
            ketQua += heSo[i] * pow(x, i);
        }
        return ketQua;
    }
    DaThuc Cong(DaThuc dt) {
        DaThuc ketQua;
        ketQua.bac = max(this->bac, dt.bac);
        ketQua.heSo = new double[ketQua.bac + 1];
        for (int i = 0; i <= ketQua.bac; i++) {
            ketQua.heSo[i] = 0;
        }
        for (int i = 0; i <= this->bac; i++) {
            ketQua.heSo[i] += this->heSo[i];
        }
        for (int i = 0; i <= dt.bac; i++) {
            ketQua.heSo[i] += dt.heSo[i];
        }
        return ketQua;
    }
    DaThuc Tru(DaThuc dt) {
        DaThuc ketQua;
        ketQua.bac = max(this->bac, dt.bac);
        ketQua.heSo = new double[ketQua.bac + 1];
        for (int i = 0; i <= ketQua.bac; i++) {
            ketQua.heSo[i] = 0;
        }
        for (int i = 0; i <= this->bac; i++) {
            ketQua.heSo[i] += this->heSo[i];
        }
        for (int i = 0; i <= dt.bac; i++) {
            ketQua.heSo[i] -= dt.heSo[i];
        }
        return ketQua;
    }
};
