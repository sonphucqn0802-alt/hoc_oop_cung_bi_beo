//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27.1

/*Gia su Cong ty co hai loai nhan vien: Nhan vien van phong va Nhan vien san xuat.
Viet chuong trinh quan ly va tinh luong cho tung nhan vien cua cong ty:
Moi nhan vien can quan ly cac thong tin sau: Ho ten, ngay sinh, luong.
Cong ty can tinh luong cho nhan vien nhu sau:
- Doi voi nhan vien san xuat:
Luong = luong can ban + so san pham * 5.000
- Doi voi nhan vien van phong:
Luong = so ngay lam viec * 100.000
Ap dung tinh ke thua, thiet ke cac lop va xay dung chuong trinh cho phep thuc hien:
- Nhap danh sach nhan vien san xuat, danh sach nhan vien van phong
- Tinh luong cho tung nhan vien
- Xuat thong tin danh sach cac nhan vien
- Tinh tong luong ma cong ty phai tra cho cac nhan vien*/

#include "Luong.h"
#include <iomanip>
using namespace std;

int main() {
     cout << fixed << setprecision(0);

     int n, m;
     double tongLuongSanXuat = 0;
     double tongLuongVanPhong = 0;

     cout << "Nhap so nhan vien san xuat: ";
     cin >> n;
     cout << "Nhap so nhan vien van phong: ";
     cin >> m;

     NhanVienSanXuat *nvsx = new NhanVienSanXuat[n];
     NhanVienVanPhong *nvvp = new NhanVienVanPhong[m];

     for (int i = 0; i < n; i++) {
          cout << "\nNhan vien san xuat thu " << i + 1 << endl;
          nvsx[i].input();
          tongLuongSanXuat += nvsx[i].getLuong();
     }

     for (int i = 0; i < m; i++) {
          cout << "\nNhan vien van phong thu " << i + 1 << endl;
          nvvp[i].input();
          tongLuongVanPhong += nvvp[i].getLuong();
     }

     cout << "\nDANH SACH NHAN VIEN SAN XUAT" << endl;
     for (int i = 0; i < n; i++) {
          cout << "\nNhan vien san xuat thu " << i + 1 << endl;
          nvsx[i].output();
     }

     cout << "\nDANH SACH NHAN VIEN VAN PHONG" << endl;
     for (int i = 0; i < m; i++) {
          cout << "\nNhan vien van phong thu " << i + 1 << endl;
          nvvp[i].output();
     }

     cout << "\nTong luong nhan vien san xuat: " << tongLuongSanXuat << endl;
     cout << "Tong luong nhan vien van phong: " << tongLuongVanPhong << endl;
     cout << "Tong luong cong ty phai tra: "
          << tongLuongSanXuat + tongLuongVanPhong << endl;

     delete[] nvsx;
     delete[] nvvp;

     return 0;
}
