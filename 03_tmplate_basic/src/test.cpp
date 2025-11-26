#include<iostream>
using namespace std;

//函数模版
template<class T>
void Swap(T& x, T& y)
{
    T tmp = x;
    x = y;
    y = tmp;
}

//类模版
template<class T>
class Stack
{
public:
    Stack(int n = 4)
        :_array(new T[n])
        ,_size(0)
        ,_capacity(n)
    {}

    ~Stack()
    {
        delete[] _array;
        _array = nullptr;
        _size = _capacity = 0;
    }

    void Push(const T& x)
    {
        if(_size == _capacity)
        {
            T* tmp = new T[_capacity*2];
            memcpy(tmp, _array, _size);
            delete[] _array;
            _array = tmp;
            _capacity *= 2;
        }
        _array[_size] = x;
        ++_size;
    }

    void Pop()
    {
        _size--;
    }

    const T& Top()
    {
        return _array[_size - 1];
    }

    bool Isempty()
    {
        return _size == 0;
    }

private:
    T* _array;
    int _size;
    int _capacity;
};


int main()
{
    int x = 10;
    int y = 20;
    Swap<int>(x,y);
    cout << x << "//" << y << endl;

    Stack<int> st;
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st.Push(4);
    st.Pop();
    while(!st.Isempty())
    {
        cout << st.Top() << endl;
        st.Pop();
    }

}