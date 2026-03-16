//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27


/* Cài đặt lớp cPhanSo để biểu diễn khái niệm phân số với hai thành phần dữ liệu
tử số, mẫu số và các hàm thành phần cộng, trừ, nhân, chia hai phân số, các
hàm thành phần xuất, nhập, định giá trị cho phân số. Viết chương trình cho
phép nhập vào hai phân số, in ra kết quả các phép toán cộng, trừ, nhân, chia hai
phân số kể trên.
*/
#include <bits/stdc++.h>
#include "cPhanSo.h"

using namespace std;


int main(){
     cPhanSo ps1, ps2;
     ps1.Nhap();
     ps2.Nhap();
     ps1.Cong(ps2).Rutgon().Xuat();
     cout << endl;
     ps1.Tru(ps2).Rutgon().Xuat();
     cout << endl;
     ps1.Nhan(ps2).Rutgon().Xuat();
     cout << endl;
     ps1.Chia(ps2).Rutgon().Xuat();
     cout << endl;
     return 0;
}