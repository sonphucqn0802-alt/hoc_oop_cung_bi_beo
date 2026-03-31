#pragma once

#include <iostream> 
using namespace std;

class cSoPhuc {
private:
    double thuc;
    double ao;
public:
    cSoPhuc() {
        thuc = 0;
        ao = 0;
    }
    cSoPhuc(double thuc, double ao) {
        this->thuc = thuc;
        this->ao = ao;
    }
    double getThuc() {
        return thuc;
    }
    double getAo() {
        return ao;
    }
    void setThuc(double thuc) {
        this->thuc = thuc;
    }
    void setAo(double ao) {
        this->ao = ao;
    }
    cSoPhuc operator+(cSoPhuc sp) {
        cSoPhuc temp;
        temp.thuc = thuc + sp.thuc;
        temp.ao = ao + sp.ao;
        return temp;
    }
    cSoPhuc operator-(cSoPhuc sp) {
        cSoPhuc temp;
        temp.thuc = thuc - sp.thuc;
        temp.ao = ao - sp.ao;
        return temp;
    }
    cSoPhuc operator*(cSoPhuc sp) {
        cSoPhuc temp;
        temp.thuc = thuc * sp.thuc - ao * sp.ao;
        temp.ao = thuc * sp.ao + ao * sp.thuc;
        return temp;
    }
    cSoPhuc operator/(cSoPhuc sp) {
        cSoPhuc temp;
        temp.thuc = (thuc * sp.thuc + ao * sp.ao) / (sp.thuc * sp.thuc + sp.ao * sp.ao);
        temp.ao = (ao * sp.thuc - thuc * sp.ao) / (sp.thuc * sp.thuc + sp.ao * sp.ao);
        return temp;
    }
    bool operator==(cSoPhuc sp) {
        return thuc == sp.thuc && ao == sp.ao;
    }
    bool operator!=(cSoPhuc sp) {
        return thuc != sp.thuc || ao != sp.ao;
    }
    friend ostream& operator<<(ostream& os, cSoPhuc sp) {
        os << sp.thuc << " + " << sp.ao << "i";
        return os;
    }
    friend istream& operator>>(istream& is, cSoPhuc& sp) {
        cout << "Nhap phan thuc: ";
        is >> sp.thuc;
        cout << "Nhap phan ao: ";
        is >> sp.ao;
        return is;
    }
};