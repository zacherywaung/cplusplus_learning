#include"../include/basic.h"
//using namespace std;

namespace zw
{
    namespace wz
    {
        int a = 10;
        double b = 10.5;
        char c = 'a';
    }
    double x = 2.5;
    double y = 3.5;
}

void Swap(int& rx, int& ry)
{
    int tmp = rx;
    rx = ry;
    ry = tmp;
}

void Swap(double& rx, double& ry)
{
    double tmp = rx;
    rx = ry;
    ry = tmp;
}

int main()
{
    std::cout << zw::wz::a << ' ' << zw::wz::b << ' ' << zw::wz::c << std::endl;
    int x = 2;
    int y = 8;
    Swap(x, y);
    Swap(zw::x, zw::y);
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "zw::x = " << zw::x << std::endl;
    std::cout << "zw::y = " << zw::y << std::endl;

    return 0;
}