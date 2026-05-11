//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27.1

/*Gia su Truong DH CNTT TP.HCM dao tao sinh vien theo 2 he la he cao dang
va he dai hoc. Ap dung tinh ke thua, thiet ke cac lop va xay dung chuong trinh:
- Nhap vao danh sach cac sinh vien dai hoc, danh sach sinh vien cao dang
- Xuat danh sach cac sinh vien
- Xuat danh sach cac sinh vien du dieu kien tot nghiep
- Xuat danh sach cac sinh vien khong du dieu kien tot nghiep
- Cho biet sinh vien dai hoc nao co diem trung binh cao nhat*/

#include "SinhVien.h"
using namespace std;

int main() {
     int n, m;
     cout << "Nhap so sinh vien dai hoc: ";
     cin >> n;
     cout << "Nhap so sinh vien cao dang: ";
     cin >> m;

     SinhVienDaiHoc *svdh = new SinhVienDaiHoc[n];
     SinhVienCaoDang *svcd = new SinhVienCaoDang[m];

     for (int i = 0; i < n; i++) {
          cout << "\nSinh vien dai hoc thu " << i + 1 << endl;
          svdh[i].input();
     }

     for (int i = 0; i < m; i++) {
          cout << "\nSinh vien cao dang thu " << i + 1 << endl;
          svcd[i].input();
     }

     cout << "\nDANH SACH SINH VIEN DAI HOC" << endl;
     for (int i = 0; i < n; i++) {
          cout << "\nSinh vien dai hoc thu " << i + 1 << endl;
          svdh[i].output();
     }

     cout << "\nDANH SACH SINH VIEN CAO DANG" << endl;
     for (int i = 0; i < m; i++) {
          cout << "\nSinh vien cao dang thu " << i + 1 << endl;
          svcd[i].output();
     }

     cout << "\nDANH SACH SINH VIEN DU DIEU KIEN TOT NGHIEP" << endl;
     for (int i = 0; i < n; i++) {
          if (svdh[i].duDieuKienTotNghiep()) {
               cout << "\nSinh vien dai hoc thu " << i + 1 << endl;
               svdh[i].output();
          }
     }

     for (int i = 0; i < m; i++) {
          if (svcd[i].duDieuKienTotNghiep()) {
               cout << "\nSinh vien cao dang thu " << i + 1 << endl;
               svcd[i].output();
          }
     }

     cout << "\nDANH SACH SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP" << endl;
     for (int i = 0; i < n; i++) {
          if (!svdh[i].duDieuKienTotNghiep()) {
               cout << "\nSinh vien dai hoc thu " << i + 1 << endl;
               svdh[i].output();
          }
     }

     for (int i = 0; i < m; i++) {
          if (!svcd[i].duDieuKienTotNghiep()) {
               cout << "\nSinh vien cao dang thu " << i + 1 << endl;
               svcd[i].output();
          }
     }

     if (n > 0) {
          int viTriMax = 0;
          for (int i = 1; i < n; i++) {
               if (svdh[i].getDiemTrungBinh() > svdh[viTriMax].getDiemTrungBinh()) {
                    viTriMax = i;
               }
          }

          cout << "\nSinh vien dai hoc co diem trung binh cao nhat" << endl;
          svdh[viTriMax].output();
     } else {
          cout << "\nKhong co sinh vien dai hoc" << endl;
     }

     delete[] svdh;
     delete[] svcd;

     return 0;
}
