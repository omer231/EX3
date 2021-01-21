#include <iostream>
#include <stdio.h>
#include "exceptions.h"
using std::cout;
using std::endl;
using std:: exception;
using namespace std;
extern "C" {
#include "date.h"
}

namespace mtm 
{ 
class DateWrap {
    private:
    Date date;
    public:
    DateWrap(int, int, int);

    DateWrap(Date);

    int day();

    int month();

    int year();

    Date getDate(DateWrap date_wrap);
    
    void operator++ (int);

    DateWrap operator+(int);

    DateWrap operator+=(int);

    bool operator>(const DateWrap&);

    bool operator<(const DateWrap&);

    bool operator>=(const DateWrap& );

    bool operator<=(const DateWrap&);

    bool operator==(const DateWrap&);

    bool operator!=(const DateWrap&);
   
    friend ostream& operator << (ostream& os, DateWrap date_wrap);

    friend DateWrap operator+(const int& days, const DateWrap date_wrap);
    
};

    ostream& operator << (ostream& os, DateWrap date_wrap);
    DateWrap operator+(const int& days, const DateWrap date_wrap);
}