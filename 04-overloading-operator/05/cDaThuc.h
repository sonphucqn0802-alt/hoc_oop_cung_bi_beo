#pragma once

#include <iostream>
#include <cmath>

using namespace std;

class cDaThuc {
private:
    int bac;
    double* heSo;

    void capPhatHeSo(int bac) {
        this->bac = bac;
        heSo = new double[bac + 1];
        for (int i = 0; i <= bac; i++) {
            heSo[i] = 0;
        }
    }

    void giaiPhongHeSo() {
        delete[] heSo;
        heSo = nullptr;
    }

    void chuanHoa() {
        while (bac > 0 && fabs(heSo[bac]) < 1e-9) {
            bac--;
        }
    }

public:
    cDaThuc() {
        capPhatHeSo(0);
    }

    cDaThuc(int bac) {
        if (bac < 0) {
            bac = 0;
        }
        capPhatHeSo(bac);
    }

    cDaThuc(const cDaThuc& daThuc) {
        capPhatHeSo(daThuc.bac);
        for (int i = 0; i <= bac; i++) {
            heSo[i] = daThuc.heSo[i];
        }
    }

    ~cDaThuc() {
        giaiPhongHeSo();
    }

    cDaThuc& operator=(const cDaThuc& daThuc) {
        if (this != &daThuc) {
            giaiPhongHeSo();
            capPhatHeSo(daThuc.bac);
            for (int i = 0; i <= bac; i++) {
                heSo[i] = daThuc.heSo[i];
            }
        }
        return *this;
    }

    int getBac() const {
        return bac;
    }

    double getHeSo(int soMu) const {
        if (soMu < 0 || soMu > bac) {
            return 0;
        }
        return heSo[soMu];
    }

    void setHeSo(int soMu, double giaTri) {
        if (soMu < 0) {
            return;
        }

        if (soMu > bac) {
            double* heSoMoi = new double[soMu + 1];

            for (int i = 0; i <= soMu; i++) {
                heSoMoi[i] = 0;
            }

            for (int i = 0; i <= bac; i++) {
                heSoMoi[i] = heSo[i];
            }

            delete[] heSo;
            heSo = heSoMoi;
            bac = soMu;
        }

        heSo[soMu] = giaTri;
        chuanHoa();
    }

    double tinhGiaTri(double x) const {
        double ketQua = 0;
        double luyThua = 1;

        for (int i = 0; i <= bac; i++) {
            ketQua += heSo[i] * luyThua;
            luyThua *= x;
        }

        return ketQua;
    }

    cDaThuc operator+(const cDaThuc& daThucKhac) const {
        int bacLonHon = bac;
        if (daThucKhac.bac > bacLonHon) {
            bacLonHon = daThucKhac.bac;
        }

        cDaThuc ketQua(bacLonHon);
        for (int i = 0; i <= bacLonHon; i++) {
            ketQua.heSo[i] = getHeSo(i) + daThucKhac.getHeSo(i);
        }

        ketQua.chuanHoa();
        return ketQua;
    }

    cDaThuc operator-(const cDaThuc& daThucKhac) const {
        int bacLonHon = bac;
        if (daThucKhac.bac > bacLonHon) {
            bacLonHon = daThucKhac.bac;
        }

        cDaThuc ketQua(bacLonHon);
        for (int i = 0; i <= bacLonHon; i++) {
            ketQua.heSo[i] = getHeSo(i) - daThucKhac.getHeSo(i);
        }

        ketQua.chuanHoa();
        return ketQua;
    }

    cDaThuc operator*(const cDaThuc& daThucKhac) const {
        cDaThuc ketQua(bac + daThucKhac.bac);

        for (int i = 0; i <= bac; i++) {
            for (int j = 0; j <= daThucKhac.bac; j++) {
                ketQua.heSo[i + j] += heSo[i] * daThucKhac.heSo[j];
            }
        }

        ketQua.chuanHoa();
        return ketQua;
    }

    bool operator==(const cDaThuc& daThucKhac) const {
        int bacLonHon = bac;
        if (daThucKhac.bac > bacLonHon) {
            bacLonHon = daThucKhac.bac;
        }

        for (int i = 0; i <= bacLonHon; i++) {
            if (fabs(getHeSo(i) - daThucKhac.getHeSo(i)) >= 1e-9) {
                return false;
            }
        }

        return true;
    }

    friend ostream& operator<<(ostream& os, const cDaThuc& daThuc) {
        bool coIn = false;

        for (int i = daThuc.bac; i >= 0; i--) {
            if (fabs(daThuc.heSo[i]) < 1e-9) {
                continue;
            }

            if (coIn == true) {
                if (daThuc.heSo[i] > 0) {
                    os << " + ";
                } else {
                    os << " - ";
                }
            } else if (daThuc.heSo[i] < 0) {
                os << "-";
            }

            os << fabs(daThuc.heSo[i]);

            if (i > 0) {
                os << "x";
            }

            if (i > 1) {
                os << "^" << i;
            }

            coIn = true;
        }

        if (coIn == false) {
            os << "0";
        }

        return os;
    }

    friend istream& operator>>(istream& is, cDaThuc& daThuc) {
        int bacMoi;
        is >> bacMoi;

        if (!is || bacMoi < 0) {
            is.setstate(ios::failbit);
            return is;
        }

        daThuc.giaiPhongHeSo();
        daThuc.capPhatHeSo(bacMoi);

        for (int i = 0; i <= daThuc.bac; i++) {
            is >> daThuc.heSo[i];
        }

        daThuc.chuanHoa();
        return is;
    }
};
