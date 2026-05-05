#include <iostream>
using namespace std;

class ThuVien {
     private:
     int MaSach;
     string NgayNhap;
     float DonGia;
     int SoLuong;
     string NhaXuatBan;

     public:
     void input() {
          cout << "Ma sach: ";
          cin >> MaSach;
          cout << "Ngay nhap: ";
          cin >> NgayNhap;
          cout << "Don gia: ";
          cin >> DonGia;
          cout << "So luong: ";
          cin >> SoLuong;
          cout << "Nha xuat ban: ";
          cin >> NhaXuatBan;
     }

     void output() {
          cout << "Ma sach: " << MaSach << endl;
          cout << "Ngay nhap: " << NgayNhap << endl;
          cout << "Don gia: " << DonGia << endl;
          cout << "So luong: " << SoLuong << endl;
          cout << "Nha xuat ban: " << NhaXuatBan << endl;
     }
};


class SachGiaoKhoa : public ThuVien {
    private:
    bool TinhTrang; //0 la cu, 1 la moi
    
    public:
    void input() {
        ThuVien::input();
        cout << "Tinh trang (0 la cu, 1 la moi): ";
        cin >> TinhTrang;
    }

    void output() {
        ThuVien::output();
        cout << "Tinh trang (0 la cu, 1 la moi): " << TinhTrang << endl;
    }

    double getThanhTien() {
        return DonGia * SoLuong * (TinhTrang ? 1 : 0.5);
    }
};

class SachThamKhao : public ThuVien {
    private:
    float Thue;
    
    public:
    void input() {
        ThuVien::input();
        cout << "Thue: ";
        cin >> Thue;
    }

    void output() {
        ThuVien::output();
        cout << "Thue: " << Thue << endl;
    }

    double getThanhTien() {
        return DonGia * SoLuong + Thue;
    }
};

