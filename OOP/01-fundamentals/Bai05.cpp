//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27


/*
Viết chương trình cho phép người dùng nhập họ tên, điểm toán, điểm văn của
một học sinh. Tính điểm trung bình và xuất kết quả ra màn hình.
*/

#include <iostream>
#include <string>
using namespace std;

struct HocSinh {
    string hoTen;
    double diemToan;
    double diemVan;
};

double tinhDiemTrungBinh(HocSinh hs) {
    return (hs.diemToan + hs.diemVan) / 2;
}

int main() {
    HocSinh hs;
    
    cout << "Nhap ho ten: "; getline(cin, hs.hoTen);
    cout << "Nhap diem toan: "; cin >> hs.diemToan;
    cout << "Nhap diem van: "; cin >> hs.diemVan;
    
    double dtb = tinhDiemTrungBinh(hs);
    
    cout << "Diem trung binh: " << dtb << endl;
    
    return 0;
}