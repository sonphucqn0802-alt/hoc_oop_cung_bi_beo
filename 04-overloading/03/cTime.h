#pragma once

#include <iostream>
using namespace std;

class cTime {
     int hour;
     int minute;
     int second;
public:
    cTime(){
        hour = 0;
        minute = 0;
        second = 0;
    }
    cTime(int hour, int minute, int second){
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
    ~cTime(){
        
    }

    void setTime(int hour, int minute, int second){
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }

    int getHour() const {
        return hour;
    }
    int getMinute() const {
        return minute;
    }
    int getSecond() const {
        return second;
    }

    void xuLyThoiGian(){
          if (second >= 60) {
            minute += second / 60;
            second %= 60;
        }
        if (minute >= 60) {
            hour += minute / 60;
            minute %= 60;
        }
        if (hour >= 24) {
            hour %= 24;
        }
    }
    
    cTime operator+(int seconds){
     second += seconds;
     xuLyThoiGian();
     return *this;
    }

    cTime operator-(int seconds){
     second -= seconds;
     xuLyThoiGian();
     return *this;
    }

    cTime operator++(){
     second++;
     xuLyThoiGian();
     return *this;
    }
    cTime operator--(){
     second--;
     xuLyThoiGian();
     return *this;
    }

    friend ostream& operator<<(ostream& os, const cTime& time){
        os << time.hour << ":" << time.minute << ":" << time.second;
        return os;
    }
    friend istream& operator>>(istream& is, cTime& time){
        is >> time.hour >> time.minute >> time.second;
        return is;
    }
};
