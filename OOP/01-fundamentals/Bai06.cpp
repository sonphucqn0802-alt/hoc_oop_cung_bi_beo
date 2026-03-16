//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/*
Viết chương trình cho phép người dùng nhập vào danh sách học sinh (thông tin
mỗi học sinh giống bài 5). Tìm và xuất thông tin học sinh có điểm trung bình cao
nhất, thấp nhất ra màn hình.
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
    int n;
    cout << "Nhap so luong hoc sinh: "; cin >> n;
    HocSinh* ds = new HocSinh[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin hoc sinh " << i + 1 << ":\n";
        cout << "Ho ten: "; cin >> ds[i].hoTen;
        cout << "Diem toan: "; cin >> ds[i].diemToan;
        cout << "Diem van: "; cin >> ds[i].diemVan;
    }
    double maxDTB = tinhDiemTrungBinh(ds[0]);
    double minDTB = tinhDiemTrungBinh(ds[0]);
    int maxIndex = 0;
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        double dtb = tinhDiemTrungBinh(ds[i]);
        if (dtb > maxDTB) {
            maxDTB = dtb;
            maxIndex = i;
        }
        if (dtb < minDTB) {
            minDTB = dtb;
            minIndex = i;
        }
    }
    cout << "Hoc sinh co diem trung binh cao nhat:\n";
    cout << "Ho ten: " << ds[maxIndex].hoTen << endl;
    cout << "Diem trung binh: " << maxDTB << endl;
    cout << "Hoc sinh co diem trung binh thap nhat:\n";
    cout << "Ho ten: " << ds[minIndex].hoTen << endl;
    cout << "Diem trung binh: " << minDTB << endl;
    delete[] ds;
    return 0;
}