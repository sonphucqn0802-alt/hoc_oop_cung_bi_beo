
/*Cài đặt lớp biểu diễn khái niệm thời gian với các thành phần dữ liệu giờ, phút,
giây và các thao tác thích hợp (nhập, xuất, thiết lập, thay đổi giờ/phút/giây, lấy
giờ/phút/giây, tăng/giảm giờ/phút/giây,…). Viết chương trình minh họa các chức
năng đã cài đặt của lớp Thời gian.*/
#include <bits/stdc++.h>
using namespace std;

class cThoiGian {
    int iGio;
    int iPhut;
    int iGiay;
    
    public:
        //Constructor
        cThoiGian();
        cThoiGian(int, int, int);
        
        //Hàm thao tác
        void SetTime(int, int, int);
        void GetTime();
        void ChangeTime(cThoiGian);
        void InputTime();
        void UpTime();
        void DownTime();
        
        //Destructor
        ~cThoiGian();
};
