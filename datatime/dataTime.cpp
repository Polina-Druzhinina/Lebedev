#include "dataTime.h"

string doubleDigits(int value) {
    if (value < 10) return "0" + to_string(value);
    return to_string(value);
}

bool correctData(int y, int m, int d){ //проверяет на корректность
    if (d < 1 || m < 1 || y < 1 || m > 12)
        return false;
    int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
        daysInMonth[1] = 29;
    }
    return d <= daysInMonth[m - 1];
}

long long translationDate(int d, int mon, int ye){ //Юлианская дата
    int a = (14-mon)/12;
    int y = ye + 4800 -a;
    int m = mon + 12*a - 3;
    long long result = d+(153*m+2)/5 + 365*y + y/4 - y/100 + y/400 - 32045;
    return result;
}

DataTime::DataTime(int d, int m, int y){ //конструктор 1
    if (!correctData(y, m, d))
        throw DateException();
    day = d;
    month = m;
    year = y;
    hour = 0;
    minute = 0;
    second = 0;
}

DataTime::DataTime(const char* date){ //конструктор даты с .
    if(!date) throw DateException();
    int len = 0;
    while(date[len] != '\0') len++;
    if (len != 10) throw DateException();

    if(date[2] != '.' || date[5] != '.') throw DateException();
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) continue;
        if (!isdigit(date[i]))
            throw DateException();
    }
    int d = (date[0] - '0') * 10 + (date[1] - '0');
    int m = (date[3] - '0') * 10 + (date[4] - '0');
    int y = (date[6] - '0') * 1000 +(date[7] - '0') * 100 +(date[8] - '0') * 10 +(date[9] - '0');
    if(!correctData(y,m,d)) throw DateException();
    day = d;
    month = m;
    year = y;

    hour = 0;
    minute = 0;
    second = 0;
}

DataTime::DataTime(const char* date, const char* time){ //конструктор с датой и временем
    if(!date || !time) throw DateException();
    int len = 0;
    while(date[len] != '\0') len++;
    if (len != 10) throw DateException();

    if(date[4] != '-' || date[7] != '-') throw DateException();
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i]))
            throw DateException();
    }
    int d = (date[8] - '0') * 10 + (date[9] - '0');
    int m = (date[5] - '0') * 10 + (date[6] - '0');
    int y = (date[0] - '0') * 1000 +(date[1] - '0') * 100 +(date[2] - '0') * 10 +(date[3] - '0');
    if(!correctData(y,m,d)) throw DateException();
    day = d;
    month = m;
    year = y;

    len = 0;
    while(time[len] != '\0') len++;
    if (len != 8) throw DateException();

    if(time[2] != ':' || time[5] != ':') throw DateException();
    for (int i = 0; i < 8; i++) {
        if (i == 2 || i == 5) continue;
        if (!isdigit(time[i]))
            throw DateException();
    }
    int h = (time[0] - '0') * 10 + (time[1] - '0');
    int min = (time[3] - '0') * 10 + (time[4] - '0');
    int s = (time[6] - '0') * 10 + (time[7] - '0');
    if (h > 23 || min > 59 || s > 59) throw DateException();
    hour = h;
    minute = min;
    second = s;
}

long long DataTime::operator-(const DataTime&r) const{ //перегрузка оператора в днях, даже с временем
    long long seconds1 = translationDate(day, month, year) * 86400LL+ hour * 3600+ minute * 60+ second;
    long long seconds2 = translationDate(r.day, r.month, r.year) * 86400LL+ r.hour * 3600+ r.minute * 60+ r.second;
    return (seconds1 - seconds2)/86400;
}

string DataTime::dayWeek()const{ //день недели
    long long jl = translationDate(day, month, year);
    int weekday = jl % 7;
    string days[] = {
        "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday", "Sunday"
    };
    return days[weekday];
}

ostream& operator<<(ostream& out, const DataTime& data){ //вывод в формате 
    out<<data.toShort();
    return out;
}

string DataTime::toShort() const { //по умолчанию << 
    string res;
    res +=(doubleDigits(day)+".");
    res += (doubleDigits(month)+".");
    res += to_string(year);
    if (hour != 0 || minute != 0 || second != 0) {
        res += " ";
        res += doubleDigits(hour) + ":";
        res += doubleDigits(minute) + ":";
        res += doubleDigits(second);
    }
    return res;
}

string DataTime::toLong() const {
    static const string months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    string res;
    res += to_string(day);
    res += " ";
    res += months[month - 1];
    res += " ";
    res += to_string(year);
    return res;
}

DataTime DataTime::easter(int year) {
    int a = year % 19;
    int b = year / 100;
    int c = year % 100;
    int d = b / 4;
    int e = b % 4;
    int f = (b + 8) / 25;
    int g = (b - f + 1) / 3;
    int h = (19 * a + b - d - g + 15) % 30;
    int i = c / 4;
    int k = c % 4;
    int l = (32 + 2 * e + 2 * i - h - k) % 7;
    int m = (a + 11 * h + 22 * l) / 451;
    int month = (h + l - 7 * m + 114) / 31;
    int day = ((h + l - 7 * m + 114) % 31) + 1;
    return DataTime(day, month, year);
}