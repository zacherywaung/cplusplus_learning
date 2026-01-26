#include<iostream>
using namespace std;

namespace zw
{
    class MyException : public exception
    {
    protected:
        string _msg;
    public:
        MyException(const string& msg)
            :_msg(msg)
        {}
        const char* what() const noexcept override
        {
            return _msg.c_str();
        }
    };

    double Devide(int x, int y)
    {
        if(y == 0)
        {
            throw  MyException("Devide by zero");
        }
        return double(x) / double(y);
    }
}

int main()
{
    while(1)
    {
        try
        {
            int x, y;
            cin >> x >> y;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                throw zw::MyException("Invalid arguments");
            }
            cout << zw::Devide(x, y) << endl;
        }
        catch(const exception& e)
        {
            cout << e.what() << endl;
        }
        catch(...)
        {
            cout << "Unknown Exception" << endl;
        }
         
    }
    return 0;
}