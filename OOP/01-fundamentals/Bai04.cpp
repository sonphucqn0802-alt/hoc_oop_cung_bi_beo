//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/*
Viết chương trình cho phép người dùng nhập vào một dãy gồm n phân số. Tìm
và xuất ra màn hình phân số lớn nhất. Sắp xếp dãy phân số tăng dần/giảm dần
*/

#include <iostream>
using namespace std;
#define MAX 1200

struct PhanSo {
    long long tu;
    long long mau;
};

bool lonHon (PhanSo a, PhanSo b) {
    if (a.tu*b.mau > a.mau*b.tu) {
        return true;
    }
    return false;
}

int main() {
    PhanSo ps[MAX];
    int n;
    cout << "Nhap so phan so: "; cin >> n;
    int maxIndex = 0;
    for (int i = 0; i < n; i++) {
        cout << "Nhap tu so: "; cin >> ps[i].tu;
        cout << "Nhap mau so: "; cin >> ps[i].mau;
        if (ps[i].mau == 0) {
            cout << "Mau so phai khac 0" << endl;
            i--;
            continue;
        }
        if (lonHon(ps[i], ps[maxIndex])) {
            maxIndex = i;
        }
    }

     cout << "Phan so lon nhat: " << ps[maxIndex].tu << "/" << ps[maxIndex].mau << endl;

    return 0;

}


