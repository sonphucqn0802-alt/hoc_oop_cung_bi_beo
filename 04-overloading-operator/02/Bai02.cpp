//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/* Làm lại bài phân số với các phương thức thiết lập cho phép sử dụng một số
nguyên như một phân số đặc biệt (mẫu số bằng 1). Định nghĩa các phép toán +, -,
*, /, ==, >, < trên phân số. Định nghĩa phép toán << và >> để xuất và nhập dữ
liệu cho phân số.*/


#include "cPhanSoPremium.h"

using namespace std;

int main (){
     cPhanSoPremium ps1, ps2;
     cout << "Nhap phan so 1: ";
     cin >> ps1;
     cout << "Nhap phan so 2: ";
     cin >> ps2;
     cout << "Phan so 1: " << ps1 << endl;
     cout << "Phan so 2: " << ps2 << endl;
     cout << "Tong: " << ps1 + ps2 << endl;
     cout << "Hieu: " << ps1 - ps2 << endl;
     cout << "Tich: " << ps1 * ps2 << endl;
     cout << "Thuong: " << ps1 / ps2 << endl;
     cout << "So sanh: " << (ps1 == ps2) << endl;
     cout << "So sanh: " << (ps1 > ps2) << endl;
     cout << "So sanh: " << (ps1 < ps2) << endl;
     return 0;
}
