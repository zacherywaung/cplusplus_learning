#include<iostream>
#include<functional>

namespace zw
{
    void _Print()
    {
        std::cout << std::endl;
    }

    template<class T, class ...Args>
    void _Print(T&& x, Args&&... args)
    {
        std::cout << x << " ";
        _Print(std::forward<Args>(args)...);
    }

    template<class ...Args>
    void Print1(Args&&... args)
    {
        _Print(std::forward<Args>(args)...);
    }


    template<class T>
    int getArgs(T&& x)
    {
        std::cout << x << " ";
        return 0;
    }

    template<class ...Args>
    void Arguments(Args&&... args){}

    template<class ...Args>
    void Print2(Args&&... args)
    {
        Arguments(getArgs(std::forward<Args>(args))...);
        std::cout << std::endl;
    }

}

void TestArgs()
{
    int i = 3;
    zw::Print1(1, std::string("xxxx"), 2.2, 'c', i);
    zw::Print2(1, std::string("xxxx"), 2.2, 'c', i);
}

void TestLambda()
{
    int a = 1, b = 1, c = 1;
    auto func1 = [](int a, int b, int c)->int
    {
        return a + b + c;
    };
    std::cout << "func1 : " << func1(a, b, c) << std::endl;

    auto func2 = [a, b, c]
    {
        return a + b + c;
    };
    std::cout << "func2 : " << func2() << std::endl;

    auto func3 = [=]
    {
        return a + b + c;
    };
    std::cout << "func3 : " << func3() << std::endl;

    auto func4 = [&]
    {
        a++;
        b++;
        c++;
        return a + b + c;
    };
    std::cout << "func4 : " << func4() << std::endl;
    std::cout << "a = " << a << " b = " << b << " c = " << c << std::endl;

    auto func5 = [=, &c]
    {
        c++;
        return a + b + c;
    };
    std::cout << "func5 : " << func5() << std::endl;
    std::cout << "a = " << a << " b = " << b << " c = " << c << std::endl;

}

namespace zw
{
    int f(int a, int b)
    {
        return a + b;
    }

    struct Functor
    {
        int operator()(int a, int b)
        {
            return a + b;
        }
    };

    class Plus
    {
    public:
        Plus() = default;
        static int plus1(int a, int b)
        {
            return a + b;
        }

        double plus2(double a, double b)
        {
            return a + b;
        }
    };

}

using std::placeholders::_1;
using std::placeholders::_2;

void TestFunction()
{
    std::function<int(int, int)> f1 = zw::f;
    std::function<int(int, int)> f2 = zw::Functor();
    std::function<int(int, int)> f3 = [](int a, int b)->int{return a + b;};
    std::function<int(int, int)> f4 = &zw::Plus::plus1;
    std::function<double(zw::Plus*, double, double)> f5 = &zw::Plus::plus2;
    std::function<double(zw::Plus, double, double)> f6 = &zw::Plus::plus2;
    std::function<double(double, double)> f7 = std::bind(&zw::Plus::plus2, zw::Plus(), _1, _2);


    std::cout << "function pointer: " << f1(1, 2) << std::endl;
    std::cout << "functor: " << f2(1, 2) << std::endl;
    std::cout << "lambda: " << f3(1, 2) << std::endl;
    std::cout << "static method in object: " <<f4(1, 2) << std::endl;
    zw::Plus plus;
    std::cout << "method in object(pointer): " <<f5(&plus, 1, 2) << std::endl;
    std::cout << "method in object(object): " <<f6(zw::Plus(), 1, 2) << std::endl;
    std::cout << "method in object(use bind): " <<f7(1, 2) << std::endl;

}


int main()
{
    //TestArgs();
    //TestLambda();
    TestFunction();
    return 0;
}