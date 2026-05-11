//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27.1

/*
Thư viện X có nhu cầu quản lý danh sách các loại sách. Thông tin về các loại
sách gồm:
     - Sách giáo khoa: Mã sách, ngày nhập, đơn giá, số lượng, nhà xuất bản, tình
trạng ("mới", "cũ").
          o Nếu tình trạng sách là "mới" thì: thành tiền = số lượng * đơn giá.
          o Nếu tình trạng sách là "cũ" thì: thành tiền = số lượng * đơn giá * 50%.
     - Sách tham khảo: Mã sách, ngày nhập, đơn giá, số lượng, nhà xuất bản, thuế.
     Thành tiền = số lượng * đơn giá + thuế.
Áp dụng tính kế thừa, cài đặt các lớp cho phép thực hiện các chức năng sau:
     - Nhập thông tin Sách giáo khoa, Sách tham khảo
     - Xuất thông tin Sách giáo khoa, Sách tham khảo
     - Tính thành tiền Sách giáo khoa, Sách tham khảo
Viết chương trình minh họa, cho phép nhập mỗi loại 3 cuốn sách, sau đó:
     - Tính tổng thành tiền cho từng loại.
     - Tính trung bình cộng đơn giá của các sách tham khảo
     - Xuất ra các sách giáo khoa của nhà xuất bản K (cho nhập K).
*/

#include "Library.h"
using namespace std;

int main() {
     const int N = 3;
     int tongTienSGK = 0;
     int tongTienSTK = 0;

    SachGiaoKhoa sgk[N];
    SachThamKhao stk[N];

    for (int i = 0; i < N; i++) {
        cout << "Sach giao khoa " << i + 1 << endl;
        sgk[i].input();
    }

    for (int i = 0; i < N; i++) {
        cout << "Sach tham khao " << i + 1 << endl;
        stk[i].input();
    }
    
    for (int i = 0; i < N; i++) {
        cout << "Sach giao khoa " << i + 1 << endl;
        sgk[i].output();
    }
    
    for (int i = 0; i < N; i++) {
        cout << "Sach tham khao " << i + 1 << endl;
        stk[i].output();
    }

    cout << "Tong thanh tien sach giao khoa: " << endl;
    for (int i = 0; i < N; i++) {
        tongTienSGK += sgk[i].getThanhTien();
    }
    cout << tongTienSGK << endl;

    cout << "Tong thanh tien sach tham khao: " << endl;
    for (int i = 0; i < N; i++) {
        tongTienSTK += stk[i].getThanhTien();
    }
    cout << tongTienSTK << endl;

    cout << "Tong tien ca hai loai sach: " << tongTienSGK + tongTienSTK << endl;

    return 0;
}