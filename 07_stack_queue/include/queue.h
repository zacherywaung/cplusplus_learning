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

        void push()
        {
            ;
        }

    private:
        Container con;
    }
}