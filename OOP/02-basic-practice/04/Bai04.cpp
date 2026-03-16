//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27


/*Cài đặt lớp biểu diễn khái niệm thời gian với các thành phần dữ liệu giờ, phút,
giây và các thao tác thích hợp (nhập, xuất, thiết lập, thay đổi giờ/phút/giây, lấy
giờ/phút/giây, tăng/giảm giờ/phút/giây,…). Viết chương trình minh họa các chức
năng đã cài đặt của lớp Thời gian.*/
#include "cThoiGian.h"
using namespace std;

int main() {

    cThoiGian tg,tgbonus;
    cThoiGian t;

    tg.SetTime(10,20,30);

    cout << "Thoi gian ban dau: ";
    tg.GetTime();

    cout << "Nhap thoi gian: ";
    tgbonus.InputTime();
    tgbonus.GetTime();

    cout << "Tang thoi gian:" << endl;
    tg.UpTime();
    tg.GetTime();

    cout << "Giam thoi gian:" << endl;
    tg.DownTime();
    tg.GetTime();

    cout << "Thay doi thoi gian:" << endl;
    t.SetTime(5,10,15);
    tg.ChangeTime(t);
    tg.GetTime();

    return 0;
}

cThoiGian :: cThoiGian() {
     iGio=iPhut=iGiay=0;
}

cThoiGian :: cThoiGian (int h, int m , int s) {
     iGio=h;
     iPhut=m;
     iGiay=s;
}

void cThoiGian :: SetTime(int h, int m, int s) {
     iGio = h;
     iPhut = m;
     iGiay = s;
}

void cThoiGian::InputTime() {
     cout << "Nhap gio: ";
     cin >> this->iGio;

     cout << "Nhap phut: ";
     cin >> this->iPhut;

     cout << "Nhap giay: ";
     cin >> this->iGiay;
}

void cThoiGian :: GetTime() {
     cout << iGio << ":" << iPhut << ":" << iGiay << endl;
}

void cThoiGian :: ChangeTime(cThoiGian p) {
    this->iGio = p.iGio;
    this->iPhut = p.iPhut;
    this->iGiay = p.iGiay;
}

void cThoiGian::UpTime() {
     int h,m,s;
     cout << "Nhap gio muon tang: ";
     cin >> h;
     cout << "Nhap phut muon tang: ";
     cin >> m;
     cout << "Nhap giay muon tang: ";
     cin >> s;

     iGio += h;
     iPhut += m;
     iGiay += s;

     if(iGiay >= 60){
          iPhut += iGiay/60;
          iGiay %= 60;
     }

     if(iPhut >= 60){
          iGio += iPhut/60;
          iPhut %= 60;
     }

     if(iGio >= 24){
          iGio %= 24;
     }
}
void cThoiGian::DownTime() {
     int h,m,s;
     cout << "Nhap gio muon giam: ";
     cin >> h;
     cout << "Nhap phut muon giam: ";
     cin >> m;
     cout << "Nhap giay muon giam: ";
     cin >> s;

     iGio -= h;
     iPhut -= m;
     iGiay -= s;

     if(iGiay < 0){
          iGiay += 60;
          iPhut--;
     }

     if(iPhut < 0){
          iPhut += 60;
          iGio--;
     }

     if(iGio < 0){
          iGio += 24;
     }
}


cThoiGian :: ~cThoiGian() {
    
}

