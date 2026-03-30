#pragma once //để chỉ gọi include một lần cho file này

#include <cstdlib>
#include <iostream>

using namespace std;

class cPhanSo {
private:
    long long iTuSo;
    long long iMauSo;

    static long long TimUCLN(long long a, long long b) {
        while (b != 0) {
            long long soDu = a % b;
            a = b;
            b = soDu;
        }
        return a;
    }

    void ChuanHoa() {
        if (iMauSo < 0) {
            iTuSo = -iTuSo;
            iMauSo = -iMauSo;
        }

        if (iTuSo == 0) {
            iMauSo = 1;
            return;
        }

        long long ucln = TimUCLN(llabs(iTuSo), llabs(iMauSo));
        iTuSo /= ucln;
        iMauSo /= ucln;
    }

    static bool LaSoNguyenTo(long long n) {
        if (n < 2) {
            return false;
        }

        for (long long i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

public:
    cPhanSo(long long tuSo = 0, long long mauSo = 1) : iTuSo(tuSo), iMauSo(mauSo == 0 ? 1 : mauSo) {
        ChuanHoa();
    }

    void Nhap() {
        cout << "Nhap tu so: ";
        cin >> iTuSo;

        do {
            cout << "Nhap mau so (khac 0): ";
            cin >> iMauSo;
        } while (iMauSo == 0);

        ChuanHoa();
    }

    void Xuat() const {
        cout << iTuSo << "/" << iMauSo;
    }

    cPhanSo Cong(const cPhanSo& ps) const {
        return cPhanSo(iTuSo * ps.iMauSo + ps.iTuSo * iMauSo, iMauSo * ps.iMauSo);
    }

    bool LonHon(const cPhanSo& ps) const {
        return iTuSo * ps.iMauSo > ps.iTuSo * iMauSo;
    }

    bool NhoHon(const cPhanSo& ps) const {
        return iTuSo * ps.iMauSo < ps.iTuSo * iMauSo;
    }

    long long GetTuSo() const {
        return iTuSo;
    }
    
    long long GetMauSo() const {
        return iMauSo;
    }

    bool TuLaSoNguyenTo() const {
        return LaSoNguyenTo(iTuSo);
    }
};

class cDSPhanSo {
private:
    cPhanSo* ds;
    int iSoLuong;

    void GiaiPhong() {
        delete[] ds;
        ds = nullptr;
        iSoLuong = 0;
    }

    void SaoChepTu(const cDSPhanSo& other) {
        iSoLuong = other.iSoLuong;
        if (iSoLuong == 0) {
            ds = nullptr;
            return;
        }

        ds = new cPhanSo[iSoLuong];
        for (int i = 0; i < iSoLuong; ++i) {
            ds[i] = other.ds[i];
        }
    }

    void HoanDoi(cPhanSo& a, cPhanSo& b) {
        cPhanSo tam = a;
        a = b;
        b = tam;
    }

public:
    cDSPhanSo() : ds(nullptr), iSoLuong(0) {}

    cDSPhanSo(const cDSPhanSo& other) : ds(nullptr), iSoLuong(0) {
        SaoChepTu(other);
    }

    cDSPhanSo& operator=(const cDSPhanSo& other) {
        if (this != &other) {
            GiaiPhong();
            SaoChepTu(other);
        }
        return *this;
    }

    ~cDSPhanSo() {
        delete[] ds;
    }

    void Nhap() {
        int n;
        do {
            cout << "Nhap so luong phan so: ";
            cin >> n;
        } while (n < 0);

        GiaiPhong();
        iSoLuong = n;

        if (iSoLuong == 0) {
            return;
        }

        ds = new cPhanSo[iSoLuong];
        for (int i = 0; i < iSoLuong; ++i) {
            cout << "Nhap phan so thu " << i + 1 << ":\n";
            ds[i].Nhap();
        }
    }

    void Xuat() const {
        if (iSoLuong == 0) {
            cout << "[]";
            return;
        }

        cout << "[";
        for (int i = 0; i < iSoLuong; ++i) {
            ds[i].Xuat();
            if (i + 1 < iSoLuong) {
                cout << ", ";
            }
        }
        cout << "]";
    }

    bool Rong() const {
        return iSoLuong == 0;
    }

    cPhanSo TinhTong() const {
        cPhanSo tong;
        for (int i = 0; i < iSoLuong; ++i) {
            tong = tong.Cong(ds[i]);
        }
        return tong;
    }

    cPhanSo TimLonNhat() const {
        cPhanSo lonNhat = ds[0];
        for (int i = 1; i < iSoLuong; ++i) {
            if (ds[i].LonHon(lonNhat)) {
                lonNhat = ds[i];
            }
        }
        return lonNhat;
    }

    cPhanSo TimNhoNhat() const {
        cPhanSo nhoNhat = ds[0];
        for (int i = 1; i < iSoLuong; ++i) {
            if (ds[i].NhoHon(nhoNhat)) {
                nhoNhat = ds[i];
            }
        }
        return nhoNhat;
    }

    bool TimPhanSoCoTuLaSoNguyenToLonNhat(cPhanSo& ketQua) const {
        bool timThay = false;

        for (int i = 0; i < iSoLuong; ++i) {
            if (!ds[i].TuLaSoNguyenTo()) {
                continue;
            }

            if (!timThay || ds[i].GetTuSo() > ketQua.GetTuSo() ||
                (ds[i].GetTuSo() == ketQua.GetTuSo() && ds[i].LonHon(ketQua))) {
                ketQua = ds[i];
                timThay = true;
            }
        }

        return timThay;
    }

    void SapXepTangDan() {
        for (int i = 0; i < iSoLuong - 1; ++i) {
            for (int j = i + 1; j < iSoLuong; ++j) {
                if (ds[j].NhoHon(ds[i])) {
                    HoanDoi(ds[i], ds[j]);
                }
            }
        }
    }

    void SapXepGiamDan() {
        for (int i = 0; i < iSoLuong - 1; ++i) {
            for (int j = i + 1; j < iSoLuong; ++j) {
                if (ds[j].LonHon(ds[i])) {
                    HoanDoi(ds[i], ds[j]);
                }
            }
        }
    }
};
