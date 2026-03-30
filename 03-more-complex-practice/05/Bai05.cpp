//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/*Định nghĩa lớp cDaGiac để biểu diễn khái niệm đa giác trong mặt phẳng với các
hàm thành phần tương tự như lớp TamGiac. Viết chương trình minh họa.
*/
#include "cDaGiac.h"

using namespace std;

int main() {
    cDaGiac dg;

    dg.Nhap();

    cout << "\nDa giac vua nhap:" << endl;
    dg.Xuat();

    if (dg.KiemTraHopLe() == false) {
        cout << "Da giac khong hop le." << endl;
        return 0;
    }

    dg.tinhChuVi();
    dg.tinhDienTich();

    dg.TinhTien(1, 1);
    cout << "\nSau khi tinh tien (1, 1):" << endl;
    dg.Xuat();

    dg.PhongTo(2);
    cout << "\nSau khi phong to 2 lan:" << endl;
    dg.Xuat();

    dg.ThuNho(2);
    cout << "\nSau khi thu nho 2 lan:" << endl;
    dg.Xuat();

    return 0;
}
