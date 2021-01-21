#include <iostream>
#include "exceptions.h"
#include "date_wrap.h"
using std::cout;
using std::endl;
using namespace std;
extern "C" {
#include "date.h"
}
namespace mtm{
    
    DateWrap::DateWrap(int day, int month, int year)
    {
        date=dateCreate(day, month, year);
    }

    DateWrap::DateWrap(Date date_insert)
    {
        date=dateCopy(date_insert);
    }

    Date DateWrap::getDate(DateWrap date_wrap)
    {
        return date_wrap.date;
    }

    int DateWrap::day()
    {
        int day, month, year;
        dateGet(this->date, &day, &month, &year);
        return day;
    }

    int DateWrap::month()
    {
        int day, month, year;
        dateGet(this->date, &day, &month, &year);
        return month;
    }

    int DateWrap::year()
    {
        int day, month, year;
        dateGet(this->date, &day, &month, &year);
        return year;
    }
    
    void DateWrap::operator++ (int)
    {
        dateTick(this->date);
    }

    DateWrap DateWrap::operator+(int days)
    {
        if(days<0)
        {
            throw mtm::NegativeDays();
        }
        Date new_date=dateCopy(this->date);
        for(int i=0; i<days; i++)
        {
            dateTick(new_date);
        }
        DateWrap new_date_wrap(new_date);
        return new_date_wrap;
    }
    
    

   DateWrap  DateWrap::operator+=(int days)
    {
         if(days<0)
        {
            throw mtm::NegativeDays();
        }
        for(int i=0; i<days; i++)
        {
            dateTick(this->date);
        }
        return *this;
    }

    bool DateWrap::operator>(const DateWrap& date_wrap)
    {
        if((dateCompare(date, date_wrap.date))>0)
        {
            return true;
        }
        return false;
    }

    bool DateWrap::operator<(const DateWrap& date_wrap)
    {
        if((dateCompare(date, date_wrap.date))>0)
        {
            return false;
        }
        return true;
    }

    bool DateWrap::operator>=(const DateWrap& date_wrap)
    {
        if((dateCompare(date, date_wrap.date))>=0)
        {
            return true;
        }
        return false;
    }

    bool DateWrap::operator<=(const DateWrap& date_wrap)
    {
        if((dateCompare(date, date_wrap.date))>=0)
        {
            return false;
        }
        return true;
    }

    bool DateWrap::operator==(const DateWrap& date_wrap)
    {
        if((dateCompare(date, date_wrap.date))==0)
        {
            return true;
        }
        return false;
    }

    bool DateWrap::operator!=(const DateWrap& date_wrap)
    {
        if((dateCompare(date, date_wrap.date))==0)
        {
            return false;
        }
        return true;
    }

    ostream& operator << (ostream& os, DateWrap date_wrap)
    {   
        os << date_wrap.day() << "/" << date_wrap.month() << "/" << date_wrap.year();
        return os;
    }
    
    DateWrap operator+(const int& days, const DateWrap date_wrap)
    {
        if(days<0)
        {
            throw mtm::NegativeDays();
        }
        Date new_date=dateCopy(date_wrap.date);
        for(int i=0; i<days; i++)
        {
            dateTick(new_date);
        }
        DateWrap new_date_wrap(new_date);
        return new_date_wrap;
    }
}




