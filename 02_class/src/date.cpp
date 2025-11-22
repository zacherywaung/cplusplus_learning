#include"../include/date.h"

void Date::PrintDate()
{
    cout << _year << "/" << _month << "/" << _day << endl;
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

bool Date::operator>(const Date& d) const
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

bool Date::operator==(const Date& d) const
{
    return (_year == d._year && _month == d._month && _day == d._day);
}

bool Date::operator >= (const Date& d) const
{
    return (*this > d || *this == d);
}

bool Date::operator < (const Date& d) const
{
    return !(*this >= d);
}

bool Date::operator <= (const Date& d) const
{
    return !(*this > d);
}

bool Date::operator != (const Date& d) const
{
    return !(*this == d);
}

Date* Date::operator&()
{
    return this;
}

const Date* Date::operator&() const
{
    return this;
}

int Date::operator-(const Date& d)
{
    int n = 0;
    int flag = -1;
    Date min = *this;
    Date max = d;
    if(min > max)
    {
        min = d;
        max = *this;
        flag = 1;
    }
    while(min != max)
    {
        min++;
        n++;
    }
    return flag*n;
}

ostream& operator<<(ostream& out, const Date& d)
{
    out << d._year << "/" << d._month << "/" << d._day << endl;
    return out;
}


istream& operator>>(istream& in, Date& d)
{
    cout << "please enter date: ";
    in >> d._year >> d._month >> d._day;
    return in;
}