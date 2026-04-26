#include "dataTime.h"
#include <iostream>

using namespace std;

void splitDateTime(const char* full_date, char* full_d, char* full_h);

int main() {
    try {
        DataTime date1(30, 3, 2026);
        DataTime date2(30, 3, 2025);
        cout << "Difference: " <<date2<<"-"<<date1<<"= "<< date2 - date1 << endl;

        DataTime date3(28, 2, 2020);
        DataTime date4(1, 3, 2020);
        cout << "Difference: " <<date4<<"-"<<date3<<"= "<< date4 - date3 << endl;

        DataTime date5(5, 4, 2026);
        cout << "Day of week " <<date5<<"= "<< date5.dayWeek() << endl;
        cout << "Short format: " << date5 << endl;
        cout << "Long format: " << date5.toLong() << endl;

        cout << "Enter two dates (dd.mm.yyyy):" << endl;
        char date6[11];
        char date7[11];
        cin >> date6;
        cin >> date7;
        DataTime d6(date6);
        DataTime d7(date7);
        cout << "Difference: " << (d7 - d6) << endl;
        cout << "Day week (second date): " << d7.dayWeek() << endl;

        cout << "Enter datetime (yyyy-MM-ddThh:mm:ss):" << endl;
        char full_date[20];
        cin >> full_date;
        char full_d[11];
        char full_h[9];
        splitDateTime(full_date, full_d, full_h);
        DataTime dt(full_d, full_h);
        cout << "Parsed datetime: " << dt << endl;

        DataTime t1("2026-04-27", "12:00:00");
        DataTime t2("2026-04-25", "00:00:00");
        cout << "Difference: " << (t1 - t2) << endl;


        DataTime p = DataTime::easter(2026);
        cout << "Easter: " << p.toLong() << endl;

    }
    catch (const DateException& e) {
        cout << "Date error!" << endl;
    }
    return 0;
}

void splitDateTime(const char* full_date, char* full_d, char* full_h) {
    const char* ptr = full_date;
    int i = 0;
    while (*ptr != 'T' && *ptr != '\0' && i <  10) {
        full_d[i++] = *ptr;
        ptr++;
    }
    full_d[i] = '\0';

    if (*ptr == 'T') ptr++; // пропускаем 'T'
    i = 0;
    while (*ptr != '\0' && i < 8) {
        full_h[i++] = *ptr;
        ptr++;
    }
    full_h[i] = '\0';
}