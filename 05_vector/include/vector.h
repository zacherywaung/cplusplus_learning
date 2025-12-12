#include<iostream>
#include<assert.h>
using namespace std;

namespace zw
{
  template<class T>
  class vector
  {
  public:
    // iterator is a pointer
    typedef T* iterator;
    typedef const T* const_iterator;

    iterator begin()
    {
        return _start;
    }

    iterator end()
    {
        return _finish;
    }

    const_iterator cbegin()const
    {
        return _start;
    }

    const_iterator cend()const
    {
        return _finish;
    }


    // construct and destroy

    vector()
        :_start(nullptr)
        ,_finish(nullptr)
        ,_end_of_storage(nullptr)
    {}

    vector(int n, const T& value = T())
    {
        assert(n > 0);
        _start = new T[n];
        for(int i = 0; i < n; i++)
        {
            _start[i] = value;
        }
        _finish = _end_of_storage = _start + n;
    }

    // template<class InputIterator>
    // vector(InputIterator first, InputIterator last)
    // {
    //     size_t n = 0;
    //     for(InputIterator it = first; it != last; it++)
    //     {
    //         n++;
    //     }
    //     _start = new T[n];
    //     _finish = _end_of_storage = _start + n;
    //     T* dest = _start;
    //     while(dest != _finish)
    //     {
    //         *dest = *first;
    //         ++dest;
    //         ++first;
    //     }
    // }

    template<class InputIterator>
    vector(InputIterator first, InputIterator last)
    {
        while(first != last)
        {
            push_back(*first);
            ++first;
        }
    }

    // vector(const vector<T>& v)
    // {
    //     reserve(v.capacity());
    //     for(auto& e : v)
    //     {
    //         push_back(e);
    //     }
    // }

    vector(const vector<T>& v)
    {
        vector<T> tmp(v._start, v._finish);
        swap(tmp);
    }

    void clear()
    {
        _finish = _start;
    }

    // vector<T>& operator= (vector<T> v)
    // {
    //     if(this != &v)
    //     {
    //         clear();
    //         reserve(v.size());
    //         for(auto& e : v)
    //         {
    //             push_back(e);
    //         }
    //     }
    //     return *this;
    // }

    // vector<T>& operator= (vector<T> v)
    // {
    //     vector<T> tmp(v._start, v._finish);
    //     swap(tmp);
    //     return *this;
    // }

    vector<T>& operator= (vector<T> v)
    {
        swap(v);
        return *this;
    }

    ~vector()
    {
        if(_start)
        {
            delete[] _start;
            _start = _finish = _end_of_storage = nullptr;
        }
    }

    // capacity

    size_t size() const
    {
        return _finish - _start;
    }

    size_t capacity() const
    {
        return _end_of_storage - _start;
    }

    void reserve(size_t n)
    {
        if(n > capacity())
        {
            T* tmp = new T[n];
            size_t old_size = size();
            for(size_t i = 0; i < old_size; i++)
            {
                tmp[i] = _start[i];
            }
            delete[] _start;
            _start = tmp;
            _finish = tmp + old_size;
            _end_of_storage = tmp + n;
        }
    }

    void resize(size_t n, const T& value = T())
    {
        if(n <= _finish - _start)
        {
            _finish = _start + n;
        }
        else{
            if(n > size())
            {
                reserve(n);
            }
            while(_finish != _start + n)
            {
                *_finish = value;
                ++_finish;
            }
        }
    }



    ///////////////access///////////////////////////////

    T& operator[](size_t pos)
    {
        return _start[pos];
    }

    const T& operator[](size_t pos)const
    {
        return _start[pos];
    }

    ///////////////modify/////////////////////////////

    void push_back(const T& x)
    {
        if(_finish == _end_of_storage)
        {
            reserve(capacity() == 0 ? 4 : 2*capacity());
        }
        *_finish = x;
        _finish++;
    }

    void pop_back()
    {
        assert(!empty());
        _finish--;
    }

    bool empty()
    {
        return _start == _finish;
    }

    void swap(vector<T>& v)
    {
        std::swap(_start, v._start);
        std::swap(_finish, v._finish);
        std::swap(_end_of_storage, v._end_of_storage);
    }

    iterator insert(iterator pos, const T& x)
    {
        if(_finish == _end_of_storage)
        {
            size_t len = pos - _start;
            reserve(capacity() == 0 ? 4 : 2*capacity());
            pos = _start + len;
        }
        T* end = _finish - 1;
        for(end = _finish - 1; end >= pos; end--)
        {
            *(end + 1) = *end;
        }
        *pos = x;
        ++_finish;
        return pos;
    }

    iterator erase(iterator pos)
    {
        assert(pos < _finish);
        T* key = pos;
        while(key + 1 < _finish)
        {
            *key = *(key + 1);
            key++;
        }
        --_finish;
        return pos;
    }

    void print_vector()
    {
        for(size_t i = 0; i < size(); i++)
        {
            cout << _start[i] << " ";
        }
        cout << endl;
    }

  private:

    iterator _start = nullptr;

    iterator _finish = nullptr;

    iterator _end_of_storage = nullptr;
  };
}