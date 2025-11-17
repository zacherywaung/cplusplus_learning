#include"../include/test.h"

typedef int STDataType;

class Date
{
public:
    // //无参构造函数
    // Date()
    // {
    //     _year = 1;
    //     _month = 1;
    //     _day = 1;
    // }
    // //带参构造函数
    // Date(int year, int month, int day)
    // {
    //     _year = year;
    //     _month = month;
    //     _day = day;
    // }
    //全缺省构造函数
    Date(int year = 2000, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    void PrintDate()
    {
        cout << this->_year << "/" << this->_month << "/" << this->_day << endl;
    }

private:
    int _year;
    int _month;
    int _day;
};

class Stack
{
public:
    Stack(int n = 4)
    {
        _a = (STDataType*)malloc(sizeof(STDataType) * n);
        if(nullptr == _a)
        {
            perror("malloc fail");
            exit(1);
        }
        _top = 0;
        _capacity = n;
    }

    ~Stack()
    {
        cout << "~Stack()" << endl;
        free(_a);
        _a = nullptr;
        _top = _capacity = 0;
    }

    void Push(STDataType x)
    {
        //extend the capacity
        if(_top == _capacity)
        {
            int newcapacity = _capacity * 2;
            STDataType* tmp = (STDataType*)realloc(_a, sizeof(STDataType)*newcapacity);
            if(nullptr == tmp)
            {
                perror("realloc fail");
                exit(1);
            }
            _a = tmp;
            _capacity = newcapacity;
        }
        _a[_top] = x;
        _top++;
    }

    void Pop()
    {
        assert(_top > 0);
        _top--;
    }

    int Top()
    {
        assert(_top > 0);
        return _a[_top - 1];
    }

    bool IsEmpty()
    {
        return _top == 0;
    }

private:
    STDataType* _a;
    int _top;
    int _capacity;
};

class MyQueue
{
public:
private:
    Stack _stack1;
    Stack _stack2;
};




int main()
{
    Date d1(2025, 11);
    Date d2;
    d1.PrintDate();
    d2.PrintDate();
    Stack st(8);
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st.Push(4);
    st.Push(5);

    while(! st.IsEmpty())
    {
        cout << st.Top() << endl;
        st.Pop();
    }

    MyQueue mq;
    cout << zw::a + zw::b << endl; 
    return 0;
}