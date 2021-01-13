#ifndef DATE_WRAP_H_
#define DATE_WRAP_H_

#include <iostream>
using std::cout;
using std::endl;
using namespace std;
extern "C" {
#include "date.h"
}
namespace mtm 
{ 
    struct NegativeDays : public std::exception{};
}

class DateWrap {
    public:
    DateWrap(int day, int month, int year);

    int day();

    int month();

    int year();
    
    DateWrap operator++ (int);
};

DateWrap toDateWrap(Date date);

Date toDate(DateWrap date_wrap);

void print(DateWrap date);

DateWrap addDays(const DateWrap date_wrap, int days);

DateWrap operator+(const DateWrap date_wrap, int days);

DateWrap operator+(int days, const DateWrap date_wrap);

DateWrap operator+=(const DateWrap date_wrap, int days);

int getDiff(const DateWrap date_wrap1,const DateWrap date_wrap2);

bool operator>(const DateWrap date_wrap1,const DateWrap date_wrap2);

bool operator<(const DateWrap date_wrap1,const DateWrap date_wrap2);

bool operator==(const DateWrap date_wrap1,const DateWrap date_wrap2);

bool operator>=(const DateWrap date_wrap1,const DateWrap date_wrap2);

bool operator<=(const DateWrap date_wrap1,const DateWrap date_wrap2);

#endif //DATE_WRAP_H_