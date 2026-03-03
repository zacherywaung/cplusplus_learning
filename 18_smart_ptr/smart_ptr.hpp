#ifndef __SMART_PTR_HPP__
#define __SMART_PTR_HPP__

#include <iostream>

namespace SmartPtrModule
{
    template <class T>
    class unique_ptr
    {
    public:
        explicit unique_ptr(T *ptr = nullptr)
            : _ptr(ptr)
        {}

        T& operator*()
        {
            return *_ptr;
        }

        T* operator->()
        {
            return _ptr;
        }

        unique_ptr(const unique_ptr<T>& o) = delete;

        unique_ptr<T>& operator=(const unique_ptr<T>& o) = delete;

        unique_ptr(unique_ptr<T>&& o)
            :_ptr(o._ptr)
        {
            o._ptr = nullptr;
        }

        unique_ptr<T>& operator=(unique_ptr<T>&& o)
        {
            if(this != &o)
            {
                std::swap(_ptr, o._ptr);
            }
            return *this;
        }

        ~unique_ptr()
        {
            if(_ptr)
            {
                delete _ptr;
            }
        }

    private:
        T *_ptr;
    };

    template<class T>
    class shared_ptr
    {
    public:
        explicit shared_ptr(T* ptr = nullptr)
            :_ptr(ptr)
            ,_pcount(new int(1))
        {}

        shared_ptr(const shared_ptr<T>& o)
            :_ptr(o._ptr)
            ,_pcount(o._pcount)
        {
            (*_pcount)++;
        }

        shared_ptr<T>& operator=(const shared_ptr<T>& o)
        {
            if(_ptr != o._ptr)
            {
                (*_pcount)--;
                if(*_pcount == 0)
                {
                    delete _ptr;
                    delete _pcount;
                }
                _ptr = o._ptr;
                _pcount = o._pcount;
                (*_pcount)++;
            }
            return *this;
        }

        T& operator*()
        {
            return *_ptr;
        }

        T* operator->()
        {
            return _ptr;
        }

        ~shared_ptr()
        {
            (*_pcount)--;
            if(*_pcount == 0)
            {
                delete _ptr;
                delete _pcount;
            }
        }
    private:
        T* _ptr;
        int* _pcount;
    };

}

#endif