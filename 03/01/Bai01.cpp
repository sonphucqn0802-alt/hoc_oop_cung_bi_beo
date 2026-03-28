/*Định nghĩa lớp cDSPhanSo (danh sách phân số) để lưu trữ và xử lý các thao tác
trên mảng các phân số. Viết chương trình cho phép người dùng nhập vào danh
sách các phân số
- Tính tổng các phân số
- Tìm phân số lớn nhất
- Tìm phân số nhỏ nhất
- Tìm phân số có tử là số nguyên tố lớn nhất
- Sắp xếp danh sách phân số tăng dần
- Sắp xếp danh sách phân số giảm dần
*/
#include "cDsPhanSo.h"
using namespace std;

int main() {
    cDSPhanSo dsPhanSo;
    dsPhanSo.Nhap();

    if (dsPhanSo.Rong()) {
        cout << "Danh sach rong.\n";
        return 0;
    }

    cout << "Danh sach vua nhap: ";
    dsPhanSo.Xuat();
    cout << '\n';

    cout << "Tong cac phan so: ";
    dsPhanSo.TinhTong().Xuat();
    cout << '\n';

    cout << "Phan so lon nhat: ";
    dsPhanSo.TimLonNhat().Xuat();
    cout << '\n';

    cout << "Phan so nho nhat: ";
    dsPhanSo.TimNhoNhat().Xuat();
    cout << '\n';

    cPhanSo phanSoCoTuNguyenToLonNhat;
    if (dsPhanSo.TimPhanSoCoTuLaSoNguyenToLonNhat(phanSoCoTuNguyenToLonNhat)) {
        cout << "Phan so co tu la so nguyen to lon nhat: ";
        phanSoCoTuNguyenToLonNhat.Xuat();
        cout << '\n';
    } else {
        cout << "Khong co phan so nao co tu la so nguyen to.\n";
    }

    dsPhanSo.SapXepTangDan();
    cout << "Danh sach tang dan: ";
    dsPhanSo.Xuat();
    cout << '\n';

    dsPhanSo.SapXepGiamDan();
    cout << "Danh sach giam dan: ";
    dsPhanSo.Xuat();
    cout << '\n';

    return 0;
}