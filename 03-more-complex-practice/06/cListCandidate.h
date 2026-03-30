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

class cCandidate {
private:
    int ma;
    string ten;
    DateofBirth ngaySinh;
    float diemToan;
    float diemVan;
    float diemAnh;

    float NhapDiem(const string& tenMon) {
        float diem;
        do {
            cout << "Nhap diem " << tenMon << " [0..10]: ";
            cin >> diem;
        } while (diem < 0 || diem > 10);
        return diem;
    }

public:
    cCandidate(int ma = 0, const string& ten = "", const DateofBirth& ngaySinh = DateofBirth(),
               float diemToan = 0, float diemVan = 0, float diemAnh = 0)
        : ma(ma), ten(ten), ngaySinh(ngaySinh), diemToan(diemToan), diemVan(diemVan), diemAnh(diemAnh) {
    }

    void Nhap() {
        cout << "Nhap ma thi sinh: ";
        cin >> ma;

        cin.ignore();
        do {
            cout << "Nhap ho ten: ";
            getline(cin, ten);
        } while (ten.empty());

        ngaySinh.Nhap();
        diemToan = NhapDiem("Toan");
        diemVan = NhapDiem("Van");
        diemAnh = NhapDiem("Anh");
    }

    float TongDiem() const {
        return diemToan + diemVan + diemAnh;
    }

    int GetMa() const {
        return ma;
    }

    void Xuat() const {
        cout << ma << "/"
             << ten << "/";
        ngaySinh.Xuat();
        cout << "/";
        cout << fixed << setprecision(2)
             << diemToan << "-"
             << diemVan << "-"
             << diemAnh << "-"
             << TongDiem() << '\n';
    }
};

class cListCandidate {
private:
    cCandidate* candidates;
    int n;

    void GiaiPhong() {
        delete[] candidates;
        candidates = nullptr;
        n = 0;
    }

    void SaoChepTu(const cListCandidate& other) {
        n = other.n;
        if (n == 0) {
            candidates = nullptr;
            return;
        }

        candidates = new cCandidate[n];
        for (int i = 0; i < n; ++i) {
            candidates[i] = other.candidates[i];
        }
    }

    void HoanDoi(cCandidate& a, cCandidate& b) {
        cCandidate temp = a;
        a = b;
        b = temp;
    }

    void XuatTieuDe() const {
        cout << "Ma" << "/"
             << "Ho ten" << "/"
             << "Ngay sinh" << "/"
             << "Toan" << "/"
             << "Van" << "/"
             << "Anh" << "/"
             << "Tong" << '\n';
        cout << string(80, '-') << '\n';
    }

    int TimViTriTongDiemCaoNhat() const {
        if (n == 0) {
            return -1;
        }

        int viTriMax = 0;
        for (int i = 1; i < n; ++i) {
            if (candidates[i].TongDiem() > candidates[viTriMax].TongDiem()) {
                viTriMax = i;
            }
        }
        return viTriMax;
    }

public:
    cListCandidate() : candidates(nullptr), n(0) {
    }

    cListCandidate(const cListCandidate& other) : candidates(nullptr), n(0) {
        SaoChepTu(other);
    }

    cListCandidate& operator=(const cListCandidate& other) {
        if (this != &other) {
            GiaiPhong();
            SaoChepTu(other);
        }
        return *this;
    }

    ~cListCandidate() {
        delete[] candidates;
    }

    void Nhap() {
        int soLuong;
        do {
            cout << "Nhap so luong thi sinh: ";
            cin >> soLuong;
        } while (soLuong < 0);

        GiaiPhong();
        n = soLuong;

        if (n == 0) {
            return;
        }

        candidates = new cCandidate[n];
        for (int i = 0; i < n; ++i) {
            cout << "\nNhap thong tin thi sinh thu " << i + 1 << ":\n";
            candidates[i].Nhap();
        }
    }

    void Xuat() const {
        if (n == 0) {
            cout << "Danh sach thi sinh rong.\n";
            return;
        }

        XuatTieuDe();
        for (int i = 0; i < n; ++i) {
            candidates[i].Xuat();
        }
    }

    void XuatThiSinhTongLonHon15() const {
        bool timThay = false;
        for (int i = 0; i < n; ++i) {
            if (candidates[i].TongDiem() > 15) {
                if (!timThay) {
                    XuatTieuDe();
                }
                candidates[i].Xuat();
                timThay = true;
            }
        }

        if (!timThay) {
            cout << "Khong co thi sinh nao co tong diem lon hon 15.\n";
        }
    }

    void XuatThiSinhTongCaoNhat() const {
        int viTriMax = TimViTriTongDiemCaoNhat();
        if (viTriMax == -1) {
            cout << "Danh sach thi sinh rong.\n";
            return;
        }

        XuatTieuDe();
        candidates[viTriMax].Xuat();
    }

    void SapXepGiamDanTheoTongDiem() {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (candidates[j].TongDiem() > candidates[i].TongDiem() ||
                    (candidates[j].TongDiem() == candidates[i].TongDiem() &&
                     candidates[j].GetMa() < candidates[i].GetMa())) {
                    HoanDoi(candidates[i], candidates[j]);
                }
            }
        }
    }
};
