//Mã số sinh viên: 25521438
//Họ và tên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27



#pragma once

#include <bits/stdc++.h>

using namespace std;

string nhapChuoi(const string& thongBao) {
    string giaTri;
    
    do {
        cout << thongBao;
        getline(cin, giaTri);
    } while (giaTri.empty());
    return giaTri;
}

int nhapSoNguyen(
    const string& thongBao,
    int minValue = INT_MIN,
    int maxValue = INT_MAX ) {
    int giaTri;

    while (true) {
        cout << thongBao;

        if (!(cin >> giaTri)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Du lieu khong hop le. Vui long nhap so nguyen.\n";
            continue;
        }

        cin.ignore(10000, '\n');

        if (giaTri < minValue || giaTri > maxValue) {
            cout << "Gia tri phai nam trong khoang [" << minValue << ", " << maxValue
                 << "]. Vui long nhap lai.\n";
            continue;
        }

        return giaTri;
    }
}

float nhapSoThuc(
    const string& thongBao,
    float minValue = -FLT_MAX,
    float maxValue = FLT_MAX) {
    float giaTri;

    while (true) {
        cout << thongBao;

        if (!(cin >> giaTri)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Du lieu khong hop le. Vui long nhap so.\n";
            continue;
        }

        cin.ignore(10000, '\n');

        if (giaTri < minValue || giaTri > maxValue) {
            cout << "Gia tri phai nam trong khoang [" << minValue << ", " << maxValue
                 << "]. Vui long nhap lai.\n";
            continue;
        }

        return giaTri;
    }
}

class SinhVien {
private:
    int heHoc;  // 0: Cao dang, 1: Dai hoc
    string MSSV;
    string hoTen;
    string diaChi;
    int tongSoTinChi;
    float diemTrungBinh;
    float diemThiTotNghiep;
    string tenLuanVan;
    float diemLuanVan;

public:
    SinhVien()
        : heHoc(0),
          tongSoTinChi(0),
          diemTrungBinh(0.0),
          diemThiTotNghiep(0.0),
          diemLuanVan(0.0) {}

    ~SinhVien() {}

    void setHeHoc(int heHoc) { this->heHoc = heHoc; }
    void setMSSV(const string& MSSV) { this->MSSV = MSSV; }
    void setHoTen(const string& hoTen) { this->hoTen = hoTen; }
    void setDiaChi(const string& diaChi) { this->diaChi = diaChi; }
    void setTongSoTinChi(int tongSoTinChi) { this->tongSoTinChi = tongSoTinChi; }
    void setDiemTrungBinh(float diemTrungBinh) { this->diemTrungBinh = diemTrungBinh; }
    void setDiemThiTotNghiep(float diemThiTotNghiep) { this->diemThiTotNghiep = diemThiTotNghiep; }
    void setTenLuanVan(const string& tenLuanVan) { this->tenLuanVan = tenLuanVan; }
    void setDiemLuanVan(float diemLuanVan) { this->diemLuanVan = diemLuanVan; }

    int getHeHoc() const { return heHoc; }
    string getMSSV() const { return MSSV; }
    string getHoTen() const { return hoTen; }
    string getDiaChi() const { return diaChi; }
    int getTongSoTinChi() const { return tongSoTinChi; }
    float getDiemTrungBinh() const { return diemTrungBinh; }
    float getDiemThiTotNghiep() const { return diemThiTotNghiep; }
    string getTenLuanVan() const { return tenLuanVan; }
    float getDiemLuanVan() const { return diemLuanVan; }

    bool laSinhVienCaoDang() const { return heHoc == 0; }
    bool laSinhVienDaiHoc() const { return heHoc == 1; }

    bool duDieuKienTotNghiep() const {
        if (laSinhVienCaoDang()) {
            return tongSoTinChi >= 110 && diemTrungBinh >= 5.0 &&
                   diemThiTotNghiep >= 5.0;
        }

        return tongSoTinChi >= 145 && diemTrungBinh >= 5.0 && diemLuanVan >= 5.0;
    }

