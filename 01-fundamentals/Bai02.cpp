//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/*Viết chương trình cho phép người dùng nhập vào hai phân số, tìm phân số lớn
nhất và xuất kết quả ra màn hình.*/

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

//     double ps1 = (double)tu1 / mau1;
//     double ps2 = (double)tu2 / mau2;
    
//     if (ps1 > ps2) {
//         cout << tu1 << "/" << mau1 << endl;
//     } else {
//         cout << tu2 << "/" << mau2 << endl;
//     }
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
        bool Sosanh(PhanSo ps);
};

int main(){
    PhanSo ps1, ps2;
    ps1.Nhap();
    ps2.Nhap();
    if (ps1.Sosanh(ps2)) {
        ps1.Xuat();
    } else {
        ps2.Xuat();
    }
    return 0;
}

void PhanSo::Nhap(){
    cin >> tu >> mau;
}

void PhanSo::Xuat(){
    cout << tu << "/" << mau;
}

bool PhanSo::Sosanh(PhanSo ps){
    return (double)tu / mau > (double)ps.tu / ps.mau;
}