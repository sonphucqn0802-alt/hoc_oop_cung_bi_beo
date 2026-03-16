#include <iostream>
using namespace std;

struct SoPhuc {
    double Phanthuc;
    double Phanao;
};

int main() {
    SoPhuc z1, z2, tong;

    // Nhập số phức thứ nhất
    cout << "Nhap so phuc thu nhat (phan thuc va phan ao): ";
    cin >> z1.Phanthuc >> z1.Phanao;

    // Nhập số phức thứ hai
    cout << "Nhap so phuc thu hai (phan thuc va phan ao): ";
    cin >> z2.Phanthuc >> z2.Phanao;

    // Tính tổng
    tong.Phanthuc = z1.Phanthuc + z2.Phanthuc;
    tong.Phanao = z1.Phanao + z2.Phanao;

    // Xuất kết quả
    cout << "Tong hai so phuc la: ";
    
    if (tong.Phanao >= 0)
        cout << tong.Phanthuc << " + " << tong.Phanao << "i";
    else
        cout << tong.Phanthuc << " - " << -tong.Phanao << "i";

    return 0;
}