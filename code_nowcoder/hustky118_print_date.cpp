// HUSTKY118_打印日期
// 给出年分m和一年中的第n天，算出第n天是几月几号。
// 输入描述：
// 输入包括两个整数y(1<=y<=3000)，n(1<=n<=366)。
// 输出描述：
// 可能有多组测试数据，对于每组数据， 按 yyyy-mm-dd的格式将输入中对应的日期打印出来。
// 输入：
// 2000 3
// 2000 31
// 2000 40
// 2000 60
// 2000 61
// 2001 60
// 输出：
// 2000-01-03
// 2000-01-31
// 2000-02-09
// 2000-02-29
// 2000-03-01
// 2001-03-01
#include <climits>
#include <iostream>
#include <string>
using namespace std;

class Date {
  public:
    Date(int year, int x)
        : _year(year)
        , _x(x)
    {}

    int GetMonthDay(int year, int month) {
        int monthArray[] = {-1, 31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31
                           };
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0)
                           || (year % 400 == 0)) ) {
            return 29;
        }
        return monthArray[month];
    }
    void CalculateDay() {
        int day = 0;
        day += _x;
        int month = 1;
        while (day > GetMonthDay(_year, month)) {
            day -= GetMonthDay(_year, month);
            ++month;
        }
        string str_month = month < 10 ? "0" + to_string(month) : "" + to_string(month);
        string str_day = day < 10 ? "0" + to_string(day) : "" + to_string(day);

        cout << _year << "-" << str_month << "-" << str_day << endl;

    }

  private:
    int _year = 1900;
    int _x = 0;
};

int main() {
    int year;
    int x;
    while (cin >> year >> x) {
        Date(year, x).CalculateDay();
    }
}