//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/*Viết chương trình cho phép người dùng nhập vào một ngày (ngày tháng năm).
Xuất ra thứ trong tuần của ngày đó.*/

#include <iostream>
using namespace std;

struct Ngay {
     int ngay;
     int thang;
     int nam;
};

// do không có mốc cố định nên em sẽ cho người dùng chọn 1 ngày làm thứ 2 đầu tiên.

bool laNamnhuan(int nam) {
     return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int main() {
     Ngay ngaydautien;
     cout << "Nhap ngay dau tien (ngay thang nam): ";
     cin >> ngaydautien.ngay >> ngaydautien.thang >> ngaydautien.nam;

     Ngay ngay;
     cout << "Nhap ngay can kiem tra (ngay thang nam): ";
     cin >> ngay.ngay >> ngay.thang >> ngay.nam;
     
     return 0;
}
