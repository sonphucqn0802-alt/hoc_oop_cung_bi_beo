#include <iostream>
#include <string>
using namespace std;

class GiaoDich {
protected:
     string MaGiaoDich;
     string NgayGiaoDich;
     double DonGia;
     int SoLuong;

public:
     GiaoDich() : DonGia(0), SoLuong(0) {}

     void inputBase() {
          cout << "Ma giao dich: ";
          cin >> MaGiaoDich;
          cout << "Ngay giao dich: ";
          cin >> NgayGiaoDich;
          cout << "Don gia: ";
          cin >> DonGia;
          cout << "So luong: ";
          cin >> SoLuong;
     }

     void outputBase() {
          cout << "Ma giao dich: " << MaGiaoDich << endl;
          cout << "Ngay giao dich: " << NgayGiaoDich << endl;
          cout << "Don gia: " << DonGia << endl;
          cout << "So luong: " << SoLuong << endl;
     }
};

class GiaoDichVang : public GiaoDich {
private:
     string LoaiVang;

public:
     void input() {
          inputBase();
          cout << "Loai vang: ";
          cin >> LoaiVang;
     }

     void output() {
          outputBase();
          cout << "Loai vang: " << LoaiVang << endl;
          cout << "Thanh tien: " << getThanhTien() << endl;
     }

     double getThanhTien() {
          return SoLuong * DonGia;
     }
};

class GiaoDichTienTe : public GiaoDich {
private:
     double TiGia;
     string LoaiTienTe;

public:
     GiaoDichTienTe() : TiGia(0) {}

     void input() {
          inputBase();
          cout << "Ti gia: ";
          cin >> TiGia;
          cout << "Loai tien te (VN/USD/Euro): ";
          cin >> LoaiTienTe;
     }

     void output() {
          outputBase();
          cout << "Ti gia: " << TiGia << endl;
          cout << "Loai tien te: " << LoaiTienTe << endl;
          cout << "Thanh tien: " << getThanhTien() << endl;
     }

     double getThanhTien() {
          if (LoaiTienTe == "USD" || LoaiTienTe == "Euro" || LoaiTienTe == "EURO") {
               return SoLuong * DonGia * TiGia;
          }

          return SoLuong * DonGia;
     }

     bool laEuro() {
          return LoaiTienTe == "Euro" || LoaiTienTe == "EURO";
     }
};
