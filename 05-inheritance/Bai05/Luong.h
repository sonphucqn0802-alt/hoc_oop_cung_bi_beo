#include <iostream>
#include <string>
using namespace std;

class NhanVien {
protected:
     string HoTen;
     string NgaySinh;
     double Luong;

public:
     NhanVien() : Luong(0) {}

     void inputBase() {
          cout << "Ho ten: ";
          cin.ignore(10000, '\n');
          getline(cin, HoTen);
          cout << "Ngay sinh: ";
          cin >> NgaySinh;
     }

     void outputBase() {
          cout << "Ho ten: " << HoTen << endl;
          cout << "Ngay sinh: " << NgaySinh << endl;
          cout << "Luong: " << Luong << endl;
     }

     double getLuong() {
          return Luong;
     }
};

class NhanVienSanXuat : public NhanVien {
private:
     double LuongCanBan;
     int SoSanPham;

public:
     NhanVienSanXuat() : LuongCanBan(0), SoSanPham(0) {}

     void input() {
          inputBase();
          cout << "Luong can ban: ";
          cin >> LuongCanBan;
          cout << "So san pham: ";
          cin >> SoSanPham;
          tinhLuong();
     }

     void output() {
          outputBase();
          cout << "Luong can ban: " << LuongCanBan << endl;
          cout << "So san pham: " << SoSanPham << endl;
     }

     void tinhLuong() {
          Luong = LuongCanBan + SoSanPham * 5000;
     }
};

class NhanVienVanPhong : public NhanVien {
private:
     int SoNgayLamViec;

public:
     NhanVienVanPhong() : SoNgayLamViec(0) {}

     void input() {
          inputBase();
          cout << "So ngay lam viec: ";
          cin >> SoNgayLamViec;
          tinhLuong();
     }

     void output() {
          outputBase();
          cout << "So ngay lam viec: " << SoNgayLamViec << endl;
     }

     void tinhLuong() {
          Luong = SoNgayLamViec * 100000;
     }
};
