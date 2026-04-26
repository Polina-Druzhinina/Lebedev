#include <iostream>
#include "dataTime.h"
#include <string>
#include <fstream>
#include <ctime>
using namespace std;
int main(){
        cout << "Enter date (dd.mm.yyyy):" << endl;
        char date[11];
        cin >> date;
        DataTime d(date);
        string year = to_string(d.getYear());

        string fileName = "Moon/moon"+year+".dat";
        ifstream file(fileName);
        if(!file.is_open()){
            cout<<"No file";
            return -1;
        }

        string header;
        getline(file, header);

        string ymd, hms;
        double T, R, El, Az, FI, LG;
        double H, Sh, Dl;
        string hms_sunrise, hms_sunset, hms_max;
        double prevEl = 0, maxi = 0;
        bool first = true;
        string needData = to_string(d.getYear()) + DataTime::doubleDigits(d.getMonth()) + DataTime::doubleDigits(d.getDay());
        
        bool hasEl = (header.find("El") != string::npos);
        double ElH;

        clock_t start = clock();
        while (file >> ymd >> hms) {
            if(hasEl){
                file>>T>>R>>El>>Az>>FI>>LG;
                ElH = El;
            }
            else{
                file >> R >> H >> Az >> Sh >> Dl;
                ElH = H;
            }

            if(needData != ymd) continue;
            //cout<<ymd + " " + hms + " "<<ElH<<endl;
            if (first){
                prevEl = ElH;
                maxi = ElH;
                first = false;
                continue;
            }
            if (prevEl < 0 && ElH > 0){
                hms_sunrise = hms;
            }

            if(prevEl > 0 && ElH < 0){
                hms_sunset = hms;
            }

            if(maxi < ElH){
                maxi = ElH;
                hms_max = hms;
            }
            prevEl = ElH;
        }
        clock_t end = clock();
        double time = (double)(end - start) / CLOCKS_PER_SEC;

        cout<<"Date: "<<d<<endl;
        cout<<"Sunrise: "<<DataTime::formatTime(hms_sunrise)<<endl;
        cout<<"Culmination: "<<DataTime::formatTime(hms_max)<<endl;
        cout<<"Sunset: "<<DataTime::formatTime(hms_sunset)<<endl;
        cout<<"Time: "<<time<<endl;
        return 0;
}