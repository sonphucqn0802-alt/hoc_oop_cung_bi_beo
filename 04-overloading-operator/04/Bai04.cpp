//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/*Định nghĩa lớp CDate biểu diễn khái niệm ngày, tháng, năm với các phép toán +,
- (cộng, trừ thêm một số ngày), ++, -- (thêm bớt một ngày), - (khoảng cách giữa
hai CDate tính bằng ngày). Phép toán <<, >> để xuất, nhập dữ liệu loại CDate.
Áp dụng lớp CDate để giải bài toán tính lãi suất tiền gửi ngân hàng.*/

#include "cDate.h"

using namespace std;

int main() {
    cDate ngayGui;
    cDate ngayDaoHan;
    double soTienGui;
    double laiSuatNam;

    cout << "Nhap so tien gui: ";
    cin >> soTienGui;
    cout << "Nhap lai suat nam (%): ";
    cin >> laiSuatNam;

    cout << "Nhap ngay gui (dd mm yyyy): ";
    cin >> ngayGui;
    if (!cin) {
        cout << "Ngay gui khong hop le.\n";
        return 1;
    }

    cout << "Nhap ngay dao han (dd mm yyyy): ";
    cin >> ngayDaoHan;
    if (!cin) {
        cout << "Ngay dao han khong hop le.\n";
        return 1;
    }

    long long soNgayGui = ngayDaoHan - ngayGui;
    double tienLai = soTienGui * (laiSuatNam / 100.0) * double(soNgayGui) / 365.0;
    double tongNhanDuoc = soTienGui + tienLai;

    cout << fixed << setprecision(2);
    cout << "Ngay gui: " << ngayGui << endl;
    cout << "Ngay dao han: " << ngayDaoHan << endl;
    cout << "So ngay gui: " << soNgayGui << endl;
    cout << "Tien lai: " << tienLai << endl;
    cout << "Tong nhan duoc: " << tongNhanDuoc << endl;

    return 0;
}
