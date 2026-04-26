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

    bool correctData(int y, int m, int d);
    DataTime(int d, int m, int y);
    DataTime(const char* date);
    DataTime(const char* date, const char* time);

    int getYear();
    int getDay();
    int getMonth();

    static string doubleDigits(int value);
    long long operator-(const DataTime&r) const;
    string dayWeek() const;
    string toShort() const;
    string toLong() const;
    friend ostream& operator<<(ostream& out, const DataTime& data);
    static string formatTime(const string& hms);
};


