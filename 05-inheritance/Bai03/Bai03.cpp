//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27.1

/*Cong ty X co nhu cau quan ly danh sach cac giao dich, hien tai cong ty co 2 loai
giao dich:
- Giao dich vang: Ma giao dich, ngay giao dich, don gia, so luong, loai vang.
Thanh tien = so luong * don gia.
- Giao dich tien te: Ma giao dich, ngay giao dich, don gia, so luong, ti gia, loai
tien te co 3 loai: tien Viet Nam, tien USD, tien Euro.
Ap dung tinh ke thua, thiet ke cac lop va xay dung chuong trinh cho phep thuc hien
cac yeu cau sau:
- Nhap danh sach cac giao dich vang
- Nhap danh sach cac giao dich ngoai te
- Cho biet giao dich vang nao co thanh tien cao nhat
- Cho biet giao dich ngoai te Euro nao co gia tri thap nhat
- Xuat ra cac giao dich co thanh tien tren 1 ty dong*/

#include "Giaodich.h"
using namespace std;

int main() {
     int n, m;
     cout << "Nhap so giao dich vang: ";
     cin >> n;
     cout << "Nhap so giao dich tien te: ";
     cin >> m;

     GiaoDichVang *gdv = new GiaoDichVang[n];
     GiaoDichTienTe *gdtt = new GiaoDichTienTe[m];

     for (int i = 0; i < n; i++) {
          cout << "\nGiao dich vang thu " << i + 1 << endl;
          gdv[i].input();
     }

     for (int i = 0; i < m; i++) {
          cout << "\nGiao dich tien te thu " << i + 1 << endl;
          gdtt[i].input();
     }

     if (n > 0) {
          int viTriMax = 0;
          for (int i = 1; i < n; i++) {
               if (gdv[i].getThanhTien() > gdv[viTriMax].getThanhTien()) {
                    viTriMax = i;
               }
          }

          cout << "\nGiao dich vang co thanh tien cao nhat" << endl;
          gdv[viTriMax].output();
     }

     int viTriEuroMin = -1;
     for (int i = 0; i < m; i++) {
          if (gdtt[i].laEuro()) {
               if (viTriEuroMin == -1 || gdtt[i].getThanhTien() < gdtt[viTriEuroMin].getThanhTien()) {
                    viTriEuroMin = i;
               }
          }
     }

     if (viTriEuroMin != -1) {
          cout << "\nGiao dich tien te Euro co thanh tien thap nhat" << endl;
          gdtt[viTriEuroMin].output();
     } else {
          cout << "\nKhong co giao dich tien te Euro" << endl;
     }

     cout << "\nCac giao dich co thanh tien tren 1 ty dong" << endl;
     for (int i = 0; i < n; i++) {
          if (gdv[i].getThanhTien() > 1000000000) {
               cout << "\nGiao dich vang thu " << i + 1 << endl;
               gdv[i].output();
          }
     }

     for (int i = 0; i < m; i++) {
          if (gdtt[i].getThanhTien() > 1000000000) {
               cout << "\nGiao dich tien te thu " << i + 1 << endl;
               gdtt[i].output();
          }
     }

     delete[] gdv;
     delete[] gdtt;

     return 0;
}
