//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/*Xét đa thức theo biến x (đa thức một biến) bậc n có dạng như sau:
P(X) = a1x
n + a2x
n-1 + a3x
n-2 + … + aj
Trong đó: n là bậc của đa thức. a1, a2, a3,…, aj là các hệ số tương ứng với từng
bậc của đa thức.
Định nghĩa lớp cDaThuc biểu diễn khái niệm đa thức với các thao tác sau:
- Khởi tạo một đa thức có bậc bằng 0 hoặc bậc.
- Tính giá trị của đa thức khi biết giá trị của x
- Nhập đa thức
- Xuất đa thức
- Cộng hai đa thức
- Trừ hai đa thức
Viết chương trình cho phép người dùng nhập vào hai đa thức, xuất các đa thức
ra màn hình, tính tổng , hiệu hai đa thức và xuất kết quả ra màn hình. */


#include "DaThuc.h"

int main() {
    DaThuc dt1, dt2;
    dt1.Nhap();
    dt2.Nhap();
    dt1.Xuat();
    dt2.Xuat();
    DaThuc tong = dt1.Cong(dt2);
    DaThuc hieu = dt1.Tru(dt2);
    tong.Xuat();
    hieu.Xuat();
    // Bổ sung hàm tính giá trị đa thức dù đề không yêu cầu vì em thấy phải tạo phương thức rồi.

    cout << "Gia tri cua da thuc 1 tai x = 2: " << dt1.TinhGiaTri(2) << endl;
    cout << "Gia tri cua da thuc 2 tai x = 4: " << dt2.TinhGiaTri(4) << endl;
    return 0;
}