//Mã số sinh viên: 25521438
//Họ và tên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/*Áp dụng kiến thức OOP đã học (không sử dụng kế thừa), viết chương trình
quản lý danh sách sinh viên trường đại học CNTT, Giả sử Trường ĐH CNTT TP.HCM đào tạo sinh viên theo 2 hệ là hệ cao đẳng và hệ đại học. 

Thông tin cần quản lý của một sinh viên cao đẳng bao gồm: mã số sinh viên, họ tên, địa chỉ, tổng số tín chỉ, điểm trung bình, điểm thi tốt nghiệp. 
Thông tin cần quản lý của một sinh viên đại học bao gồm: mã số sinh viên, họ tên, địa chỉ, tổng số tín chỉ, điểm trung bình, tên luận văn, điểm luận văn.

Chương trình cho phép người dùng thực hiện các chức năng sau:
- Nhập vào danh sách sinh viên (gồm sinh viên cao đẳng và sinh viên đại học)
- Xuất danh sách sinh viên (gồm sinh viên cao đẳng và sinh viên đại học)
- Cho biết có bao nhiêu sinh viên đủ điều kiện tốt nghiệp?
- Cho biết sinh viên đại học nào có điểm trung bình cao nhất?
Cách xét tốt nghiệp của sinh viên mỗi hệ là khác nhau:
- Sinh viên hệ cao đẳng đủ điều kiện tốt nghiệp khi có tổng số tín chỉ từ 110 trở lên, điểm trung bình từ 5 trở lên và điểm thi tốt nghiệp phải đạt từ 5 trở lên.
- Sinh viên hệ đại học đủ điều kiện tốt nghiệp khi có tổng số tín chỉ từ 145 trở lên, điểm trung bình từ 5 trở lên và phải bảo vệ luận văn với điểm số đạt được từ 5 điểm trở lên.
*/

#include "SinhVien.h"

void hienThiMenu() {
    cout << "\n========== CHỨC NĂNG ==========\n";
    cout << "1. Nhap danh sach sinh vien\n";
    cout << "2. Xuat danh sach sinh vien\n";
    cout << "3. So luong sinh vien du dieu kien tot nghiep\n";
    cout << "4. Diem trung binh cao nhat cua sinh vien dai hoc\n";
    cout << "0. Thoat\n";
}

int main() {
    QuanLySinhVien qlSinhVien;
    int luaChon;

    do {
        hienThiMenu();
        luaChon = nhapSoNguyen("Nhap lua chon: ", 0, 4);
        cout << '\n';

        switch (luaChon) {
            case 1:
                qlSinhVien.nhapDanhSach();
                break;

            case 2:
                qlSinhVien.xuatDanhSach();
                break;

            case 3:
                if (qlSinhVien.rong()) {
                    cout << "Danh sach sinh vien dang rong.\n";
                } else {
                    cout << "So sinh vien du dieu kien tot nghiep: "
                         << qlSinhVien.demSinhVienDuTotNghiep() << '\n';
                }
                break;

            case 4: {
                vector<SinhVien> ketQua = qlSinhVien.timSinhVienDaiHocDiemCaoNhat();

                if (ketQua.empty()) {
                    cout << "Khong co sinh vien dai hoc trong danh sach.\n";
                } else {
                    cout << "Sinh vien dai hoc co diem trung binh cao nhat:\n";
                    for (size_t i = 0; i < ketQua.size(); ++i) {
                        cout << "\nSinh vien thu " << i + 1 << ":\n";
                        ketQua[i].xuat();
                    }
                }
                break;
            }

            case 0:
                cout << "Ket thuc chuong trinh.\n";
                break;
        }
    } while (luaChon != 0);

    return 0;
}
