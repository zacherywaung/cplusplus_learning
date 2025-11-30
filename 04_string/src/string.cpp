#include"../include/string.h"

namespace zw
{
    void string::reserve(size_t n)
    {
        if(n > _capacity)
        {
            char* tmp = new char[n + 1];
            strcpy(tmp, _str);
            delete[] _str;
            _str = tmp;
            _capacity = n;
        }
    }

    void string::push_back(char c)
    {
        if(_size == _capacity)
        {
            reserve(_capacity == 0? 4 : 2*_capacity);
        }
        _str[_size] = c;
        _size++;
        _str[_size] = '\0';
    }

    string& string::operator+=(char c)
    {
        push_back(c);
        return *this;
    }

    void string::append(const char* str)
    {
        size_t len = strlen(str);
        if(_size + len > _capacity)
        {
            reserve(_size + len > 2 * _capacity ? (_size + len) : (2 * _capacity));
        }
        strcpy(_str + _size, str);
        _size += len;
    }

    string& string::operator+=(const char* str)
    {
        append(str);
        return *this;
    }

    void string::clear()
    {
        _str[0] = '\0';
        _size = 0;
    }

    void string::swap(string& s)
    {
        //swap _str
        char* tmp_str = _str;
        _str = s._str;
        s._str = tmp_str;

        //swap _size
        size_t tmp_size = _size;
        _size = s._size;
        s._size = tmp_size;

        //swap _capacity
        size_t tmp_capacity = _capacity;
        _capacity = s._capacity;
        s._capacity = tmp_capacity;
    }

    const char* string::c_str()const
    {
        return _str;
    }
}