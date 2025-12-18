#pragma once
#include<vector>

namespace zw
{
    template<class T>
    class less
    {
    public:
        bool operator()(const T& x, const T& y)
        {
            return x < y;
        }
    };

    template<class T>
    class greater
    {
    public:
        bool operator()(const T& x, const T& y)
        {
            return x > y;
        }
    };

    template <class T, class Container = std::vector<T>, class Compare = less<T> >
    class priority_queue
    {
    public:
    priority_queue()
    {}

    template <class InputIterator>
    priority_queue(InputIterator first, InputIterator last)
    {
        while(first != last)
        {
            con.push_back(*first);
            ++first;
        }
        int parent = (con.size() - 2) / 2;
        while(parent >= 0)
        {
            AdjustDown(parent);
            --parent;
        }
    }

    bool empty() const
    {
        return con.empty();
    }

    size_t size() const
    {
        return con.size();
    }

    const T& top() const
    {
        return con.front();
    }

    void push(const T& x)
    {
        con.push_back(x);
        AdjustUp(con.size() - 1);
    }

    void pop()
    {
        std::swap(con[0], con[con.size() - 1]);
        con.pop_back();
        AdjustDown(0);
    }

    private:
        void AdjustDown(int parent)
        {
            Compare comp;
            int child = parent * 2 + 1;
            while(child < con.size())
            {
                // if(child + 1 < con.size() && con[child] < con[child + 1])
                if(child + 1 < con.size() && comp(con[child], con[child + 1]))
                {
                    ++child;
                }
                // if(con[parent] < con[child])
                if(comp(con[parent], con[child]))
                {
                    std::swap(con[parent], con[child]);
                    parent = child;
                    child = parent * 2 + 1;
                }
                else{
                    break;
                }
            }
        }

        void AdjustUp(int child)
        {
            Compare comp;
            while(child > 0)
            {
                int parent = (child - 1) / 2;
                // if(con[child] > con[parent])
                if(comp(con[parent], con[child]))
                {
                    std::swap(con[child], con[parent]);
                    child = parent;
                }
                else{
                    break;
                }
            }
        }

    private:
        Container con;
    };
}