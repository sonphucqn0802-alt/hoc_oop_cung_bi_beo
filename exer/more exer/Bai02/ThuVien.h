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

        if (giaTri.empty()) {
            cout << "Khong duoc de trong. Vui long nhap lai.\n";
        }
    } while (giaTri.empty());

    return giaTri;
}

int nhapSoNguyen(
    const string& thongBao,
    int minValue = INT_MIN,
    int maxValue = INT_MAX) {
    int giaTri;

    while (true) {
        cout << thongBao;

        if (!(cin >> giaTri)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Du lieu khong hop le. Vui long nhap lai.\n";
            continue;
        }

        cin.ignore(10000, '\n');

        if (giaTri < minValue || giaTri > maxValue) {
            cout << "Gia tri khong hop le. Vui long nhap lai.\n";
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
            cout << "Du lieu khong hop le. Vui long nhap lai.\n";
            continue;
        }

        cin.ignore(10000, '\n');

        if (giaTri < minValue || giaTri > maxValue) {
            cout << "Gia tri khong hop le. Vui long nhap lai.\n";
            continue;
        }

        return giaTri;
    }
}

class Sach {
private:
    bool Loai;  // 0: SGK, 1: STK
    string ID;
    string TenSach;
    string NhaXuatBan;
    int SoLuong;
    float DonGia;
    bool TinhTrang;  // 0: Cu, 1: Moi
    float TienThue;

public:
    Sach()
        : Loai(0),
          SoLuong(0),
          DonGia(0.0),
          TinhTrang(1),
          TienThue(0.0) {}

    ~Sach() {}

    void setLoai(bool loai) { Loai = loai; }
    void setID(const string& id) { ID = id; }
    void setTenSach(const string& tenSach) { TenSach = tenSach; }
    void setNhaXuatBan(const string& nhaXuatBan) { NhaXuatBan = nhaXuatBan; }
    void setSoLuong(int soLuong) { SoLuong = soLuong; }
    void setDonGia(float donGia) { DonGia = donGia; }
    void setTinhTrang(bool tinhTrang) { TinhTrang = tinhTrang; }
    void setTienThue(float tienThue) { TienThue = tienThue; }

    bool getLoai() const { return Loai; }
    string getID() const { return ID; }
    string getTenSach() const { return TenSach; }
    string getNhaXuatBan() const { return NhaXuatBan; }
    int getSoLuong() const { return SoLuong; }
    float getDonGia() const { return DonGia; }
    bool getTinhTrang() const { return TinhTrang; }
    float getTienThue() const { return TienThue; }

    bool laSachGiaoKhoa() const { return Loai == 0; }
    bool laSachThamKhao() const { return Loai == 1; }
    bool laSachCu() const { return TinhTrang == 0; }
    bool laSachMoi() const { return TinhTrang == 1; }

    float tinhTien() const {
        if (laSachGiaoKhoa()) {
            if (laSachMoi()) {
                return SoLuong * DonGia;
            }

            return SoLuong * DonGia * 0.5;
        }

        return SoLuong * DonGia + TienThue;
    }

    bool laSachGiaoKhoaCuaNhaXuatBan(const string& nhaXuatBan) const {
        return laSachGiaoKhoa() && NhaXuatBan == nhaXuatBan;
    }

    void Nhap() {
        Loai = nhapSoNguyen("Nhap loai (0 - SGK, 1 - STK): ", 0, 1);
        ID = nhapChuoi("Nhap ma sach: ");
        TenSach = nhapChuoi("Nhap ten sach: ");
        NhaXuatBan = nhapChuoi("Nhap nha xuat ban: ");
        SoLuong = nhapSoNguyen("Nhap so luong: ", 0);
        DonGia = nhapSoThuc("Nhap don gia: ", 0.0);

        if (laSachGiaoKhoa()) {
            TinhTrang = nhapSoNguyen("Nhap tinh trang (0 - Cu, 1 - Moi): ", 0, 1);
            TienThue = 0.0;
        } else {
            TienThue = nhapSoThuc("Nhap tien thue: ", 0.0);
            TinhTrang = 1;
        }
    }

