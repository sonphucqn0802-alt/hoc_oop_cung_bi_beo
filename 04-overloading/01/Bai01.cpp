//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/*Làm lại bài số phức với một phương thức thiết lập duy nhất cho phép quan điểm
một số thực như một số phức đặc biệt (phần ảo bằng 0). Định nghĩa các phép
toán +, -, *, /, ==, != trên số phức. Định nghĩa phép toán << và >> để xuất và
nhập dữ liệu cho số phức.*/

#include "cSoPhuc.cpp"

int main () {
    cSoPhuc sp1(1, 2);
    cSoPhuc sp2;
    cin >> sp2;
    cSoPhuc sp3 = sp1 + sp2;
    cout << sp3 << endl;
    sp2 = sp1 - sp2;
    cout << sp2 << endl;
    return 0;
}