    void nhap() {
        heHoc = nhapSoNguyen("Nhap he hoc (0 - Cao dang, 1 - Dai hoc): ", 0, 1);
        MSSV = nhapChuoi("Nhap MSSV: ");
        hoTen = nhapChuoi("Nhap ho ten: ");
        diaChi = nhapChuoi("Nhap dia chi: ");
        tongSoTinChi = nhapSoNguyen("Nhap tong so tin chi: ", 0);
        diemTrungBinh = nhapSoThuc("Nhap diem trung binh: ", 0.0, 10.0);

        if (laSinhVienCaoDang()) {
            diemThiTotNghiep = nhapSoThuc("Nhap diem thi tot nghiep: ", 0.0, 10.0);
            tenLuanVan.clear();
            diemLuanVan = 0.0;
        } else {
            tenLuanVan = nhapChuoi("Nhap ten luan van: ");
            diemLuanVan = nhapSoThuc("Nhap diem luan van: ", 0.0, 10.0);
            diemThiTotNghiep = 0.0;
        }
    }

    void xuat() const {
        cout << "He hoc: " << (laSinhVienCaoDang() ? "Cao dang" : "Dai hoc") << '\n';
        cout << "MSSV: " << MSSV << '\n';
        cout << "Ho ten: " << hoTen << '\n';
        cout << "Dia chi: " << diaChi << '\n';
        cout << "Tong so tin chi: " << tongSoTinChi << '\n';
        cout << fixed << setprecision(2);
        cout << "Diem trung binh: " << diemTrungBinh << '\n';

        if (laSinhVienCaoDang()) {
            cout << "Diem thi tot nghiep: " << diemThiTotNghiep << '\n';
        } else {
            cout << "Ten luan van: " << tenLuanVan << '\n';
            cout << "Diem luan van: " << diemLuanVan << '\n';
        }

        cout << "Tinh trang tot nghiep: "
             << (duDieuKienTotNghiep() ? "Du dieu kien" : "Chua du dieu kien") << '\n';
    }
};

class QuanLySinhVien {
private:
    vector<SinhVien> danhSach;

public:
    void nhapDanhSach() {
        int soLuong = nhapSoNguyen("Nhap so luong sinh vien: ", 0);
        danhSach.clear();
        danhSach.reserve(soLuong);

        for (int i = 0; i < soLuong; ++i) {
            cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":\n";
            SinhVien sv;
            sv.nhap();
            danhSach.push_back(sv);
        }
    }

    void xuatDanhSach() const {
        if (danhSach.empty()) {
            cout << "Danh sach sinh vien dang rong.\n";
            return;
        }

        cout << "\n===== DANH SACH SINH VIEN =====\n";
        for (size_t i = 0; i < danhSach.size(); ++i) {
            cout << "\nSinh vien thu " << i + 1 << ":\n";
            danhSach[i].xuat();
        }
    }

    int demSinhVienDuTotNghiep() const {
        int dem = 0;

        for (const SinhVien& sv : danhSach) {
            if (sv.duDieuKienTotNghiep()) {
                ++dem;
            }
        }

        return dem;
    }

    vector<SinhVien> timSinhVienDaiHocDiemCaoNhat() const {
        vector<SinhVien> ketQua;
        float diemCaoNhat = -1.0;

        for (const SinhVien& sv : danhSach) {
            if (!sv.laSinhVienDaiHoc()) {
                continue;
            }

            if (sv.getDiemTrungBinh() > diemCaoNhat) {
                diemCaoNhat = sv.getDiemTrungBinh();
                ketQua.clear();
                ketQua.push_back(sv);
            } else if (sv.getDiemTrungBinh() == diemCaoNhat) {
                ketQua.push_back(sv);
            }
        }

        return ketQua;
    }

    bool rong() const { return danhSach.empty(); }
};
