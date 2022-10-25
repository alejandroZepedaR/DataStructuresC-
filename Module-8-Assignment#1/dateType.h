#ifndef dateType_h
#define dateType_h
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class dateType
{
    public:
        dateType(int d, int m, int y)
        {
            day = d;
            month = m;
            year = y;
        }
        dateType()
        {
            day = 0;
            month = 0;
            year = 0;
        }

        void setDay(int d)
        {
            day = d;
        }
        void setMonth(int m)
        {
            month = m;
        }
        void setYear(int y)
        {
            year = y;
        }

        void getDate()
        {
            cout<<month<<"/"<<day<<"/"<<year<<endl;
        }

    private:
        int day;
        int month;
        int year;
};

#endif