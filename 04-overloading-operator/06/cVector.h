#pragma once

#include <bits/stdc++.h>

using namespace std;

class cVector {
private:
    vector<double> thanhPhan;

public:
    cVector() {}

    cVector(int soChieu) : thanhPhan(soChieu, 0) {}

    int laySoChieu() const {
        return static_cast<int>(thanhPhan.size());
    }

    double layThanhPhan(int chiSo) const {
        return thanhPhan[chiSo];
    }

    void ganThanhPhan(int chiSo, double giaTri) {
        thanhPhan[chiSo] = giaTri;
    }

    cVector operator+(const cVector& vectorKhac) const {
        if (laySoChieu() != vectorKhac.laySoChieu()) {
            cout << "Hai vector khong cung so chieu" << endl;
            return cVector();
        }

        cVector ketQua(laySoChieu());
        for (int i = 0; i < laySoChieu(); i++) {
            ketQua.thanhPhan[i] = thanhPhan[i] + vectorKhac.thanhPhan[i];
        }
        return ketQua;
    }

    cVector operator-(const cVector& vectorKhac) const {
        if (laySoChieu() != vectorKhac.laySoChieu()) {
            cout << "Hai vector khong cung so chieu" << endl;
            return cVector();
        }

        cVector ketQua(laySoChieu());
        for (int i = 0; i < laySoChieu(); i++) {
            ketQua.thanhPhan[i] = thanhPhan[i] - vectorKhac.thanhPhan[i];
        }
        return ketQua;
    }

    bool operator==(const cVector& vectorKhac) const {
        if (laySoChieu() != vectorKhac.laySoChieu()) {
            return false;
        }

        for (int i = 0; i < laySoChieu(); i++) {
            if (fabs(thanhPhan[i] - vectorKhac.thanhPhan[i]) >= 1e-9) {
                return false;
            }
        }
        return true;
    }

    friend ostream& operator<<(ostream& os, const cVector& vector) {
        os << "(";                  
        for (int i = 0; i < vector.laySoChieu(); i++) {
            os << vector.thanhPhan[i];
            if (i + 1 < vector.laySoChieu()) {
                os << ", ";
            }
        }
        os << ")";
        return os;
    }

    friend istream& operator>>(istream& is, cVector& vector) {
        int soChieu;
        is >> soChieu;
        vector.thanhPhan.assign(soChieu, 0);
        for (int i = 0; i < soChieu; i++) {
            is >> vector.thanhPhan[i];
        }
        return is;
    }
};
