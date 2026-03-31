#pragma once

#include <iostream>
#include <vector>
#include <cmath>

class cDaThuc {
private:
    std::vector<double> heSo;

    void chuanHoa() {
        while (heSo.size() > 1 && std::fabs(heSo.back()) < 1e-9) {
            heSo.pop_back();
        }
    }

public:
    cDaThuc() : heSo(1, 0) {}

    cDaThuc(int bac) : heSo(bac + 1, 0) {}

    int layBac() const {
        return static_cast<int>(heSo.size()) - 1;
    }

    double layHeSo(int soMu) const {
        if (soMu < 0 || soMu > layBac()) {
            return 0;
        }
        return heSo[soMu];
    }

    void ganHeSo(int soMu, double giaTri) {
        if (soMu < 0) {
            return;
        }
        if (soMu > layBac()) {
            heSo.resize(soMu + 1, 0);
        }
        heSo[soMu] = giaTri;
        chuanHoa();
    }

    double tinhGiaTri(double x) const {
        double ketQua = 0;
        double luyThua = 1;

        for (size_t i = 0; i < heSo.size(); i++) {
            ketQua += heSo[i] * luyThua;
            luyThua *= x;
        }

        return ketQua;
    }

    cDaThuc operator+(const cDaThuc& daThucKhac) const {
        int bacLonNhat = std::max(layBac(), daThucKhac.layBac());
        cDaThuc ketQua(bacLonNhat);

        for (int i = 0; i <= bacLonNhat; i++) {
            ketQua.heSo[i] = layHeSo(i) + daThucKhac.layHeSo(i);
        }

        ketQua.chuanHoa();
        return ketQua;
    }

    cDaThuc operator-(const cDaThuc& daThucKhac) const {
        int bacLonNhat = std::max(layBac(), daThucKhac.layBac());
        cDaThuc ketQua(bacLonNhat);

        for (int i = 0; i <= bacLonNhat; i++) {
            ketQua.heSo[i] = layHeSo(i) - daThucKhac.layHeSo(i);
        }

        ketQua.chuanHoa();
        return ketQua;
    }

    cDaThuc operator*(const cDaThuc& daThucKhac) const {
        cDaThuc ketQua(layBac() + daThucKhac.layBac());

        for (int i = 0; i <= layBac(); i++) {
            for (int j = 0; j <= daThucKhac.layBac(); j++) {
                ketQua.heSo[i + j] += heSo[i] * daThucKhac.heSo[j];
            }
        }

        ketQua.chuanHoa();
        return ketQua;
    }

    bool operator==(const cDaThuc& daThucKhac) const {
        if (layBac() != daThucKhac.layBac()) {
            return false;
        }

        for (int i = 0; i <= layBac(); i++) {
            if (std::fabs(heSo[i] - daThucKhac.heSo[i]) >= 1e-9) {
                return false;
            }
        }

        return true;
    }

    friend std::ostream& operator<<(std::ostream& os, const cDaThuc& daThuc) {
        bool coHangTu = false;

        for (int i = daThuc.layBac(); i >= 0; i--) {
            double heSoHienTai = daThuc.heSo[i];

            if (std::fabs(heSoHienTai) < 1e-9) {
                continue;
            }

            if (coHangTu) {
                if (heSoHienTai > 0) {
                    os << " + ";
                } else {
                    os << " - ";
                }
            } else if (heSoHienTai < 0) {
                os << "-";
            }

            double giaTriTuyetDoi = std::fabs(heSoHienTai);
            os << giaTriTuyetDoi;

            if (i >= 1) {
                os << "x";
            }
            if (i >= 2) {
                os << "^" << i;
            }

            coHangTu = true;
        }

        if (!coHangTu) {
            os << "0";
        }

        return os;
    }

    friend std::istream& operator>>(std::istream& is, cDaThuc& daThuc) {
        int bac;
        is >> bac;
        if (!is || bac < 0) {
            is.setstate(std::ios::failbit);
            return is;
        }

        daThuc.heSo.assign(bac + 1, 0);
        for (int i = 0; i <= bac; i++) {
            is >> daThuc.heSo[i];
        }

        daThuc.chuanHoa();
        return is;
    }
};
