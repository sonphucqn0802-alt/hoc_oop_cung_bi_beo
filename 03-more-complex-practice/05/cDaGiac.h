#pragma once

#include <bits/stdc++.h>
using namespace std;

class cDiem {
public:
    int x, y;

    cDiem(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
};

class cDaGiac {
private:
    int n;
    vector<cDiem> dinh;

public:
    cDaGiac(int n = 0) {
        this->n = n;
        dinh.resize(n);
    }

    ~cDaGiac() {
    }

    void Nhap() {
        do {
            cout << "Nhap so dinh cua da giac: ";
            cin >> n;
        } while (n < 3);

        dinh.resize(n);
        for (int i = 0; i < n; i++) {
            cout << "Nhap toa do dinh " << i + 1 << ": ";
            cin >> dinh[i].x >> dinh[i].y;
        }
    }

    void Xuat() {
        cout << "Da giac co " << n << " dinh:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Dinh " << i + 1 << ": (" << dinh[i].x << ", " << dinh[i].y << ")" << endl;
        }
    }

    bool KiemTraHopLe() {
        if (n < 3) {
            return false;
        }

        long long tong = 0;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            tong += 1LL * dinh[i].x * dinh[j].y - 1LL * dinh[i].y * dinh[j].x;
        }

        if (tong == 0) {
            return false;
        }

        return true;
    }

    double TinhChuVi() {
        double chuVi = 0;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            double dx = dinh[i].x - dinh[j].x;
            double dy = dinh[i].y - dinh[j].y;
            chuVi += sqrt(dx * dx + dy * dy);
        }
        return chuVi;
    }

    double TinhDienTich() {
        long long tong = 0;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            tong += 1LL * dinh[i].x * dinh[j].y - 1LL * dinh[i].y * dinh[j].x;
        }

        if (tong < 0) {
            tong = -tong;
        }

        return tong / 2.0;
    }

    void tinhChuVi() {
        cout << "Chu vi: " << TinhChuVi() << endl;
    }

    void tinhDienTich() {
        cout << "Dien tich: " << TinhDienTich() << endl;
    }

    void TinhTien(int dx, int dy) {
        for (int i = 0; i < n; i++) {
            dinh[i].x += dx;
            dinh[i].y += dy;
        }
    }

    void PhongTo(int k) {
        for (int i = 0; i < n; i++) {
            dinh[i].x *= k;
            dinh[i].y *= k;
        }
    }

    void ThuNho(int k) {
        if (k == 0) {
            return;
        }

        for (int i = 0; i < n; i++) {
            dinh[i].x /= k;
            dinh[i].y /= k;
        }
    }

};
