//HJ_73 计算日期到天数的转换
//对应输入的日期，计算这是这一年的第几天。
//在一行上输入三个整数 a,b,c(1900≦a≦2200)a,b,c(1900≦a≦2200)，分别代表年、月、日。保证输入的日期是合法的
//输出一个整数，代表输入的日期是这一年的第几天。

#include <iostream>
using namespace std;

class Date
{
public:
    Date(int a, int b, int c)
        :_year(a)
        ,_month(b)
        ,_day(c)
        ,_ret(0)
    {}
    int GetMonthDay(int year, int month)
    {
        int montharray[13] = {0, 31, 28, 31, 30, 31, 
        30, 31, 31, 30, 31, 30, 31};
        if(month == 2 && ((year % 4 == 0 && year % 100 != 0)
        || year % 400 == 0))
        {
            return 29;
        }
        return montharray[month];
    }

    int GetRet()
    {
        int i = 0;
        for(i = 1; i < _month; i++)
        {
            _ret += GetMonthDay(_year, i);
        }
        return (_ret + _day);
    }

private:
    int _year = 1900;
    int _month = 1;
    int _day = 1;
    int _ret = 0;
};

int main() {
    int a, b, c;
    while (cin >> a >> b >> c) { // 注意 while 处理多个 case
        cout << Date(a, b, c).GetRet() << endl;
    }
}