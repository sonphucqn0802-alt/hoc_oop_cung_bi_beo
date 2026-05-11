#include <iostream>
#include <string>
using namespace std;

class SinhVien {
protected:
     string MaSo;
     string HoTen;
     string DiaChi;
     int TongSoTinChi;
     double DiemTrungBinh;

public:
     SinhVien() : TongSoTinChi(0), DiemTrungBinh(0) {}

     void inputBase() {
          cout << "Ma so sinh vien: ";
          cin >> MaSo;
          cout << "Ho ten: ";
          cin.ignore(10000, '\n');
          getline(cin, HoTen);
          cout << "Dia chi: ";
          getline(cin, DiaChi);
          cout << "Tong so tin chi: ";
          cin >> TongSoTinChi;
          cout << "Diem trung binh: ";
          cin >> DiemTrungBinh;
     }

     void outputBase() {
          cout << "Ma so sinh vien: " << MaSo << endl;
          cout << "Ho ten: " << HoTen << endl;
          cout << "Dia chi: " << DiaChi << endl;
          cout << "Tong so tin chi: " << TongSoTinChi << endl;
          cout << "Diem trung binh: " << DiemTrungBinh << endl;
     }

     double getDiemTrungBinh() {
          return DiemTrungBinh;
     }
};

class SinhVienCaoDang : public SinhVien {
private:
     double DiemThiTotNghiep;

public:
     SinhVienCaoDang() : DiemThiTotNghiep(0) {}

     void input() {
          inputBase();
          cout << "Diem thi tot nghiep: ";
          cin >> DiemThiTotNghiep;
     }

     void output() {
          outputBase();
          cout << "Diem thi tot nghiep: " << DiemThiTotNghiep << endl;
     }

     bool duDieuKienTotNghiep() {
          return TongSoTinChi >= 110 && DiemTrungBinh >= 5 && DiemThiTotNghiep >= 5;
     }
};

class SinhVienDaiHoc : public SinhVien {
private:
     string TenLuanVan;
     double DiemLuanVan;

public:
     SinhVienDaiHoc() : DiemLuanVan(0) {}

     void input() {
          inputBase();
          cout << "Ten luan van: ";
          cin.ignore(10000, '\n');
          getline(cin, TenLuanVan);
          cout << "Diem luan van: ";
          cin >> DiemLuanVan;
     }

     void output() {
          outputBase();
          cout << "Ten luan van: " << TenLuanVan << endl;
          cout << "Diem luan van: " << DiemLuanVan << endl;
     }

     bool duDieuKienTotNghiep() {
          return TongSoTinChi >= 145 && DiemTrungBinh >= 5 && DiemLuanVan >= 5;
     }
};
