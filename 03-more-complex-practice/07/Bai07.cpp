//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/* Cai dat lop Nhan vien van phong (cNhanVienVP) cho phep luu tru cac thong tin:
ma nhan vien, ho ten, ngay sinh, luong va cac thao tac can thiet : constructor, get,
set, nhap, xuat,...
Viet chuong trinh cho phep nguoi dung thuc hien cac chuc nang sau:
- Nhap danh sach n nhan vien van phong
- Xuat danh sach nhan vien van phong duoi dang danh sach
- Cho biet nhan vien van phong nao co luong cao nhat
- Tinh tong luong ma cong ty phai tra cho cac nhan vien van phong
- Cho biet nhan vien nao co tuoi cao nhat
- Sap xep danh sach nhan vien van phong tang dan theo luong
*/

#include "cNhanVienVP.h"

int main() {
    cListNhanVienVP dsNhanVien;

    dsNhanVien.Nhap();

    cout << "\nDanh sach nhan vien van phong vua nhap:\n";
    dsNhanVien.Xuat();

    cout << "\nNhan vien co luong cao nhat:\n";
    dsNhanVien.XuatNhanVienLuongCaoNhat();

    cout << "\nTong luong cong ty phai tra: " << fixed << setprecision(2)
         << dsNhanVien.TinhTongLuong() << '\n';

    cout << "\nNhan vien lon tuoi nhat:\n";
    dsNhanVien.XuatNhanVienLonTuoiNhat();

    dsNhanVien.SapXepTangDanTheoLuong();
    cout << "\nDanh sach sau khi sap xep tang dan theo luong:\n";
    dsNhanVien.Xuat();

    return 0;
}
