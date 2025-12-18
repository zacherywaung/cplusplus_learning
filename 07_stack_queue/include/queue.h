#pragma once
#include<deque>

namespace zw
{
    template<class T, class Container = std::deque<T>>
    class queue
    {
    public:
        queue()
        {}

        void push(const T& x)
        {
            con.push_back(x);
        }

        void pop()
        {
            con.pop_front();
        }

        const T& top() const
        {
            return con.front();
        }

        size_t size()
        {
            return con.size();
        }

        bool empty()
        {
            return con.empty();
        }

    private:
        Container con;
    };
}