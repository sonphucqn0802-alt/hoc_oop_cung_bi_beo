//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/*Định nghĩa lớp CVector biểu diễn khái niệm vector trong không gian có số chiều
bất kỳ với các hàm thành phần và các phép toán cần thiết.
Định nghĩa lớp CMatrix biểu diễn khái niệm ma trận có kích thước bất kỳ với các
hàm thành phần và các phép toán cần thiết.
Viết hàm tính tích của một ma trận và một vector. Tích của hai ma trận.*/

#include "cMatrix.h"
using namespace std;

int main() {
    cMatrix maTranA;
    cMatrix maTranB;
    cVector vectorX;

    cout << "Nhap ma tran A (so dong, so cot, cac phan tu): ";
    cin >> maTranA;
    if (!cin) {
        cout << "Du lieu ma tran A khong hop le.\n";
        return 1;
    }

    cout << "Nhap ma tran B (so dong, so cot, cac phan tu): ";
    cin >> maTranB;
    if (!cin) {
        cout << "Du lieu ma tran B khong hop le.\n";
        return 1;
    }

    cout << "Nhap vector x (so chieu va cac thanh phan): ";
    cin >> vectorX;
    if (!cin) {
        cout << "Du lieu vector khong hop le.\n";
        return 1;
    }

    cout << fixed << setprecision(2);
    cout << "Ma tran A:\n" << maTranA << endl;
    cout << "Ma tran B:\n" << maTranB << endl;
    cout << "Vector x: " << vectorX << endl;

    try {
        cout << "A + B:\n" << maTranA + maTranB << endl;
    } catch (const exception& loi) {
        cout << "Khong the tinh A + B: " << loi.what() << endl;
    }

    try {
        cout << "A - B:\n" << maTranA - maTranB << endl;
    } catch (const exception& loi) {
        cout << "Khong the tinh A - B: " << loi.what() << endl;
    }

    try {
        cout << "A * x: " << maTranA * vectorX << endl;
    } catch (const exception& loi) {
        cout << "Khong the tinh A * x: " << loi.what() << endl;
    }

    try {
        cout << "A * B:\n" << maTranA * maTranB << endl;
    } catch (const exception& loi) {
        cout << "Khong the tinh A * B: " << loi.what() << endl;
    }

    return 0;
}