    void Xuat() const {
        cout << fixed << setprecision(2);
        cout << "Loai sach: " << (laSachGiaoKhoa() ? "Sach giao khoa" : "Sach tham khao")
             << '\n';
        cout << "Ma sach: " << ID << '\n';
        cout << "Ten sach: " << TenSach << '\n';
        cout << "Nha xuat ban: " << NhaXuatBan << '\n';
        cout << "So luong: " << SoLuong << '\n';
        cout << "Don gia: " << DonGia << '\n';

        if (laSachGiaoKhoa()) {
            cout << "Tinh trang: " << (laSachMoi() ? "Moi" : "Cu") << '\n';
        } else {
            cout << "Tien thue: " << TienThue << '\n';
        }

        cout << "Thanh tien: " << tinhTien() << '\n';
    }
};

class ThuVien {
private:
    vector<Sach> danhSach;

public:
    void nhapDanhSach() {
        int soLuong = nhapSoNguyen("Nhap so luong sach: ", 0);
        danhSach.clear();
        danhSach.reserve(soLuong);

        for (int i = 0; i < soLuong; ++i) {
            cout << "\nNhap thong tin sach thu " << i + 1 << ":\n";
            Sach sach;
            sach.Nhap();
            danhSach.push_back(sach);
        }
    }

    void xuatDanhSach() const {
        if (danhSach.empty()) {
            cout << "Danh sach sach dang rong.\n";
            return;
        }

        cout << "\n===== DANH SACH SACH =====\n";
        for (size_t i = 0; i < danhSach.size(); ++i) {
            cout << "\nSach thu " << i + 1 << ":\n";
            danhSach[i].Xuat();
        }
    }

    float tongThanhTienSachGiaoKhoa() const {
        float tong = 0.0;

        for (size_t i = 0; i < danhSach.size(); ++i) {
            if (danhSach[i].laSachGiaoKhoa()) {
                tong += danhSach[i].tinhTien();
            }
        }

        return tong;
    }

    float tongThanhTienSachThamKhao() const {
        float tong = 0.0;

        for (size_t i = 0; i < danhSach.size(); ++i) {
            if (danhSach[i].laSachThamKhao()) {
                tong += danhSach[i].tinhTien();
            }
        }

        return tong;
    }

    void xuatThongTinSachCoThanhTienItNhat() const {
        if (danhSach.empty()) {
            cout << "Danh sach sach dang rong.\n";
            return;
        }

        float minThanhTien = danhSach[0].tinhTien();

        for (size_t i = 1; i < danhSach.size(); ++i) {
            if (danhSach[i].tinhTien() < minThanhTien) {
                minThanhTien = danhSach[i].tinhTien();
            }
        }

        cout << "\nNhung sach co thanh tien it nhat:\n";
        for (size_t i = 0; i < danhSach.size(); ++i) {
            if (fabs(danhSach[i].tinhTien() - minThanhTien) < 0.0001) {
                cout << "\nSach thu " << i + 1 << ":\n";
                danhSach[i].Xuat();
            }
        }
    }

    void timKiemTheoNhaXuatBan(const string& nhaXuatBan) const {
        if (danhSach.empty()) {
            cout << "Danh sach sach dang rong.\n";
            return;
        }

        bool timThay = false;

        for (size_t i = 0; i < danhSach.size(); ++i) {
            if (danhSach[i].laSachGiaoKhoaCuaNhaXuatBan(nhaXuatBan)) {
                if (!timThay) {
                    cout << "\nCac sach giao khoa cua nha xuat ban " << nhaXuatBan << ":\n";
                }

                cout << "\nSach thu " << i + 1 << ":\n";
                danhSach[i].Xuat();
                timThay = true;
            }
        }

        if (!timThay) {
            cout << "Khong tim thay sach giao khoa cua nha xuat ban " << nhaXuatBan
                 << ".\n";
        }
    }

    bool rong() const { return danhSach.empty(); }
};
