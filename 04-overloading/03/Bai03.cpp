//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/*Định nghĩa lớp CTime biểu diễn khái niệm thời điểm có các thành phần giờ phút
giây. Định nghĩa các phép toán +, - (cộng, trừ thêm một số nguyên giây, ++, --
(thêm bớt một giây). Phép toán <<, >> để xuất, nhập dữ liệu loại CTime. Áp
dụng lớp CTime để tạo đồng hồ in ở góc trên bên phải màn hình.
*/

#include "cTime.h"

using namespace std;

int main() {
    cTime time;
    cin >> time;
    cout << "Time: " << time << endl;
    time++;
    cout << "Time after ++: " << time << endl;
    return 0;
}
