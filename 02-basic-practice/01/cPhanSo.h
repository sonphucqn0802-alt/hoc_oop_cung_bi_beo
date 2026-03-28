#include <bits/stdc++.h>
using namespace std;

class cPhanSo {
     int iTuSo;
     int iMauSo;

     public:
          cPhanSo();
          cPhanSo(int);
          cPhanSo(int, int);

          void Nhap();
          void Xuat();

          cPhanSo Cong(cPhanSo);
          cPhanSo Tru(cPhanSo);
          cPhanSo Nhan(cPhanSo);
          cPhanSo Chia(cPhanSo);
          cPhanSo Rutgon();
          
          ~cPhanSo();
};




cPhanSo :: cPhanSo() {
     iTuSo = 0;
     iMauSo = 1;
}

cPhanSo :: cPhanSo(int tu) {
     iTuSo = tu;
     iMauSo = 1;
}

cPhanSo :: cPhanSo(int tu, int mau) {
     iTuSo = tu;
     iMauSo = mau;
}

cPhanSo cPhanSo::Rutgon(){
     int ucln = __gcd(iTuSo, iMauSo);
     iTuSo /= ucln;
     iMauSo /= ucln;
     return *this;
}

void cPhanSo::Nhap(){
     cout << "Nhap tu so: ";
     cin >> iTuSo;
     cout << "Nhap mau so: ";
     cin >> iMauSo;
}


void cPhanSo::Xuat(){
     cout << iTuSo << "/" << iMauSo;
}

cPhanSo cPhanSo::Cong(cPhanSo ps){
     cPhanSo kq;
     kq.iTuSo = this->iTuSo * ps.iMauSo + ps.iTuSo * this->iMauSo;
     kq.iMauSo = this->iMauSo * ps.iMauSo;
     return kq;
}

cPhanSo cPhanSo::Tru(cPhanSo ps){
     cPhanSo kq;
     kq.iTuSo = this->iTuSo * ps.iMauSo - ps.iTuSo * this->iMauSo;
     kq.iMauSo = this->iMauSo * ps.iMauSo;
     return kq;
}

cPhanSo cPhanSo::Nhan(cPhanSo ps){
     cPhanSo kq;
     kq.iTuSo = this->iTuSo * ps.iTuSo;
     kq.iMauSo = this->iMauSo * ps.iMauSo;
     return kq;
}

cPhanSo cPhanSo::Chia(cPhanSo ps){
     cPhanSo kq;
     kq.iTuSo = this->iTuSo * ps.iMauSo;
     kq.iMauSo = this->iMauSo * ps.iTuSo;
     return kq;
}

cPhanSo::~cPhanSo() {
}