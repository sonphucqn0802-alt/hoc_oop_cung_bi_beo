//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27.1

/*Cong ty Bat dong san VAKALAND co nhu cau quan ly danh sach cac giao dich
bat dong san, hien tai cong ty co 3 loai giao dich:
- Giao dich Dat: Ma giao dich, ngay giao dich, don gia, loai dat (A, B, C), dien tich.
- Giao dich Nha pho: Ma giao dich, ngay giao dich, don gia, loai nha, dia chi, dien tich.
- Giao dich Can ho chung cu: Ma giao dich, ngay giao dich, don gia, ma can, vi tri tang, dien tich.
Ap dung tinh ke thua, thiet ke cac lop va xay dung chuong trinh cho phep thuc hien
cac yeu cau sau:
- Nhap danh sach cac giao dich Dat
- Nhap danh sach cac giao dich Nha pho
- Nhap danh sach cac giao dich Can ho chung cu
- Tinh tong so luong cho tung loai.
- Tinh trung binh thanh tien cua giao dich Can ho chung cu
- Cho biet Giao dich Nha pho co tri gia cao nhat
- Xuat ra danh sach cac giao dich cua thang 12 nam 2024.*/

#include "Giaodich.h"
using namespace std;

int main() {
     int n, m, k;
     cout << "Nhap so giao dich dat: ";
     cin >> n;
     cout << "Nhap so giao dich nha pho: ";
     cin >> m;
     cout << "Nhap so giao dich can ho chung cu: ";
     cin >> k;

     GiaoDichDat *gdd = new GiaoDichDat[n];
     GiaoDichNhaPho *gdnp = new GiaoDichNhaPho[m];
     GiaoDichCanHo *gdch = new GiaoDichCanHo[k];

     for (int i = 0; i < n; i++) {
          cout << "\nGiao dich dat thu " << i + 1 << endl;
          gdd[i].input();
     }

     for (int i = 0; i < m; i++) {
          cout << "\nGiao dich nha pho thu " << i + 1 << endl;
          gdnp[i].input();
     }

     for (int i = 0; i < k; i++) {
          cout << "\nGiao dich can ho chung cu thu " << i + 1 << endl;
          gdch[i].input();
     }

     cout << "\nTong so luong giao dich dat: " << n << endl;
     cout << "Tong so luong giao dich nha pho: " << m << endl;
     cout << "Tong so luong giao dich can ho chung cu: " << k << endl;

     if (k > 0) {
          double tongThanhTienCanHo = 0;
          for (int i = 0; i < k; i++) {
               tongThanhTienCanHo += gdch[i].getThanhTien();
          }

          cout << "\nTrung binh thanh tien giao dich can ho chung cu: "
               << tongThanhTienCanHo / k << endl;
     } else {
          cout << "\nKhong co giao dich can ho chung cu de tinh trung binh" << endl;
     }

     if (m > 0) {
          int viTriMax = 0;
          for (int i = 1; i < m; i++) {
               if (gdnp[i].getThanhTien() > gdnp[viTriMax].getThanhTien()) {
                    viTriMax = i;
               }
          }

          cout << "\nGiao dich nha pho co tri gia cao nhat" << endl;
          gdnp[viTriMax].output();
     } else {
          cout << "\nKhong co giao dich nha pho" << endl;
     }

     cout << "\nDanh sach cac giao dich cua thang 12 nam 2024" << endl;
     for (int i = 0; i < n; i++) {
          if (gdd[i].laThang12Nam2024()) {
               cout << "\nGiao dich dat thu " << i + 1 << endl;
               gdd[i].output();
          }
     }

     for (int i = 0; i < m; i++) {
          if (gdnp[i].laThang12Nam2024()) {
               cout << "\nGiao dich nha pho thu " << i + 1 << endl;
               gdnp[i].output();
          }
     }

     for (int i = 0; i < k; i++) {
          if (gdch[i].laThang12Nam2024()) {
               cout << "\nGiao dich can ho chung cu thu " << i + 1 << endl;
               gdch[i].output();
          }
     }

     delete[] gdd;
     delete[] gdnp;
     delete[] gdch;

     return 0;
}
