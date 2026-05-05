/*Công ty du lịch X có nhu cầu quản lý thông tin các chuyến xe. Hiện tại công ty
có 2 loại chuyến xe:
- Chuyến xe nội thành có các thông tin sau: Mã số chuyến, Họ tên tài xế, số
xe, số tuyến, số km đi được, doanh thu.
- Chuyến xe ngoại thành có các thông tin sau: Mã số chuyến, Họ tên tài xế, số
xe, nơi đến, số ngày đi được, doanh thu.
Áp dụng tính kế thừa, cài đặt các lớp cho phép thực hiện các chức năng sau:
- Nhập thông tin chuyến xe nội thành
- Nhập thông tin chuyến xe ngoại thành
- Xuất thông tin chuyến xe nội thành
- Xuất thông tin chuyến xe ngoại thành
Viết chương trình minh họa, cho phép nhập mỗi loại 2 chuyến xe. Xuất tổng
doanh thu cho tất cả các chuyến xe và tổng doanh thu của từng loại chuyến xe.
*/

#include "Bus.h"
using namespace std;

int main(){
    const int n = 2;
    LocalBus localBuses[n];
    LongDistanceBus longDistanceBuses[n];
    double totalLocalRevenue = 0;
    double totalLongDistanceRevenue = 0;

    cout << "NHAP THONG TIN CHUYEN XE NOI THANH" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nChuyen xe noi thanh thu " << i + 1 << endl;
        localBuses[i].input();
        totalLocalRevenue += localBuses[i].getRevenue();
    }

    cout << "\nNHAP THONG TIN CHUYEN XE NGOAI THANH" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nChuyen xe ngoai thanh thu " << i + 1 << endl;
        longDistanceBuses[i].input();
        totalLongDistanceRevenue += longDistanceBuses[i].getRevenue();
    }

    cout << "\nDANH SACH CHUYEN XE NOI THANH" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nChuyen xe noi thanh thu " << i + 1 << endl;
        localBuses[i].output();
    }

    cout << "\nDANH SACH CHUYEN XE NGOAI THANH" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nChuyen xe ngoai thanh thu " << i + 1 << endl;
        longDistanceBuses[i].output();
    }

    cout << "\nTong doanh thu chuyen xe noi thanh: " << totalLocalRevenue << endl;
    cout << "Tong doanh thu chuyen xe ngoai thanh: " << totalLongDistanceRevenue << endl;
    cout << "Tong doanh thu tat ca chuyen xe: "
         << totalLocalRevenue + totalLongDistanceRevenue << endl;

    return 0;
}
