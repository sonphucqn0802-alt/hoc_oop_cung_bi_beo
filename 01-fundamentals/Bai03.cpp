//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/*Viết chương trình cho phép người dùng nhập vào hai phân số. Tính tổng, hiệu,
tích, thương giữa chúng và xuất kết quả ra màn hình.*/

#include <bits/stdc++.h>
using namespace std;
    //Cách 1
// int main() {
//     long long tu1 = 0, mau1 = 0, tu2 = 0, mau2 = 0;
//     if (!cin >> tu1 >> mau1 >> tu2 >> mau2) {
//         return 0;
//     }
//     if (mau1 == 0 || mau2 == 0) return 0;
//     if (mau1 < 0) {
//         tu1 = -tu1; mau1 = -mau1;
//     }
//     if (mau2 < 0) {
//         tu2 = -tu2; mau2 = -mau2;
//     }
    
//     // Tính tổng
//     long long tu_tong = tu1 * mau2 + tu2 * mau1;
//     long long mau_tong = mau1 * mau2;
//     long long ucln_tong = gcd(llabs(tu_tong), llabs(mau_tong));
//     tu_tong /= ucln_tong;
//     mau_tong /= ucln_tong;
//     cout << tu_tong << "/" << mau_tong << endl;
    
//     // Tính hiệu
//     long long tu_hieu = tu1 * mau2 - tu2 * mau1;
//     long long mau_hieu = mau1 * mau2;
//     long long ucln_hieu = gcd(llabs(tu_hieu), llabs(mau_hieu));
//     tu_hieu /= ucln_hieu;
//     mau_hieu /= ucln_hieu;
//     cout << tu_hieu << "/" << mau_hieu << endl;
    
//     // Tính tích
//     long long tu_tich = tu1 * tu2;
//     long long mau_tich = mau1 * mau2;
//     long long ucln_tich = gcd(llabs(tu_tich), llabs(mau_tich));
//     tu_tich /= ucln_tich;
//     mau_tich /= ucln_tich;
//     cout << tu_tich << "/" << mau_tich << endl;
    
//     // Tính thương
//     long long tu_thuong = tu1 * mau2;
//     long long mau_thuong = mau1 * tu2;
//     long long ucln_thuong = gcd(llabs(tu_thuong), llabs(mau_thuong));
//     tu_thuong /= ucln_thuong;
//     mau_thuong /= ucln_thuong;
//     cout << tu_thuong << "/" << mau_thuong << endl;
    
//     return 0;
// }

    //Cách 2
class PhanSo{
    private:
        int tu;
        int mau;
    public:
        void Nhap();
        void Xuat();
        void Tinh(PhanSo ps2, PhanSo &ps3, PhanSo &ps4, PhanSo &ps5, PhanSo &ps6);
        void RutGon();
};

int main(){
    PhanSo ps1, ps2;
    PhanSo tong,hieu,tich,thuong;
    ps1.Nhap();
    ps2.Nhap();
    ps1.Tinh(ps2, tong, hieu, tich, thuong);
    
    tong.RutGon();
    hieu.RutGon();
    tich.RutGon();
    thuong.RutGon();

    tong.Xuat();
    hieu.Xuat();
    tich.Xuat();
    thuong.Xuat();
    
    return 0;
}

void PhanSo::Nhap(){
    cin >> tu >> mau;
}

void PhanSo::Xuat(){
    cout << tu << "/" << mau;
    cout << endl;
}

void PhanSo::Tinh(PhanSo ps2, PhanSo& tong, PhanSo& hieu, PhanSo& tich, PhanSo& thuong){
    // Tính tổng
    tong.tu = this->tu * ps2.mau + ps2.tu * this->mau;
    tong.mau = this->mau * ps2.mau;
    
    // Tính hiệu
    hieu.tu = this->tu * ps2.mau - ps2.tu * this->mau;
    hieu.mau = this->mau * ps2.mau;
    
    // Tính tích
    tich.tu = this->tu * ps2.tu;
    tich.mau = this->mau * ps2.mau;
    
    
    // Tính thương
    thuong.tu = this->tu * ps2.mau;
    thuong.mau = this->mau * ps2.tu;
}

void PhanSo::RutGon(){
     int ucln = gcd(tu, mau);
     tu /= ucln;
     mau /= ucln;
     if (mau < 0) {
          tu = -tu;
          mau = -mau;
     }
}
