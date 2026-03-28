//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27



/*Viết chương trình cho phép người dùng nhập vào một phân số, rút gọn phân số
và xuất kết quả ra màn hình.*/

#include <bits/stdc++.h>
using namespace std;
//Cách 1:
// int main() {
//      long long tu = 0, mau = 0;
//      if (!cin >> tu >> mau) {
//           return 0;
//      }
//      if (mau == 0) return 0;
//      if (mau < 0) {
//           tu = -tu; mau = -mau;
//      }

//      long long ucln = gcd(llabs(tu), llabs(mau));
//      tu /= ucln;
//      mau /= ucln;

//      cout << tu << "/" << mau << endl;

//     return 0;
// }

//Cách 2:
class PhanSo {
     private:
          int TuSo;
          int MauSo;
     public:
          void Nhap();
          void Xuat();
          void RutGon();
};

int main(){
     PhanSo ps;
     ps.Nhap();
     ps.RutGon();
     ps.Xuat();
     return 0;
}

void PhanSo::Nhap(){
     cin >> TuSo >> MauSo;
}

void PhanSo::Xuat(){
     cout << TuSo << "/" << MauSo;
}

void PhanSo::RutGon(){
     int ucln = gcd(TuSo, MauSo);
     TuSo /= ucln;
     MauSo /= ucln;
}

