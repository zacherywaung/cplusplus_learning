#pragma once
#include<deque>

namespace zw
{
    template<class T, class Container = std::deque<T>>
    class stack
    {
    public:
        stack()
        {}

        void push(const T& x)
        {
            con.push_back(x);
        }

        void pop()
        {
            con.pop_back();
        }

        const T& top() const
        {
            return con.back();
        }

        size_t size() const
        {
            return con.size();
        }

        bool empty() const
        {
            return con.empty();
        }

    private:
        Container con;
    };
}