//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/*
Định nghĩa lớp cTamGiac để biểu diễn khái niệm tam giác 
trong mặt phẳng
(gồm 3 đỉnh A, B, C) với các phương thức thiết lập, hủy bỏ 
(nếu có). Các hàm
thành phần: thiết lập, nhập, xuất, kiểm tra loại tam giác 
(thường, vuông, cân,
đều), tính chu vi, tính diện tích, tịnh tiến, phóng to, 
thu nhỏ, vẽ tam giác (nếu
được). Viết chương trình minh họa các chức năng của lớp 
cTamGiac.
Lưu ý: Để vẽ hình sinh viên cần tìm hiểu thư viện đồ họa 
(graphic), yêu cầu
này tùy chọn không bắt buộc.
*/

#include "cTamGiac.h"

int main() {
    cTamGiac tg;
    tg.Nhap();
    tg.Xuat();
    tg.tinhChuVi();
    tg.tinhDienTich();
    return 0;
}
