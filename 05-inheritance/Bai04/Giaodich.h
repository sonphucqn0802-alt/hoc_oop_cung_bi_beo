#include <iostream>
#include <string>
using namespace std;

class GiaoDich {
protected:
     string MaGiaoDich;
     string NgayGiaoDich;
     double DonGia;
     double DienTich;

public:
     GiaoDich() : DonGia(0), DienTich(0) {}

     void inputBase() {
          cout << "Ma giao dich: ";
          cin >> MaGiaoDich;
          cout << "Ngay giao dich: ";
          cin >> NgayGiaoDich;
          cout << "Don gia: ";
          cin >> DonGia;
     }

     void outputBase() {
          cout << "Ma giao dich: " << MaGiaoDich << endl;
          cout << "Ngay giao dich: " << NgayGiaoDich << endl;
          cout << "Don gia: " << DonGia << endl;
          cout << "Dien tich: " << DienTich << endl;
     }

     bool laThang12Nam2024() {
          return NgayGiaoDich.find("/12/2024") != string::npos
               || NgayGiaoDich.find("-12-2024") != string::npos
               || NgayGiaoDich.find(".12.2024") != string::npos;
     }
};

class GiaoDichDat : public GiaoDich {
private:
     string LoaiDat;

public:
     void input() {
          inputBase();
          cout << "Loai dat (A/B/C): ";
          cin >> LoaiDat;
          cout << "Dien tich: ";
          cin >> DienTich;
     }

     void output() {
          outputBase();
          cout << "Loai dat: " << LoaiDat << endl;
          cout << "Thanh tien: " << getThanhTien() << endl;
     }

     double getThanhTien() {
          if (LoaiDat == "A" || LoaiDat == "a") {
               return DienTich * DonGia * 1.5;
          }

          return DienTich * DonGia;
     }
};

class GiaoDichNhaPho : public GiaoDich {
private:
     string LoaiNha;
     string DiaChi;

public:
     void input() {
          inputBase();
          cout << "Loai nha (cao_cap/thuong): ";
          cin >> LoaiNha;
          cout << "Dia chi: ";
          cin.ignore(10000, '\n');
          getline(cin, DiaChi);
          cout << "Dien tich: ";
          cin >> DienTich;
     }

     void output() {
          outputBase();
          cout << "Loai nha: " << LoaiNha << endl;
          cout << "Dia chi: " << DiaChi << endl;
          cout << "Thanh tien: " << getThanhTien() << endl;
     }

     double getThanhTien() {
          if (LoaiNha == "cao_cap" || LoaiNha == "Cao_cap" || LoaiNha == "CaoCap") {
               return DienTich * DonGia;
          }

          return DienTich * DonGia * 0.9;
     }
};

class GiaoDichCanHo : public GiaoDich {
private:
     string MaCan;
     int ViTriTang;

public:
     GiaoDichCanHo() : ViTriTang(0) {}

     void input() {
          inputBase();
          cout << "Ma can: ";
          cin >> MaCan;
          cout << "Vi tri tang: ";
          cin >> ViTriTang;
          cout << "Dien tich: ";
          cin >> DienTich;
     }

     void output() {
          outputBase();
          cout << "Ma can: " << MaCan << endl;
          cout << "Vi tri tang: " << ViTriTang << endl;
          cout << "Thanh tien: " << getThanhTien() << endl;
     }

     double getThanhTien() {
          if (ViTriTang == 1) {
               return DienTich * DonGia * 2;
          }

          if (ViTriTang >= 15) {
               return DienTich * DonGia * 1.2;
          }

          return DienTich * DonGia;
     }
};
