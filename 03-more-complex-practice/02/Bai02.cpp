//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/*Định nghĩa lớp Mảng một chiều (cArray) để lưu trữ danh sách
các số nguyên và hỗ trợ xử lý các thao tác cơ bản trên mảng 
một chiều:
- Tạo mảng ngẫu nhiên gồm n số nguyên
- Xuất các phần tử mảng
- Đếm số lần xuất hiện của giá trị x trong mảng
- Kiểm tra các phần tử trong mảng có tăng dần hay không
- Tìm phần lẻ nhỏ nhất trong mảng
- Tìm số nguyên tố lớn nhất trong mảng
- Sắp xếp các phần tử trong mảng tăng dần/giảm dần theo các 
thuật toán đã học trong môn Cấu trúc dữ liệu và giải thuật
Viết chương trình minh họa các chức năng của lớp cAray đã 
định nghĩa.*/

#include "cArray.h"

int main() {
    cArray arr;
    arr.Nhap();
    arr.Xuat();
    cout << "So lan xuat hien cua 5: " << arr.DemSoLanXuatHien(5) << endl;
    cout << "Mang co tang dan: " << arr.KiemTraTangDan() << endl;
    cout << "Phan tu nho nhat: " << arr.TimPhanTuNhoNhat() << endl;
    cout << "So nguyen to lon nhat: " << arr.TimSoNguyenToLonNhat() << endl;
    arr.SapXepTangDan();
    arr.Xuat();
    arr.SapXepGiamDan();
    arr.Xuat();
    return 0;
}
