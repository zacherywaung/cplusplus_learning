#include"../include/string.h"

namespace zw
{
    const size_t string::npos = -1;

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

    size_t string::find(char c, size_t pos)const
    {
        assert(pos < _size);
        for(size_t i = pos; i < _size; i++)
        {
            if(_str[i] == c)
            {
                return i;
            }
        }
        return npos;
    }

    size_t string::find(const char* s, size_t pos)const
    {
        assert(pos < _size);
        char* ptr = strstr(_str + pos, s);
        if(ptr == nullptr)
        {
            return npos;
        }
        return ptr - _str;
    }

    string& string::insert(size_t pos, char c)
    {
        assert(pos <= _size);
        if(_size == _capacity)
        {
            reserve(_capacity == 0 ? 4 : 2 * _capacity);

        }
        size_t end = _size + 1;
        while(end > pos)
        {
            _str[end] = _str[end - 1];
            end--;
        }
        _str[pos] = c;
        ++_size;
        return *this;
    }

    string& string::insert(size_t pos, const char* str)
    {
        assert(pos <= _size);
        size_t len = strlen(str);
        if(_size + len > _capacity)
        {
            reserve(_size + len > _capacity * 2 ? _size + len : _capacity * 2);
        }
        size_t end = _size + len;
        while(end > pos + len - 1)
        {
            _str[end] = _str[end - len];
            end--;
        }
        for(size_t i = 0; i < len; i++)
        {
            _str[pos + i] = str[i];
        }
        _size += len;
        return *this;
    }

    string& string::erase(size_t pos, size_t len)
    {
        assert(pos < _size);
        assert(len >= 0);
        if(pos + len >= _size)
        {
            _str[pos] = '\0';
            _size = pos;
        }
        else{
            for(size_t i = pos + len; i <= _size; i++)
            {
                _str[i - len] = _str[i];
            }
            _size -= len;
        }
        return *this;
    }

    string string::substr(size_t pos, size_t len)
    {
        assert(pos < _size);
        if(len > _size - pos)
        {
            len = _size - pos;
        }
        string sub;
        sub.reserve(len);
        size_t i = 0;
        for(i = pos; i < pos + len; i++)
        {
            sub += _str[i];
        }
        return sub;
    }

    ostream& operator<<(ostream& _cout, const string& s)
    {
        for(auto ch : s)
        {
            _cout << ch;
        }
        return _cout;
    }

    istream& operator>>(istream& _cin, string& s)
    {
        s.clear();
        const int N = 256;
        char buff[N];
        char ch = _cin.get();
        int i = 0;
        while(ch != ' ' && ch != '\n')
        {
            buff[i++] = ch;
            if(i == N - 1)
            {
                buff[i] = '\0';
                s += buff;
                i = 0;
            }
            ch = _cin.get();
        }
        if(i > 0)
        {
            buff[i] = '\0';
            s += buff;
        }
        return _cin;
    }

    bool operator<(const string& s1, const string& s2)
    {
        return strcmp(s1.c_str(), s2.c_str()) < 0;
    }

    bool operator==(const string& s1, const string& s2)
    {
        return strcmp(s1.c_str(), s2.c_str()) == 0;
    }

    bool operator<=(const string& s1, const string& s2)
    {
        return s1 < s2 || s1 == s2;
    }

    bool operator>(const string& s1, const string& s2)
    {
        return !(s1 <= s2);
    }

    bool operator>=(const string& s1, const string& s2)
    {
        return !(s1 < s2);
    }

    bool operator!=(const string& s1, const string& s2)
    {
        return !(s1 == s2);
    }


}