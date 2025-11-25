// KY257_日期累加
// 描述
// 设计一个程序能计算一个日期加上若干天后是什么日期。
// 输入描述：
// 输入第一行表示样例个数m，接下来m行每行四个整数分别表示年月日和累加的天数。
// 输出描述：
// 输出m行，每行按yyyy-mm-dd的个数输出。
// 输入：
// 1
// 2008 2 3 100
// 输出：
// 2008-05-13
#include <climits>
#include <iostream>
#include <string>
using namespace std;

class Date
{
public:
    Date(int year, int month, int day, int x)
        :_year(year)
        ,_month(month)
        ,_day(day)
        ,_x(x)
    {}

    int GetMonthDay(int year, int month)
    {
        int monthArray[] = {-1, 31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31};
        if(month == 2 && ((year % 4 == 0 && year %100!=0)
        || (year % 400 == 0)) )
        {
            return 29;
        }
        return monthArray[month];
    }
    void CalculateDay()
    {
        _day += _x;
        while(_day > GetMonthDay(_year, _month))
        {
            _day -= GetMonthDay(_year, _month);
            ++_month;
            if(_month == 13)
            {
                _month = 1;
                ++_year;
            }
        }
        string str_month = _month < 10 ? "0" + to_string(_month) : "" + to_string(_month);
        string str_day = _day < 10 ? "0" + to_string(_day) : "" + to_string(_day);

        cout << _year << "-" << str_month << "-" << str_day << endl;
        
    }

private:
    int _year = 1900;
    int _month = 1;
    int _day = 1;
    int _x = 0;
};

int main() {
    int m;
    int year;
    int month;
    int day;
    int x;
    cin >> m;
    while (cin >> year >> month >> day >> x) {
        Date(year, month, day, x).CalculateDay();
    }
}
