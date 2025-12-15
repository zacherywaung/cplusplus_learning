#pragma once

#include<iostream>
#include<assert.h>
using namespace std;


namespace zw
{
    // List的节点类
    template<class T>
    struct ListNode
    {
        ListNode(const T& val = T())
            :_val(val)
            ,_prev(nullptr)
            ,_next(nullptr)
        {}

        T _val;
        ListNode<T>* _prev;
        ListNode<T>* _next;
    };


    //List的迭代器类
    template<class T, class Ref, class Ptr>
    struct ListIterator
    {
        typedef ListNode<T>* Node;
        typedef ListIterator<T, Ref, Ptr> Self;

        ListIterator(Node pnode = nullptr)
            :_pnode(pnode)
        {}

        ListIterator(const Self& l)
        {
            _pnode = l._pnode;
        }

        Ref operator*()
        {
            return _pnode->_val;
        }

        Ptr operator->()
        {
            return &(_pnode->_val);
        }

        Self& operator++()
        {
            _pnode = _pnode->_next;
            return *this;
        }

        Self operator++(int)
        {
            Self tmp = *this;
            _pnode = _pnode->_next;
            return tmp;
        }

        Self& operator--()
        {
            _pnode = _pnode->_prev;
            return *this;
        }

        Self operator--(int)
        {
            Self tmp = *this;
            _pnode = _pnode->_prev;
            return tmp;
        }

        bool operator!=(const Self& l) const
        {
            return _pnode != l._pnode;
        }
        bool operator==(const Self& l) const
        {
            return _pnode == l._pnode;
        }


        Node _pnode;
    };


    //list类
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
        typedef Node* PNode;
    public:
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T*> const_iterator;
    public:
        ///////////////////////////////////////////////////////////////
        // List的构造
        void empty_init()
        {
            _head = new Node;
            _head->_next = _head;
            _head->_prev = _head;
            _size = 0;
        }

        list()
        {
            empty_init();
        }

        list(int n, const T& value = T())
        {
            empty_init();
            while(n != 0)
            {
                push_back(value);
                n--;
            }
        }

        template <class Iterator>
        list(Iterator first, Iterator last)
        {
            empty_init();
            while(first != last)
            {
                push_back(*first);
                ++first;
            }
        }

        list(const list<T>& l)
        {
            empty_init();
            for(auto& e : l)
            {
                push_back(e);
            }
        }

        list<T>& operator=(list<T> l)
        {
            swap(l);
            return *this;
        }


        ~list()
        {
            clear();
            delete _head;
            _head = nullptr;
        }


        ///////////////////////////////////////////////////////////////
        // List Iterator
        iterator begin()
        {
            return iterator(_head->_next);
        }
        iterator end()
        {
            return iterator(_head);
        }
        const_iterator begin() const
        {
            return const_iterator(_head->_next);
        }
        const_iterator end() const
        {
            return const_iterator(_head);
        }


        ///////////////////////////////////////////////////////////////
        // List Capacity
        size_t size()const
        {
            return _size;
        }
        bool empty()const
        {
            return _size == 0;
        }


        ////////////////////////////////////////////////////////////
        // List Access
        T& front()
        {
            return _head->_next->_val;
        }
        const T& front()const
        {
            return _head->_next->_val;
        }
        T& back()
        {
            return _head->_prev->_val;
        }
        const T& back()const
        {
            return _head->_prev->_val;
        }


        ////////////////////////////////////////////////////////////
        // List Modify
        void push_back(const T& val) { insert(end(), val); }
        void pop_back() { erase(--end()); }
        void push_front(const T& val) { insert(begin(), val); }
        void pop_front() { erase(begin()); }
        // 在pos位置前插入值为val的节点
        iterator insert(iterator pos, const T& val)
        {
            Node* cur = pos._pnode;
            Node* prev = cur->_prev;
            Node* newnode = new Node(val);
            newnode->_next = cur;
            newnode->_prev = prev;
            prev->_next = newnode;
            cur->_prev = newnode;
            ++_size;
            return iterator(newnode);
        }
        // 删除pos位置的节点，返回该节点的下一个位置
        iterator erase(iterator pos)
        {
            assert(pos._pnode != _head);
            Node* prev = pos._pnode->_prev;
            Node* cur = pos._pnode->_next;
            prev->_next = cur;
            cur->_prev = prev;
            delete pos._pnode;
            _size--;
            return iterator(cur);
        }
        void clear()
        {
            auto it = begin();
            while(it != end())
            {
                it = erase(it);
            }
        }

        void swap(list<T>& l)
        {
            std::swap(_head, l._head);
            std::swap(_size, l._size);
        }


    private:

        Node* _head;
        size_t _size;
    };

    template<class Container>
        void PrintContainer(const Container& con)
        {
            typename Container::const_iterator it = con.begin();
            while(it != con.end())
            {
                cout << *it << " ";
                ++it;
            }
            cout << endl;
        }


};