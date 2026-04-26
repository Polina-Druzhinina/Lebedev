#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class DateException{};
class DataTime{
    
public:
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int second;

    DataTime(const char* date);
    DataTime(const char* date, const char* time);
    DataTime(int d, int m, int y);
    long long operator-(const DataTime&r) const;
    string dayWeek() const;
    string toShort() const;
    string toLong() const;
    static DataTime easter(int year); //пасха
    friend ostream& operator<<(ostream& out, const DataTime& data);
    friend class MoonFile;
};


