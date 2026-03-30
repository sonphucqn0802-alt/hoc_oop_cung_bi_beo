//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/* Cai dat lop Nhan vien san xuat (cNhanVienSX) cho phep luu tru cac thong tin:
ma nhan vien, ho ten, ngay sinh, so san pham da gia cong, don gia mot san pham
va cac thao tac can thiet : constructor, get, set, nhap, xuat, tinh luong cho nhan
vien = so san pham da gia cong * don gia mot san pham.
Viet chuong trinh cho phep nguoi dung thuc hien cac chuc nang sau:
- Nhap danh sach n nhan vien san xuat
- Xuat danh sach nhan vien san xuat duoi dang danh sach
- Cho biet nhan vien san xuat nao co luong thap nhat
- Tinh tong luong ma cong ty phai tra cho cac nhan vien san xuat
- Cho biet nhan vien san xuat nao co tuoi cao nhat
- Sap xep danh sach nhan vien san xuat tang dan theo luong
*/

#include "cNhanVienSX.h"

int main() {
    cListNhanVienSX dsNhanVien;

    dsNhanVien.Nhap();

    cout << "\nDanh sach nhan vien san xuat vua nhap:\n";
    dsNhanVien.Xuat();

    cout << "\nNhan vien co luong thap nhat:\n";
    dsNhanVien.XuatNhanVienLuongThapNhat();

    cout << "\nTong luong cong ty phai tra: " << fixed << setprecision(2)
         << dsNhanVien.TinhTongLuong() << '\n';

    cout << "\nNhan vien lon tuoi nhat:\n";
    dsNhanVien.XuatNhanVienLonTuoiNhat();

    dsNhanVien.SapXepTangDanTheoLuong();
    cout << "\nDanh sach sau khi sap xep tang dan theo luong:\n";
    dsNhanVien.Xuat();

    return 0;
}
