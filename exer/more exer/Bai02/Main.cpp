//Mã số sinh viên: 25521438
//Họ và tên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/*Áp dụng kiến thức OOP đã học (không sử dụng kế thừa), viết chương trình quản lý sách cho thư viện trường học. Thư viện trường học là trung tâm văn hóa, khoa học của nhà trường nhằm mở rộng kiến thức, góp phần nâng cao hiệu quả dạy - học và nghiên cứu khoa học của giáo viên và học sinh. Thư viện trường học cần quản lý danh sách các loại sách gồm 2 loại như sau:
Sách giáo khoa: mã sách, tên sách, nhà xuất bản, số lượng, đơn giá và tình trạng (0: cũ, 1: mới).
Nếu tình trạng sách là mới thì: Thành tiền = số lượng * đơn giá.  
Nếu tình trạng sách là cũ thì: Thành tiền = số lượng * đơn giá * 50%
Sách tham khảo: mã sách, tên sách, nhà xuất bản, số lượng, đơn giá và tiền thuế.
Thành tiền = số lượng * đơn giá + thuế
Chương trình cho phép người dùng thực hiện các chức năng sau:
Nhập vào danh sách các sách giáo khoa và sách tham khảo của thư viện trường.
Xuất danh sách các sách giáo khoa và sách tham khảo của thư viện trường.
Tính thành tiền mà thư viện trường học phải trả cho từng loại sách và hiển thị thông tin chi tiết những sách nào có thành tiền phải trả ít nhất.
Tìm thông tin các sách giáo khoa của nhà xuất bản có tên do người dùng nhập vào.
*/

#include "ThuVien.h"

void hienThiMenu() {
    cout << "\n========== MENU ==========\n";
    cout << "1. Nhap danh sach sach\n";
    cout << "2. Xuat danh sach sach\n";
    cout << "3. Tinh tong thanh tien tung loai va tim sach co thanh tien it nhat\n";
    cout << "4. Tim sach giao khoa theo nha xuat ban\n";
    cout << "0. Thoat\n";
}

int main() {
    ThuVien thuVien;
    int luaChon;

    do {
        hienThiMenu();
        luaChon = nhapSoNguyen("Nhap lua chon: ", 0, 4);

        switch (luaChon) {
            case 1:
                thuVien.nhapDanhSach();
                break;

            case 2:
                thuVien.xuatDanhSach();
                break;

            case 3:
                if (thuVien.rong()) {
                    cout << "Danh sach sach dang rong.\n";
                } else {
                    cout << fixed << setprecision(2);
                    cout << "Tong thanh tien sach giao khoa: "
                         << thuVien.tongThanhTienSachGiaoKhoa() << '\n';
                    cout << "Tong thanh tien sach tham khao: "
                         << thuVien.tongThanhTienSachThamKhao() << '\n';
                    thuVien.xuatThongTinSachCoThanhTienItNhat();
                }
                break;

            case 4: {
                string nhaXuatBan = nhapChuoi("Nhap ten nha xuat ban can tim: ");
                thuVien.timKiemTheoNhaXuatBan(nhaXuatBan);
                break;
            }

            case 0:
                cout << "Ket thuc chuong trinh.\n";
                break;
        }
    } while (luaChon != 0);

    return 0;
}
