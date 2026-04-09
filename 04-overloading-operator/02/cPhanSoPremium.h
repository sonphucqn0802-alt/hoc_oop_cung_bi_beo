#pragma once

#include <iostream>
using namespace std;

class cPhanSoPremium {
private:
    int tu;
    int mau;
public:
    //các hàm khởi tạo
    cPhanSoPremium(){
        tu=0; mau =1;
    }
    cPhanSoPremium(int tu, int mau) {
        this->tu = tu;
        this->mau = mau;
    }
    cPhanSoPremium(int tu) {
        this->tu = tu;
        this->mau = 1;
    }
    ~cPhanSoPremium(){
     cout << "Huy phan so" << endl;
    }

    //cụm set và get
    void getTu() {
        cout << tu;
    }

    void getMau() {
        cout << mau;
    }

    void setMau(int mau) {
        this->mau = mau;
    }

    void setTu(int tu) {
        this->tu = tu;
    }

    void RutGon(){
     if (mau < 0) {
        mau = -mau;
        tu = -tu;
     }
     int ucln = __gcd(tu, mau);
     tu /= ucln;
     mau /= ucln;  
    }

    // các hàm operator
    cPhanSoPremium operator+(cPhanSoPremium ps){
     cPhanSoPremium kq;
     kq.tu = tu * ps.mau + mau * ps.tu;
     kq.mau = mau * ps.mau;
     kq.RutGon();
     return kq;
    }

    cPhanSoPremium operator-(cPhanSoPremium ps){
     cPhanSoPremium kq;
     kq.tu = tu * ps.mau - mau * ps.tu;
     kq.mau = mau * ps.mau;
     kq.RutGon();
     return kq;
    }
    
    cPhanSoPremium operator*(cPhanSoPremium ps){
     cPhanSoPremium kq;
     kq.tu = tu * ps.tu;
     kq.mau = mau * ps.mau;
     kq.RutGon();
     return kq;
    }
    cPhanSoPremium operator/(cPhanSoPremium ps){
     cPhanSoPremium kq;
     kq.tu = tu * ps.mau;
     kq.mau = mau * ps.tu;
     kq.RutGon();
     return kq;
    }

    bool operator==(cPhanSoPremium ps) {
     if (tu == ps.tu && mau == ps.mau) {
        return true;
     }
     return false;
    }
    bool operator>(cPhanSoPremium ps) {
     if (tu * ps.mau > mau * ps.tu) {
        return true;
     }
     return false;
    }
    bool operator<(cPhanSoPremium ps) {
     if (tu * ps.mau < mau * ps.tu) {
        return true;
     }
     return false;
    }

    friend ostream& operator<<(ostream& os, cPhanSoPremium ps) {
     os << ps.tu << "/" << ps.mau;
     return os;
    }
    friend istream& operator>>(istream& is, cPhanSoPremium& ps){
     is >> ps.tu >> ps.mau;
     return is;
    }
};

