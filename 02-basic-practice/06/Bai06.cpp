//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/*Cài đặt lớp cString để biểu diễn khái niệm chuỗi ký tự với các phương thức thiết
lập và hủy bỏ, các hàm thành phần xác định chiều dài chuỗi, nối hai chuỗi, đảo
chuỗi, chuyển chuỗi hoa/thường, nhập và xuất chuỗi. Viết chương trình minh họa
các chức năng đã cài đặt của lớp cString.
*/


#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class cString {
    char *str;

public:
    cString() {
        str = new char[1];
        str[0] = '\0';
    }

    cString(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    ~cString() {
        delete[] str;
    }

    void input() {
        char s1[1000];
        cout << "Nhap chuoi: ";
        cin.getline(s1, 1000);

        delete[] str;
        str = new char[strlen(s1) + 1];
        strcpy(str, s1);
    }

    void output() {
        cout << str;
    }

    int length() {
        return strlen(str);
    }

    cString sumstr(const cString &p) {
        char *s1 = new char[strlen(str) + strlen(p.str) + 1];

        strcpy(s1, str);
        strcat(s1, p.str);

        cString result(s1);
        delete[] s1;

        return result;
    }

    void reverse() {
        int n = strlen(str);
        for (int i = 0; i < n/2; i++) {
            char t = str[i];
            str[i] = str[n - i - 1];
            str[n - i - 1] = t;
        }
    }

    void toUpper() {
        for (int i = 0; str[i]; i++)
            str[i] = toupper(str[i]);
    }

    void toLower() {
        for (int i = 0; str[i]; i++)
            str[i] = tolower(str[i]);
    }
};

int main (){
    cString s1;
    cString s2("Xin");
    cString s3("Chao");
    
    s1.input();
    s1.output();
    cout << endl;
    
    s2.output(); cout << endl;
    s3.output(); cout << endl;
    
    cString s4 = s2.sumstr(s3);
    s4.output();
    cout << endl; 
    
    s1.reverse();
    s1.output();
    cout << endl;
    
    s1.toUpper();
    s1.output();
    cout << endl;
    
    s2.toLower();
    s2.output();
    cout << endl;
    
    return 0;
}