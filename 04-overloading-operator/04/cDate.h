#pragma once

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cstdlib>

class cDate {
private:
    int ngay;
    int thang;
    int nam;

    static bool laNamNhuan(int nam) {
        return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
    }

    static int soNgayTrongThang(int thang, int nam) {
        static const int soNgayMoiThang[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (thang == 2 && laNamNhuan(nam)) {
            return 29;
        }
        return soNgayMoiThang[thang];
    }

    static bool laNgayHopLe(int ngay, int thang, int nam) {
        if (nam < 1 || thang < 1 || thang > 12) {
            return false;
        }
        return ngay >= 1 && ngay <= soNgayTrongThang(thang, nam);
    }

    void tangMotNgay() {
        ngay++;
        if (ngay > soNgayTrongThang(thang, nam)) {
            ngay = 1;
            thang++;
            if (thang > 12) {
                thang = 1;
                nam++;
            }
        }
    }

    void giamMotNgay() {
        ngay--;
        if (ngay < 1) {
            thang--;
            if (thang < 1) {
                thang = 12;
                nam--;
            }
            ngay = soNgayTrongThang(thang, nam);
        }
    }

    long long tinhTongSoNgay() const {
        long long tong = 0;

        for (int i = 1; i < nam; i++) {
            if (laNamNhuan(i)) {
                tong += 366;
            } else {
                tong += 365;
            }
        }

        for (int i = 1; i < thang; i++) {
            tong += soNgayTrongThang(i, nam);
        }

        tong += ngay;
        return tong;
    }

public:
    cDate() : ngay(1), thang(1), nam(2000) {}

    cDate(int ngay, int thang, int nam) {
        thietLapNgay(ngay, thang, nam);
    }

    void thietLapNgay(int ngay, int thang, int nam) {
        if (!laNgayHopLe(ngay, thang, nam)) {
            std::cout << "Ngay khong hop le" << std::endl;
            return;
        }
        this->ngay = ngay;
        this->thang = thang;
        this->nam = nam;
    }

    int getNgay() const {
        return ngay;
    }

    int getThang() const {
        return thang;
    }

    int getNam() const {
        return nam;
    }

    cDate operator+(int soNgay) const {
        cDate ketQua(*this);

        if (soNgay >= 0) {
            for (int i = 0; i < soNgay; i++) {
                ketQua.tangMotNgay();
            }
        } else {
            for (int i = 0; i < -soNgay; i++) {
                ketQua.giamMotNgay();
            }
        }

        return ketQua;
    }

    cDate operator-(int soNgay) const {
        cDate ketQua(*this);

        if (soNgay >= 0) {
            for (int i = 0; i < soNgay; i++) {
                ketQua.giamMotNgay();
            }
        } else {
            for (int i = 0; i < -soNgay; i++) {
                ketQua.tangMotNgay();
            }
        }

        return ketQua;
    }

    long long operator-(const cDate& ngayKhac) const {
        return std::llabs(tinhTongSoNgay() - ngayKhac.tinhTongSoNgay());
    }

    cDate& operator++() {
        *this = *this + 1;
        return *this;
    }

    cDate operator++(int) {
        cDate tam(*this);
        ++(*this);
        return tam;
    }

    cDate& operator--() {
        *this = *this - 1;
        return *this;
    }

    cDate operator--(int) {
        cDate tam(*this);
        --(*this);
        return tam;
    }

    friend std::ostream& operator<<(std::ostream& os, const cDate& ngayThangNam) {
        os << std::setw(2) << std::setfill('0') << ngayThangNam.ngay << "/"
           << std::setw(2) << std::setfill('0') << ngayThangNam.thang << "/"
           << ngayThangNam.nam;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, cDate& ngayThangNam) {
        int ngay;
        int thang;
        int nam;
        is >> ngay >> thang >> nam;
        if (!is) {
            return is;
        }
        if (!laNgayHopLe(ngay, thang, nam)) {
            is.setstate(std::ios::failbit);
            return is;
        }
        ngayThangNam.ngay = ngay;
        ngayThangNam.thang = thang;
        ngayThangNam.nam = nam;
        return is;
    }
};
