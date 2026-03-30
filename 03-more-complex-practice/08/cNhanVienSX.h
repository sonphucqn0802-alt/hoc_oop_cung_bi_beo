#pragma once

#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

class DateofBirth {
private:
    int ngay;
    int thang;
    int nam;

    bool LaNamNhuan(int year) const {
        return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }

    int SoNgayTrongThang(int month, int year) const {
        if (month == 2) {
            return LaNamNhuan(year) ? 29 : 28;
        }

        if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        }

        return 31;
    }

    bool HopLe(int day, int month, int year) const {
        if (year <= 0 || month < 1 || month > 12) {
            return false;
        }

        return day >= 1 && day <= SoNgayTrongThang(month, year);
    }

public:
    DateofBirth(int day = 1, int month = 1, int year = 2000) {
        SetDate(day, month, year);
    }

    void SetDate(int day, int month, int year) {
        if (HopLe(day, month, year)) {
            ngay = day;
            thang = month;
            nam = year;
        } else {
            ngay = 1;
            thang = 1;
            nam = 2000;
        }
    }

    bool SomHon(const DateofBirth& other) const {
        if (nam != other.nam) {
            return nam < other.nam;
        }
        if (thang != other.thang) {
            return thang < other.thang;
        }
        return ngay < other.ngay;
    }

    void Nhap() {
        int day, month, year;
        do {
            cout << "Nhap ngay sinh (ngay thang nam): ";
            cin >> day >> month >> year;
        } while (!HopLe(day, month, year));

        ngay = day;
        thang = month;
        nam = year;
    }

    void Xuat() const {
        cout << ngay << "/" << thang << "/" << nam;
    }
};

class cNhanVienSX {
private:
    int ma;
    string hoTen;
    DateofBirth ngaySinh;
    int soSanPham;
    double donGia;

public:
    cNhanVienSX(int ma = 0, const string& hoTen = "", const DateofBirth& ngaySinh = DateofBirth(),
                int soSanPham = 0, double donGia = 0.0)
        : ma(ma), hoTen(hoTen), ngaySinh(ngaySinh), soSanPham(soSanPham < 0 ? 0 : soSanPham),
          donGia(donGia < 0 ? 0.0 : donGia) {
    }

    void setNhanVienSX(int ma, const string& hoTen, const DateofBirth& ngaySinh, int soSanPham, double donGia) {
        this->ma = ma;
        this->hoTen = hoTen;
        this->ngaySinh = ngaySinh;
        this->soSanPham = (soSanPham < 0 ? 0 : soSanPham);
        this->donGia = (donGia < 0 ? 0.0 : donGia);
    }

    void getNhanVienSX(int& ma, string& hoTen, DateofBirth& ngaySinh, int& soSanPham, double& donGia) const {
        ma = this->ma;
        hoTen = this->hoTen;
        ngaySinh = this->ngaySinh;
        soSanPham = this->soSanPham;
        donGia = this->donGia;
    }

    int GetMa() const {
        return ma;
    }

    string GetHoTen() const {
        return hoTen;
    }

    DateofBirth GetNgaySinh() const {
        return ngaySinh;
    }

    int GetSoSanPham() const {
        return soSanPham;
    }

    double GetDonGia() const {
        return donGia;
    }

    double TinhLuong() const {
        return soSanPham * donGia;
    }

    void SetMa(int ma) {
        this->ma = ma;
    }

    void SetHoTen(const string& hoTen) {
        this->hoTen = hoTen;
    }

    void SetNgaySinh(const DateofBirth& ngaySinh) {
        this->ngaySinh = ngaySinh;
    }

    void SetSoSanPham(int soSanPham) {
        this->soSanPham = (soSanPham < 0 ? 0 : soSanPham);
    }

    void SetDonGia(double donGia) {
        this->donGia = (donGia < 0 ? 0.0 : donGia);
    }

    void NhapNhanVien() {
        cout << "Nhap ma nhan vien: ";
        cin >> ma;

        cin.ignore();
        do {
            cout << "Nhap ho ten: ";
            getline(cin, hoTen);
        } while (hoTen.empty());

        ngaySinh.Nhap();

        do {
            cout << "Nhap so san pham da gia cong: ";
            cin >> soSanPham;
        } while (soSanPham < 0);

        do {
            cout << "Nhap don gia mot san pham: ";
            cin >> donGia;
        } while (donGia < 0);
    }

    void XuatNhanVien() const {
        cout << ma
             << " | " << hoTen;
        ngaySinh.Xuat();
        cout << " | "
             << soSanPham
             << " | "
             << donGia 
             << " | "
             << TinhLuong() << '\n';
    }

