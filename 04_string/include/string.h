#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace zw
{
    class string
    {

        friend ostream& operator<<(ostream& _cout, const zw::string& s);

        friend istream& operator>>(istream& _cin, zw::string& s);

    public:

        typedef char* iterator;

    public:

        string(const char* str = "")
        {
            _size = strlen(str);
            _capacity = _size; // not include \0
            _str = new char[_capacity + 1]; // include \0
            strcpy(_str, str);
        }

        string(const string& s)
        {
            _size = s._size;
            _capacity = s._capacity;
            _str = new char[s._capacity + 1];
            strcpy(_str, s._str);
        }

        string& operator=(const string &s)
        {
            _size = s._size;
            _capacity = s._capacity;
            _str = new char[s._capacity + 1];
            strcpy(_str, s._str);
            return *this;
        }

        ~string()
        {
            _size = _capacity = 0;
            delete[] _str;
            _str = nullptr;
        }


        //////////////////////////////////////////////////////////////

        // iterator

        iterator begin()
        {
            return _str;
        }

        iterator end()
        {
            return _str + _size;
        }



        /////////////////////////////////////////////////////////////

        // modify

        void push_back(char c);

        string& operator+=(char c);

        void append(const char* str);

        string& operator+=(const char* str);

        void clear();

        void swap(string& s);

        const char* c_str()const;



        /////////////////////////////////////////////////////////////

        // capacity

        size_t size()const
        {
            return _size;
        }

        size_t capacity()const
        {
            return _capacity;
        }

        bool empty()const
        {
            return _size == 0;
        }

        void resize(size_t n, char c = '\0')
        {
            if(_size > n)
            {
                _size = n;
                _str[n] = '\0';
            }
            else if(_size < n)
            {
                if(n > _capacity)
                {
                    reserve(n);
                }
                int i = 0;
                for(i = _size; i < n; i++)
                {
                    _str[i] = c;
                }
                _str[i] = '\0';
                _size = n;
            }
        }

        void reserve(size_t n);

        /////////////////////////////////////////////////////////////

        // access

        char& operator[](size_t index)
        {
            return _str[index];
        }

        const char& operator[](size_t index)const
        {
            return _str[index];
        }



        /////////////////////////////////////////////////////////////

        //relational operators

        bool operator<(const string& s);

        bool operator<=(const string& s);

        bool operator>(const string& s);

        bool operator>=(const string& s);

        bool operator==(const string& s);

        bool operator!=(const string& s);



        // 返回c在string中第一次出现的位置

        size_t find (char c, size_t pos = 0) const;

        // 返回子串s在string中第一次出现的位置

        size_t find (const char* s, size_t pos = 0) const;

        // 在pos位置上插入字符c/字符串str，并返回该字符的位置

        string& insert(size_t pos, char c);

        string& insert(size_t pos, const char* str);

        

        // 删除pos位置上的元素，并返回该元素的下一个位置

        string& erase(size_t pos, size_t len);

    private:

        char* _str;

        size_t _capacity;

        size_t _size;

    };

}