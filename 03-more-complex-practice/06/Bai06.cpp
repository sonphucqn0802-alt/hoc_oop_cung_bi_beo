//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27


/* Dinh nghia lop cCandidate (Thi sinh) gom cac thuoc tinh: ma, ten,
ngay thang nam sinh, diem thi Toan, Van, Anh va cac phuong thuc can thiet.
Dinh nghia lop cListCandidate (danh sach thi sinh) de luu tru va xu ly cac thao tac:
- Nhap vao n thi sinh (n do nguoi dung nhap)
- Xuat thong tin cac thi sinh co tong diem lon hon 15
- Cho biet thi sinh nao co tong diem cao nhat
- Sap xep danh sach thi sinh giam dan theo tong diem
Viet chuong trinh minh hoa. */

#include "cListCandidate.h"

int main() {
    cListCandidate dsThiSinh;

    dsThiSinh.Nhap();

    cout << "\nDanh sach thi sinh vua nhap:\n";
    dsThiSinh.Xuat();

    cout << "\nCac thi sinh co tong diem lon hon 15:\n";
    dsThiSinh.XuatThiSinhTongLonHon15();

    cout << "\nThi sinh co tong diem cao nhat:\n";
    dsThiSinh.XuatThiSinhTongCaoNhat();

    dsThiSinh.SapXepGiamDanTheoTongDiem();
    cout << "\nDanh sach sau khi sap xep giam dan theo tong diem:\n";
    dsThiSinh.Xuat();

    return 0;
}
