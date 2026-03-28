//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/*
Viết chương trình cho phép người dùng nhập vào một ngày (ngày tháng năm).
Kiểm tra tính hợp lệ và xuất ra màn hình ngày kế tiếp.
*/
#include <iostream>
using namespace std;

struct Ngay {
     int ngay;
     int thang;
     int nam;
};

bool NamNhuan(int nam) {
     return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int SoNgayTrongThang(int thang, int nam) {
     switch (thang) {
          case 1: case 3: case 5: case 7: case 8: case 10: case 12:
               return 31;
          case 4: case 6: case 9: case 11:
               return 30;
          case 2:
               return NamNhuan(nam) ? 29 : 28;
          default:
               return 0;
     }
}

bool KiemTraHopLe(Ngay ngay) {
     if (ngay.nam < 1) return false;
     if (ngay.thang < 1 || ngay.thang > 12) return false;
     if (ngay.ngay < 1 || ngay.ngay > SoNgayTrongThang(ngay.thang, ngay.nam)) return false;
     return true;
}

void NhapNgay(Ngay& ngay) {
     cout << "Nhap ngay: ";
     cin >> ngay.ngay;
     cout << "Nhap thang: ";
     cin >> ngay.thang;
     cout << "Nhap nam: ";
     cin >> ngay.nam;
}

void NgayKeTiep (Ngay& ngay) {
     ngay.ngay++;
     if (ngay.ngay > SoNgayTrongThang(ngay.thang, ngay.nam)) {
          ngay.ngay = 1;
          ngay.thang++;
          if (ngay.thang > 12) {
               ngay.thang = 1;
               ngay.nam++;
          }
     }
}

void XuatNgay(Ngay ngay) {
     cout << ngay.ngay << "/" << ngay.thang << "/" << ngay.nam << endl;
}

int main() {
     Ngay ngay;
     NhapNgay(ngay);
     if (KiemTraHopLe(ngay)) {
          NgayKeTiep(ngay);
          XuatNgay(ngay);
     } else {
          cout << "Ngay khong hop le!" << endl;
     }
     return 0;
}

