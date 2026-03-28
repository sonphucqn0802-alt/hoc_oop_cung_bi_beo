//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/*Sở giao thông cần theo dõi việc đăng ký xe (Vehicle) của người dân, cho biết
mỗi xe cần lưu các thông tin như sau: chủ xe, loại xe, trị giá xe (>=0), dung tích
xylanh (>=0). Dựa vào thông tin trị giá xe và dung tích xylanh, sở giao thông
cũng tính mức thuế phải đóng trước bạ khi mua xe như sau:
     - Dưới 100cc, 1% trị giá xe.
     - Từ 100 đến 200cc, 3% trị giá xe.
     - Trên 200cc, 5% trị giá xe.
Hãy thiết kế và cài đặt class Vehicle với các attributes và methods phù hợp (có
kiểm tra ràng buộc dữ liệu). Class phải có các constructor và phải bảo đảm tính
encapsulation.
Viết chương trình minh họa thực hiện các chức năng sau:
     - Tạo 3 đối tượng Vehicle xe1, xe2, xe3.
     - Đối tượng xe1 và xe2 được thiết lập dữ liệu sẵn thông qua constructor
     - Đối tượng xe3 cho phép người dùng nhập dữ liệu từ bán phím.
     - Xuất bảng kê khai thông tin chi tiết và tiền thuế trước bạ của các xe trên*/

#include <bits/stdc++.h>
using namespace std;

class Vehicle {
private:
     string owner;
     string type;
     long double value;
     long double xylanh;
public:
    Vehicle() {
          owner = "";
          type = "";
          value = 0;
          xylanh = 0;
    }
    Vehicle(string owner, string type, long double value, long double xylanh) {
          this->owner = owner;
          this->type = type;
          this->value = value;
          this->xylanh = xylanh;
    }
    ~Vehicle() { }
//````````````````````````````````````````````````````````````````
     void input() {
          cout << "Nhan enter de bat dau.";
          cin.ignore(); 
          cout << "Nhap chu xe: ";
          getline(cin,owner);
          cout << "Nhap loai xe: ";
          getline(cin, type);
          cout << "Nhap tri gia xe: ";
          cin >> value;
          cout << "Nhap dung tich xylanh: ";
          cin >> xylanh;
          cout << endl;
     }
     long double calculateTax() {
          if (xylanh < 100) {
               return value * 0.01;
          } else if (xylanh <= 200) {
               return value * 0.03;
          } else {
               return value * 0.05;
          }
     }

     void display() {
          cout << "Chu xe: " << owner << endl;
          cout << "Loai xe: " << type << endl;
          cout << fixed << setprecision(0);
          cout << "Tri gia xe: " << value << " VND" << endl;
          cout << "Dung tich xylanh: " << xylanh << " cc" << endl;
          cout << "Muc thue phai dong truoc ba: " << calculateTax() << " VND" << endl;
          cout << endl;
     }
};

int main() {
     Vehicle xe1("Nguyen Van A", "SH350i", 100000000, 329),xe2("Tran Van B","AirBlade2026", 60950000, 154),xe3;

     xe3.input();

     xe1.display();  
     xe2.display(); 
     xe3.display();
     return 0;
}