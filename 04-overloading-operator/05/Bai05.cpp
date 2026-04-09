//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/* Định nghĩa lớp biểu diễn khái niệm đa thức có bậc bất kỳ với các hàm thành
phần và phép toán cần thiết.*/

#include "cDaThuc.h"
#include <iomanip>

using namespace std;

int main() {
    cDaThuc daThuc1;
    cDaThuc daThuc2;
    double x;

    cout << "Nhap da thuc 1 (bac va cac he so tu x^0 den x^bac): ";
    cin >> daThuc1;
    if (!cin) {
        cout << "Du lieu da thuc 1 khong hop le.\n";
        return 1;
    }

    cout << "Nhap da thuc 2 (bac va cac he so tu x^0 den x^bac): ";
    cin >> daThuc2;
    if (!cin) {
        cout << "Du lieu da thuc 2 khong hop le.\n";
        return 1;
    }

    cout << "Da thuc 1: " << daThuc1 << endl;
    cout << "Da thuc 2: " << daThuc2 << endl;
    cout << "Tong: " << daThuc1 + daThuc2 << endl;
    cout << "Hieu: " << daThuc1 - daThuc2 << endl;
    cout << "Tich: " << daThuc1 * daThuc2 << endl;
    cout << "Hai da thuc bang nhau: " << (daThuc1 == daThuc2) << endl;

    cout << "Nhap gia tri x de tinh da thuc: ";
    cin >> x;
    if (!cin) {
        cout << "Gia tri x khong hop le.\n";
        return 1;
    }

    cout << fixed << setprecision(2);
    cout << "P1(" << x << ") = " << daThuc1.tinhGiaTri(x) << endl;
    cout << "P2(" << x << ") = " << daThuc2.tinhGiaTri(x) << endl;

    return 0;
}
