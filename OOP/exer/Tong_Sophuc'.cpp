#include <iostream>
using namespace std;

class SoPhuc {
private:
    double Phanthuc;
    double Phanao;

public:
    SoPhuc(double t = 0, double a = 0) {
        Phanthuc = t;
        Phanao = a;
    }
    void nhap() {
        cin >> Phanthuc >> Phanao;
    }
    void xuat(){
        if (Phanao >= 0)
            cout << Phanthuc << " + " << Phanao << "i";
        else
            cout << Phanthuc << " - " << -Phanao << "i";
    }
    SoPhuc cong(SoPhuc soPhuc) {
        return SoPhuc(Phanthuc + soPhuc.Phanthuc, Phanao + soPhuc.Phanao);
    }
};

int main() {
    SoPhuc z1, z2, tong;
    cout << "Nhap so phuc thu nhat (phan thuc va phan ao): ";
    z1.nhap();
    cout << "Nhap so phuc thu hai (phan thuc va phan ao): ";
    z2.nhap();
    tong = z1.cong(z2);
    cout << "Tong hai so phuc la: ";
    tong.xuat();

    return 0;
}