//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/*Cài đặt lớp biểu diễn khái niệm ngày tháng năm với các thành phần dữ liệu
ngày, tháng, năm và các thao tác thích hợp (nhập, xuất, thiết lập, thay đổi
ngày/tháng/năm, lấy ngày/tháng/năm, tăng/giảm ngày/tháng/năm, lấy thứ trong
tuần, kiểm tra năm nhuận,…). Viết chương trình minh họa các chức năng đã cài
đặt của lớp ngày tháng năm.*/
#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;

public:
    Date(int d = 1, int m = 1, int y = 1000) {
        day = d;
        month = m;
        year = y;
    }

    void input() {
        cout << "Nhap ngay: ";
        cin >> day;
        cout << "Nhap thang: ";
        cin >> month;
        cout << "Nhap nam: ";
        cin >> year;
    }

    void output() {
        cout << day << "/" << month << "/" << year << endl;
    }

    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }

    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    bool isLeapYear() {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int daysInMonth() {
        int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if (month == 2 && isLeapYear())
            return 29;
        return days[month - 1];
    }
//tăng 1 ngày
    void nextDay() {
        day++;
        if (day > daysInMonth()) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
//giảm 1 ngày
    void prevDay() {
        day--;
        if (day < 1) {
            month--;
            if (month < 1) {
                month = 12;
                year--;
            }
            int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
            if (month == 2 && isLeapYear())
                day = 29;
            else
                day = days[month - 1];
        }
    }

    string dayOfWeek() {
        int m = month, y = year, d = day;

        if (m < 3) {
            m += 12;
            y--;
        }

        int K = y % 100;
        int J = y / 100;

        int h = (d + 13*(m+1)/5 + K + K/4 + J/4 + 5*J) % 7;

        string days[] = {"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};

        return days[h];
    }
};


int main() {
    Date d(28, 2, 2024);
    Date z();
    z.input();
    cout << "Ngay vua nhap la: " << z.dayOfWeek() << endl;
    cout << "Ngay vua nhap la: " << z.day << "/" << z.month << "/" << z.year << endl;
    d.output();
    d.nextDay();
    d.output();
    d.prevDay();
    d.output();
    cout << "Ngay hom nay la: " << d.dayOfWeek() << endl;
    cout << "Ngay hom nay la: " << d.day << "/" << d.month << "/" << d.year << endl;
    return 0;
}