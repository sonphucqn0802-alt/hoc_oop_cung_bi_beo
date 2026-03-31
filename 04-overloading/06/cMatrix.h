#pragma once

#include "cVector.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

class cMatrix {
private:
    int soDong;
    int soCot;
    std::vector<std::vector<double>> phanTu;

public:
    cMatrix() : soDong(0), soCot(0) {}

    cMatrix(int soDong, int soCot)
        : soDong(soDong), soCot(soCot), phanTu(soDong, std::vector<double>(soCot, 0)) {}

    int laySoDong() const {
        return soDong;
    }

    int laySoCot() const {
        return soCot;
    }

    double layPhanTu(int dong, int cot) const {
        return phanTu[dong][cot];
    }

    void ganPhanTu(int dong, int cot, double giaTri) {
        phanTu[dong][cot] = giaTri;
    }

    cMatrix operator+(const cMatrix& maTranKhac) const {
        if (soDong != maTranKhac.soDong || soCot != maTranKhac.soCot) {
            throw std::invalid_argument("Hai ma tran khong cung kich thuoc");
        }

        cMatrix ketQua(soDong, soCot);
        for (int i = 0; i < soDong; i++) {
            for (int j = 0; j < soCot; j++) {
                ketQua.phanTu[i][j] = phanTu[i][j] + maTranKhac.phanTu[i][j];
            }
        }
        return ketQua;
    }

    cMatrix operator-(const cMatrix& maTranKhac) const {
        if (soDong != maTranKhac.soDong || soCot != maTranKhac.soCot) {
            throw std::invalid_argument("Hai ma tran khong cung kich thuoc");
        }

        cMatrix ketQua(soDong, soCot);
        for (int i = 0; i < soDong; i++) {
            for (int j = 0; j < soCot; j++) {
                ketQua.phanTu[i][j] = phanTu[i][j] - maTranKhac.phanTu[i][j];
            }
        }
        return ketQua;
    }

    cVector operator*(const cVector& vector) const {
        if (soCot != vector.laySoChieu()) {
            throw std::invalid_argument("So cot cua ma tran phai bang so chieu cua vector");
        }

        cVector ketQua(soDong);
        for (int i = 0; i < soDong; i++) {
            double tong = 0;
            for (int j = 0; j < soCot; j++) {
                tong += phanTu[i][j] * vector.layThanhPhan(j);
            }
            ketQua.ganThanhPhan(i, tong);
        }
        return ketQua;
    }

    cMatrix operator*(const cMatrix& maTranKhac) const {
        if (soCot != maTranKhac.soDong) {
            throw std::invalid_argument("So cot cua ma tran thu nhat phai bang so dong cua ma tran thu hai");
        }

        cMatrix ketQua(soDong, maTranKhac.soCot);
        for (int i = 0; i < soDong; i++) {
            for (int j = 0; j < maTranKhac.soCot; j++) {
                double tong = 0;
                for (int k = 0; k < soCot; k++) {
                    tong += phanTu[i][k] * maTranKhac.phanTu[k][j];
                }
                ketQua.phanTu[i][j] = tong;
            }
        }
        return ketQua;
    }

    bool operator==(const cMatrix& maTranKhac) const {
        if (soDong != maTranKhac.soDong || soCot != maTranKhac.soCot) {
            return false;
        }

        for (int i = 0; i < soDong; i++) {
            for (int j = 0; j < soCot; j++) {
                if (std::fabs(phanTu[i][j] - maTranKhac.phanTu[i][j]) >= 1e-9) {
                    return false;
                }
            }
        }
        return true;
    }

    friend std::ostream& operator<<(std::ostream& os, const cMatrix& maTran) {
        for (int i = 0; i < maTran.soDong; i++) {
            os << "[";
            for (int j = 0; j < maTran.soCot; j++) {
                os << maTran.phanTu[i][j];
                if (j + 1 < maTran.soCot) {
                    os << "\t";
                }
            }
            os << "]";
            if (i + 1 < maTran.soDong) {
                os << std::endl;
            }
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, cMatrix& maTran) {
        is >> maTran.soDong >> maTran.soCot;
        if (!is || maTran.soDong < 0 || maTran.soCot < 0) {
            is.setstate(std::ios::failbit);
            return is;
        }

        maTran.phanTu.assign(maTran.soDong, std::vector<double>(maTran.soCot, 0));
        for (int i = 0; i < maTran.soDong; i++) {
            for (int j = 0; j < maTran.soCot; j++) {
                is >> maTran.phanTu[i][j];
            }
        }
        return is;
    }
};