    bool LonTuoiHon(const cNhanVienSX& other) const {
        return ngaySinh.SomHon(other.ngaySinh);
    }
};

class cListNhanVienSX {
private:
    cNhanVienSX* nhanVienSX;
    int n;

    void GiaiPhong() {
        delete[] nhanVienSX;
        nhanVienSX = nullptr;
        n = 0;
    }

    void SaoChepTu(const cListNhanVienSX& other) {
        n = other.n;
        if (n == 0) {
            nhanVienSX = nullptr;
            return;
        }

        nhanVienSX = new cNhanVienSX[n];
        for (int i = 0; i < n; ++i) {
            nhanVienSX[i] = other.nhanVienSX[i];
        }
    }

    void HoanDoi(cNhanVienSX& a, cNhanVienSX& b) {
        cNhanVienSX temp = a;
        a = b;
        b = temp;
    }

    void XuatTieuDe() const {
        cout << "Ma"
             << " | " << "Ho ten"
             << " | " << "Ngay sinh"
             << " | " << "So SP"
             << " | " << "Don gia"
             << " | " << "Luong" << '\n';
        cout << string(85, '-') << '\n';
    }

    int TimViTriLuongThapNhat() const {
        if (n == 0) {
            return -1;
        }

        int viTriMin = 0;
        for (int i = 1; i < n; ++i) {
            if (nhanVienSX[i].TinhLuong() < nhanVienSX[viTriMin].TinhLuong()) {
                viTriMin = i;
            }
        }
        return viTriMin;
    }

    int TimViTriLonTuoiNhat() const {
        if (n == 0) {
            return -1;
        }

        int viTriMaxTuoi = 0;
        for (int i = 1; i < n; ++i) {
            if (nhanVienSX[i].LonTuoiHon(nhanVienSX[viTriMaxTuoi])) {
                viTriMaxTuoi = i;
            }
        }
        return viTriMaxTuoi;
    }

public:
    cListNhanVienSX() : nhanVienSX(nullptr), n(0) {
    }

    cListNhanVienSX(const cListNhanVienSX& other) : nhanVienSX(nullptr), n(0) {
        SaoChepTu(other);
    }

    cListNhanVienSX& operator=(const cListNhanVienSX& other) {
        if (this != &other) {
            GiaiPhong();
            SaoChepTu(other);
        }
        return *this;
    }

    ~cListNhanVienSX() {
        delete[] nhanVienSX;
    }

    void Nhap() {
        int soLuong;
        do {
            cout << "Nhap so luong nhan vien san xuat: ";
            cin >> soLuong;
        } while (soLuong < 0);

        GiaiPhong();
        n = soLuong;

        if (n == 0) {
            return;
        }

        nhanVienSX = new cNhanVienSX[n];
        for (int i = 0; i < n; ++i) {
            cout << "\nNhap thong tin nhan vien thu " << i + 1 << ":\n";
            nhanVienSX[i].NhapNhanVien();
        }
    }

    void Xuat() const {
        if (n == 0) {
            cout << "Danh sach nhan vien rong.\n";
            return;
        }

        XuatTieuDe();
        for (int i = 0; i < n; ++i) {
            nhanVienSX[i].XuatNhanVien();
        }
    }

    double TinhTongLuong() const {
        double tong = 0.0;
        for (int i = 0; i < n; ++i) {
            tong += nhanVienSX[i].TinhLuong();
        }
        return tong;
    }

    void XuatNhanVienLuongThapNhat() const {
        int viTriMin = TimViTriLuongThapNhat();
        if (viTriMin == -1) {
            cout << "Danh sach nhan vien rong.\n";
            return;
        }

        XuatTieuDe();
        nhanVienSX[viTriMin].XuatNhanVien();
    }

    void XuatNhanVienLonTuoiNhat() const {
        int viTriMaxTuoi = TimViTriLonTuoiNhat();
        if (viTriMaxTuoi == -1) {
            cout << "Danh sach nhan vien rong.\n";
            return;
        }

        XuatTieuDe();
        nhanVienSX[viTriMaxTuoi].XuatNhanVien();
    }

    void SapXepTangDanTheoLuong() {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nhanVienSX[j].TinhLuong() < nhanVienSX[i].TinhLuong() ||
                    (nhanVienSX[j].TinhLuong() == nhanVienSX[i].TinhLuong() &&
                     nhanVienSX[j].GetMa() < nhanVienSX[i].GetMa())) {
                    HoanDoi(nhanVienSX[i], nhanVienSX[j]);
                }
            }
        }
    }
};
