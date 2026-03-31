#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

class cVector {
private:
    std::vector<double> thanhPhan;

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
            throw std::invalid_argument("Hai vector khong cung so chieu");
        }

        cVector ketQua(laySoChieu());
        for (int i = 0; i < laySoChieu(); i++) {
            ketQua.thanhPhan[i] = thanhPhan[i] + vectorKhac.thanhPhan[i];
        }
        return ketQua;
    }

    cVector operator-(const cVector& vectorKhac) const {
        if (laySoChieu() != vectorKhac.laySoChieu()) {
            throw std::invalid_argument("Hai vector khong cung so chieu");
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
            if (std::fabs(thanhPhan[i] - vectorKhac.thanhPhan[i]) >= 1e-9) {
                return false;
            }
        }
        return true;
    }

    friend std::ostream& operator<<(std::ostream& os, const cVector& vector) {
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

    friend std::istream& operator>>(std::istream& is, cVector& vector) {
        int soChieu;
        is >> soChieu;
        if (!is || soChieu < 0) {
            is.setstate(std::ios::failbit);
            return is;
        }

        vector.thanhPhan.assign(soChieu, 0);
        for (int i = 0; i < soChieu; i++) {
            is >> vector.thanhPhan[i];
        }
        return is;
    }
};
