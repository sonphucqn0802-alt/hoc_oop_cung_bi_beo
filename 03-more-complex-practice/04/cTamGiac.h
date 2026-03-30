#pragma once

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;

class cDiem {
public:
     int x, y;

     cDiem(int x = 0, int y = 0) : x(x), y(y) {
     }
};

class cTamGiac {
     cDiem A, B, C;
     int loai; // 0: thuong, 1: vuong, 2: can, 3: deu
public:
     cTamGiac(double x1, double y1, double x2, double y2, double x3, double y3, int loai):
         A(x1, y1), B(x2, y2), C(x3, y3), loai(loai) {
     }
     ~cTamGiac() {
     }
     void nhap() {
         cout << "Nhap toa do diem A: ";
         cin >> A.x >> A.y;
         cout << "Nhap toa do diem B: ";
         cin >> B.x >> B.y;
         cout << "Nhap toa do diem C: ";
         cin >> C.x >> C.y;
     }

     void xuat() {
         cout << "Toa do diem A: " << A.x << " " << A.y << endl;
         cout << "Toa do diem B: " << B.x << " " << B.y << endl;
         cout << "Toa do diem C: " << C.x << " " << C.y << endl;
     }

     int getLoai() {
         return loai;
     }

     void kiemtra() {
         auto binhPhuongCanh = [](const cDiem& P, const cDiem& Q) {
             long long dx = P.x - Q.x;
             long long dy = P.y - Q.y;
             return dx * dx + dy * dy;
         };
         auto thangHang = [](const cDiem& P, const cDiem& Q, const cDiem& R) {
             long long x1 = Q.x - P.x;
             long long y1 = Q.y - P.y;
             long long x2 = R.x - P.x;
             long long y2 = R.y - P.y;
             return x1 * y2 - y1 * x2 == 0;
         };

         long long ab2 = binhPhuongCanh(A, B);
         long long bc2 = binhPhuongCanh(B, C);
         long long ca2 = binhPhuongCanh(C, A);

         if (ab2 == 0 || bc2 == 0 || ca2 == 0 || thangHang(A, B, C)) {
             loai = -1;
         } else if (ab2 == bc2 && bc2 == ca2) {
             loai = 3;
         } else if (ab2 + bc2 == ca2 || bc2 + ca2 == ab2 || ca2 + ab2 == bc2) {
             loai = 1;
         } else if (ab2 == bc2 || bc2 == ca2 || ca2 == ab2) {
             loai = 2;
         } else {
             loai = 0;
         }
     }
     void tinhChuVi() {
         double ab = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
         double bc = sqrt((B.x - C.x) * (B.x - C.x) + (B.y - C.y) * (B.y - C.y));
         double ca = sqrt((C.x - A.x) * (C.x - A.x) + (C.y - A.y) * (C.y - A.y));
         cout << "Chu vi: " << ab + bc + ca << endl;
     }
     void tinhDienTich() {
         double ab = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
         double bc = sqrt((B.x - C.x) * (B.x - C.x) + (B.y - C.y) * (B.y - C.y));
         double ca = sqrt((C.x - A.x) * (C.x - A.x) + (C.y - A.y) * (C.y - A.y));
         double p = (ab + bc + ca) / 2;
         cout << "Dien tich: " << sqrt(p * (p - ab) * (p - bc) * (p - ca)) << endl;
     }
     
     void TinhTien(int dx, int dy) {
         A.x += dx;
         A.y += dy;
         B.x += dx;
         B.y += dy;
         C.x += dx;
         C.y += dy;
     }

     void PhongTo(int k) {
         A.x *= k;
         A.y *= k;
         B.x *= k;
         B.y *= k;
         C.x *= k;
         C.y *= k;
     }

     void ThuNho(int k) {
         A.x /= k;
         A.y /= k;
         B.x /= k;
         B.y /= k;
         C.x /= k;
         C.y /= k;
     }
};




