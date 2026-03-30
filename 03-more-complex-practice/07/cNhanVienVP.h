#pragma once

#include <bits/stdc++.h>
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

    int GetNgay() const {
        return ngay;
    }

    int GetThang() const {
        return thang;
    }

    int GetNam() const {
        return nam;
    }
    //Hàm tính coi ai sinh trước
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

class cNhanVienVP {
private:
    int ma;
    string hoTen;
    DateofBirth ngaySinh;
    double luong;

public:
    cNhanVienVP(int ma = 0, const string& hoTen = "", const DateofBirth& ngaySinh = DateofBirth(), double luong = 0.0)
        : ma(ma), hoTen(hoTen), ngaySinh(ngaySinh), luong(luong < 0 ? 0.0 : luong) {
    }

    void setNhanVienVP(int ma, const string& hoTen, const DateofBirth& ngaySinh, double luong) {
        this->ma = ma;
        this->hoTen = hoTen;
        this->ngaySinh = ngaySinh;
        this->luong = (luong < 0 ? 0.0 : luong);
    }

    void getNhanVienVP(int& ma, string& hoTen, DateofBirth& ngaySinh, double& luong) const {
        ma = this->ma;
        hoTen = this->hoTen;
        ngaySinh = this->ngaySinh;
        luong = this->luong;
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

    double GetLuong() const {
        return luong;
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

    void SetLuong(double luong) {
        this->luong = (luong < 0 ? 0.0 : luong);
    }

    void NhapNhanVien() {
        cout << "Nhap ma nhan vien: ";
        cin >> ma;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        do {
            cout << "Nhap ho ten: ";
            getline(cin, hoTen);
        } while (hoTen.empty());
        ngaySinh.Nhap();

        do {
            cout << "Nhap luong: ";
            cin >> luong;
        } while (luong < 0);
    }

    void XuatNhanVien() const {
        cout << ma
             << " | "
             << hoTen;
        cout << " | ";
        ngaySinh.Xuat();
        cout << " | "
             << fixed << setprecision(2)
             << luong << '\n';
    }

    bool LonTuoiHon(const cNhanVienVP& other) const {
        return ngaySinh.SomHon(other.ngaySinh);
    }
};

class cListNhanVienVP {
private:
    cNhanVienVP* nhanVienVP;
    int n;

    void GiaiPhong() {
        delete[] nhanVienVP;
        nhanVienVP = nullptr;
        n = 0;
    }

    void SaoChepTu(const cListNhanVienVP& other) {
        n = other.n;
        if (n == 0) {
            nhanVienVP = nullptr;
            return;
        }

        nhanVienVP = new cNhanVienVP[n];
        for (int i = 0; i < n; ++i) {
            nhanVienVP[i] = other.nhanVienVP[i];
        }
    }

    void HoanDoi(cNhanVienVP& a, cNhanVienVP& b) {
        cNhanVienVP temp = a;
        a = b;
        b = temp;
    }

    void XuatTieuDe() const {
        cout << "Ma"
             << " | "
             << "Ho ten"
             << " | "
             << "Ngay sinh"
             << " | "
             << "Luong" << '\n';
        cout << string(65, '-') << '\n';
    }

    int TimViTriLuongCaoNhat() const {
        if (n == 0) {
            return -1;
        }

        int viTriMax = 0;
        for (int i = 1; i < n; ++i) {
            if (nhanVienVP[i].GetLuong() > nhanVienVP[viTriMax].GetLuong()) {
                viTriMax = i;
            }
        }
        return viTriMax;
    }

    int TimViTriLonTuoiNhat() const {
        if (n == 0) {
            return -1;
        }

        int viTriMaxTuoi = 0;
        for (int i = 1; i < n; ++i) {
            if (nhanVienVP[i].LonTuoiHon(nhanVienVP[viTriMaxTuoi])) {
                viTriMaxTuoi = i;
            }
        }
        return viTriMaxTuoi;
    }

public:
    cListNhanVienVP() : nhanVienVP(nullptr), n(0) {
    }

    cListNhanVienVP(const cListNhanVienVP& other) : nhanVienVP(nullptr), n(0) {
        SaoChepTu(other);
    }

    cListNhanVienVP& operator=(const cListNhanVienVP& other) {
        if (this != &other) {
            GiaiPhong();
            SaoChepTu(other);
        }
        return *this;
    }

    ~cListNhanVienVP() {
        delete[] nhanVienVP;
    }

    void Nhap() {
        int soLuong;
        do {
            cout << "Nhap so luong nhan vien van phong: ";
            cin >> soLuong;
        } while (soLuong < 0);

        GiaiPhong();
        n = soLuong;

        if (n == 0) {
            return;
        }

        nhanVienVP = new cNhanVienVP[n];
        for (int i = 0; i < n; ++i) {
            cout << "\nNhap thong tin nhan vien thu " << i + 1 << ":\n";
            nhanVienVP[i].NhapNhanVien();
        }
    }

    void Xuat() const {
        if (n == 0) {
            cout << "Danh sach nhan vien rong.\n";
            return;
        }

        XuatTieuDe();
        for (int i = 0; i < n; ++i) {
            nhanVienVP[i].XuatNhanVien();
        }
    }

    double TinhTongLuong() const {
        double tong = 0.0;
        for (int i = 0; i < n; ++i) {
            tong += nhanVienVP[i].GetLuong();
        }
        return tong;
    }

    void XuatNhanVienLuongCaoNhat() const {
        int viTriMax = TimViTriLuongCaoNhat();
        if (viTriMax == -1) {
            cout << "Danh sach nhan vien rong.\n";
            return;
        }

        XuatTieuDe();
        nhanVienVP[viTriMax].XuatNhanVien();
    }

    void XuatNhanVienLonTuoiNhat() const {
        int viTriMaxTuoi = TimViTriLonTuoiNhat();
        if (viTriMaxTuoi == -1) {
            cout << "Danh sach nhan vien rong.\n";
            return;
        }

        XuatTieuDe();
        nhanVienVP[viTriMaxTuoi].XuatNhanVien();
    }

    void SapXepTangDanTheoLuong() {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nhanVienVP[j].GetLuong() < nhanVienVP[i].GetLuong() ||
                    (nhanVienVP[j].GetLuong() == nhanVienVP[i].GetLuong() &&
                     nhanVienVP[j].GetMa() < nhanVienVP[i].GetMa())) {
                    HoanDoi(nhanVienVP[i], nhanVienVP[j]);
                }
            }
        }
    }
};
