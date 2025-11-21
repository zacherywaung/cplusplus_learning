#include"../include/date.h"

void Date::PrintDate()
{
    cout << _year << "/" << _month << "/" << _day << endl;
}

int Date::GetMonthDay(int year, int month)
{
    int month_day_array[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    {
        return 29;
    }
    return month_day_array[month];
}

Date::Date(int year, int month, int day)
{
    _year = year;
    _month = month;
    _day = day;
}

// d2(d1)
Date::Date(const Date& d)
{
    _year = d._year;
    _month = d._month;
    _day = d._day;
}

// d2 = d3 -> d2.operator=(&d2, d3)
Date& Date::operator=(const Date& d)
{
    _year = d._year;
    _month = d._month;
    _day = d._day;
    return *this;
}

Date::~Date()
{
    _year = 0;
    _month = 0;
    _day = 0;
}

Date& Date::operator+=(int day)
{
    _day += day;
    while(_day > GetMonthDay(_year, _month))
    {
        _day -= GetMonthDay(_year, _month);
        _month++;
        if(_month == 13)
        {
            _year++;
            _month = 1;
        }
    }
    return *this;
}

Date Date::operator+(int day)
{
    //Date tmp(*this);
    Date tmp = *this;
    // tmp.operator+=(day);
    tmp += day;
    return tmp;
}

Date Date::operator-(int day)
{
    // Date tmp(*this)
    Date tmp = *this;
    // tmp.operator-=(day);
    tmp -= day;
    return tmp;
}

Date& Date::operator-=(int day)
{
    _day -= day;
    while(_day < 0)
    {
        --_month;
        if(_month == 0)
        {
            _month = 12;
            --_year;
        }
        _day += GetMonthDay(_year, _month);
    }
    return *this;
}

Date& Date::operator++()
{
    *this += 1;
    return *this;
}   

Date Date::operator++(int)
{
    // Date tmp(*this);
    Date tmp = *this;
    *this += 1;
    return tmp;
}

Date Date::operator--(int)
{
    Date tmp = *this;
    *this -= 1;
    return tmp;
}

Date& Date::operator--()
{
    *this -= 1;
    return *this;
}

bool Date::operator>(const Date& d)
{
    if(_year > d._year)
        return true;
    else if(_year < d._year)
        return false;
    else{
        if(_month > d._month)
            return true;
        else if(_month < d._month)
            return false;
        else{
            if(_day > d._day)
                return true;
            return false;
        }
    }
}

bool Date::operator==(const Date& d)
{
    return (_year == d._year && _month == d._month && _day == d._day);
}

bool Date::operator >= (const Date& d)
{
    return (*this > d || *this == d);
}

bool Date::operator < (const Date& d)
{
    return !(*this >= d);
}

bool Date::operator <= (const Date& d)
{
    return !(*this > d);
}

bool Date::operator != (const Date& d)
{
    return !(*this == d);
}

int operator-(const Date& d);
