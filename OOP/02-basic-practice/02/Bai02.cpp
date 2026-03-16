//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27


/*
Cài đặt lớp biểu diễn khái niệm điểm trong mặt phẳng với hai thành phần dữ liệu
hoành độ và tung độ với các phương thức thiết lập, các hàm thành phần cho
phép thay đổi nội dung của điểm, lấy hoành độ, tung độ, thay đổi hoành độ, tung
độ, tịnh tiến, nhập, xuất một điểm. Viết chương trình minh họa các chức năng đã
cài đặt được. Tìm hiểu các hàm vẽ điểm trong chế độ đồ họa (yêu cầu tìm hiểu
thêm không bắt buộc)
*/
#include "cDiem.h"
using namespace std;

int main(){
     cDiem a, b, c(1,2);

     cout << "Nhap diem a:\n";
     a.Nhap();

     cout << "Diem a: ";
     a.Xuat();
     cout << endl;

     cout << "Toa do diem b ban dau:\n";
     cout << "Hoanh do: " << b.GetHoanhDo() << endl;
     cout << "Tung do: " << b.GetTungDo() << endl;

     cout << "Sau khi thay doi diem b:\n";
     b.SetHoanhDo(5).SetTungDo(10);
     b.Xuat();
     cout << endl;

     cout << "Diem c ban dau: ";
     c.Xuat();
     cout << endl;

     cout << "Sau khi tinh tien (1,1): ";
     c.TinhTien(1,1);
     c.Xuat();
     cout << endl;

     return 0;
}


cDiem :: cDiem() {
     dHoanhdo = 0;
     dTungdo = 0;
}

cDiem :: cDiem(double hoanhdo, double tungdo) {
     dHoanhdo = hoanhdo;
     dTungdo = tungdo;
}

void cDiem :: Nhap(){
     cout << "Nhap hoanh do: ";
     cin >> dHoanhdo;
     cout << "Nhap tung do: ";
     cin >> dTungdo;
}


void cDiem :: Xuat(){
     cout << "(" << dHoanhdo << ", " << dTungdo << ")";
}


double cDiem::GetHoanhDo(){
     return dHoanhdo;
}

double cDiem::GetTungDo(){
     return dTungdo;
}

cDiem cDiem :: SetHoanhDo(double hoanhdo){
     dHoanhdo = hoanhdo;
     return *this;
}

cDiem cDiem :: SetTungDo(double tungdo){
     dTungdo = tungdo;
     return *this;
}

cDiem cDiem :: SetDiem(double hoanhdo, double tungdo) {
     dHoanhdo = hoanhdo;
     dTungdo = tungdo;
     return *this;
}

void cDiem::TinhTien(double hoanhdo, double tungdo){
     dHoanhdo += hoanhdo;
     dTungdo += tungdo;
}

cDiem::~cDiem() {   
}
