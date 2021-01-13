#include <iostream>
using std::cout;
using std::endl;
using namespace std;
extern "C" {
#include "date.h"
}
namespace mtm 
{ 
    struct NegativeDays : public std::exception
    {
	    const char * NegativeDaysException () const throw ()
        {
    	    return "NegativeDays";
        }
    };
}

class DateWrap {
    private:
    int Day, Month, Year;
    public:
    DateWrap(int day, int month, int year)
    {
        Date date=dateCreate(day, month, year);
        int *day_p, *month_p, *year_p;
        dateGet(date, day_p, month_p, year_p);
        Day=*day_p;
        Month=*month_p;
        Year=*year_p;
    }

    int day()
    {
        return Day;
    }

    int month()
    {
        return Month;
    }

    int year()
    {
        return Year;
    }
    
    DateWrap operator++ (int)
    {
        Date date=toDate(*this);
        dateTick(date);
        return toDateWrap(date);
    }
};

DateWrap toDateWrap(Date date)
{
    int *day, *month, *year;
    dateGet(date, day, month, year);
    DateWrap date_wrap(*day, *month, *year);
    return date_wrap;
}

Date toDate(DateWrap date_wrap)
{
    return dateCreate(date_wrap.day(), date_wrap.month(), date_wrap.year());
}

void print(DateWrap date)
{
    cout << date.day() << '/' << date.month() << '/' << date.year() << endl;
}

DateWrap addDays(const DateWrap date_wrap, int days)
{
    Date date=toDate(date_wrap);
    for(int i=0; i<days; i++)
    {
        dateTick(date);
    }
    return toDateWrap(date); 
}

DateWrap operator+(const DateWrap date_wrap, int days)
{
    if(days<0)
    {
        cout << ("NegativeDays");
    }
    return addDays(date_wrap, days);
}
DateWrap operator+(int days, const DateWrap date_wrap)
{
    if(days<0)
    {
       cout << ("NegativeDays");
    }
    return addDays(date_wrap, days);
}


DateWrap operator+=(const DateWrap date_wrap, int days)
{
    if(days<0)
    {
        cout << ("NegativeDays");
    }
    return addDays(date_wrap, days);
}

int getDiff(const DateWrap date_wrap1,const DateWrap date_wrap2)
{
    Date date1=toDate(date_wrap1);
    Date date2=toDate(date_wrap2);
    return dateCompare(date1, date2);
}

bool operator>(const DateWrap date_wrap1,const DateWrap date_wrap2)
{
    if(getDiff(date_wrap1, date_wrap2)<0)
    {
        return true;
    }
    return false;
}

bool operator<(const DateWrap date_wrap1,const DateWrap date_wrap2)
{
    if(getDiff(date_wrap1, date_wrap2)<0)
    {
        return false;
    }
    return true;
}

bool operator==(const DateWrap date_wrap1,const DateWrap date_wrap2)
{
    if(getDiff(date_wrap1, date_wrap2)==0)
    {
        return true;
    }
    return false;
}

bool operator>=(const DateWrap date_wrap1,const DateWrap date_wrap2)
{
    if(getDiff(date_wrap1, date_wrap2)>0||getDiff(date_wrap1, date_wrap2)==0)
    {
        return true;
    }
    return false;
}

bool operator<=(const DateWrap date_wrap1,const DateWrap date_wrap2)
{
    if(getDiff(date_wrap1, date_wrap2)<0||getDiff(date_wrap1, date_wrap2)==0)
    {
        return false;
    }
    return true;
}