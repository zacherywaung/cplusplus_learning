#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

namespace zw
{

    template<class K>
    struct defaulthash
    {
        size_t operator()(const K& key)
        {
            return (size_t)key;
        }
    };

    template<>
    struct defaulthash<string>
    {
        size_t operator()(const string& key)
        {
            size_t ret = 0;
            for(auto& ch : key)
            {
                ret += ch;
                ret *= 131;
            }
            return ret;
        }
    };

    inline unsigned long getNextPrime(unsigned long num)
    {
        static const unsigned long len = 28;
        static const unsigned long primeList[] = {
        53, 97, 193, 389, 769,
        1543, 3079, 6151, 12289, 24593,
        49157, 98317, 196613, 393241, 786433,
        1572869, 3145739, 6291469, 12582917, 25165843,
        50331653, 100663319, 201326611, 402653189, 805306457,
        1610612741, 3221225473, 4294967291
        };
        const unsigned long* first = primeList;
        const unsigned long* last = primeList + len;
        const unsigned long* pos = lower_bound(first, last, num);
        return pos == last ? *(last - 1) : *pos; 
    }

    namespace separate_chaining
    {
        template<class T>
        class HashNode
        {
        public:
            T _data;
            HashNode<T>* _next = nullptr;

            HashNode(const T& data)
                :_data(data)
                ,_next(nullptr)
            {}
        };

        template<class K, class T, class KeyOfT, class hash>
        class HashTable;

        template<class K, class T, class Ref, class Ptr, class KeyOfT, class hash = defaulthash<K>>
        struct HTIterator
        {
            using Node = HashNode<T>;
            using HashTable = HashTable<K, T, KeyOfT, hash>;
            using Self = HTIterator<K, T, Ref, Ptr,KeyOfT, hash>;

            Node* _node;
            HashTable* _ht;

            HTIterator(Node* node, HashTable* ht)
                :_node(node)
                ,_ht(ht)
            {}

            Ref operator*()
            {
                return _node->_data;
            }

            Ptr operator->()
            {
                return &( _node->_data);
            }

            bool operator!=(const Self& s)
            {
                return _node != s._node;
            }

            Self& operator++()
            {
                if(_node->_next)
                {
                    _node = _node->_next;
                }
                else{
                    KeyOfT kot;
                    hash transfer;
                    size_t hashi = transfer(kot(_node->_data)) % _ht->_tables.size();
                    ++hashi;
                    while(hashi < _ht->_tables.size())
                    {
                        _node = _ht->_tables[hashi];
                        if(_node)
                        {
                            break;
                        }
                        ++hashi;
                    }
                    if(hashi == _ht->_tables.size())
                    {
                        _node = nullptr;
                    }
                }
                return *this;
            }
        };

        template<class K, class T, class KeyOfT, class hash = defaulthash<K>>
        class HashTable
        {
            template<class, class, class, class, class, class>
            friend struct HTIterator;
        public:
            using Node = HashNode<T>;

            using Iterator = HTIterator<K, T, T&, T*, KeyOfT, hash>;
            using ConstIterator = HTIterator<K, T, const T&, const T*, KeyOfT, hash>;

            HashTable()
                :_tables(getNextPrime(0))
                ,_n(0)
            {}

            Iterator Begin()
            {
                if(_n == 0)
                {
                    return End();
                }
                for(int i = 0; i < _tables.size(); i++)
                {
                    Node* cur = _tables[i];
                    if(cur)
                    {
                        return Iterator(cur, this);
                    }
                }
                return End();
            }

            Iterator End()
            {
                return Iterator(nullptr, this);
            }

            ConstIterator Begin() const
            {
                if(_n == 0)
                {
                    return End();
                }
                for(int i = 0; i < _tables.size(); i++)
                {
                    Node* cur = _tables[i];
                    if(cur)
                    {
                        return ConstIterator(cur, this);
                    }
                }
                return End();
            }

            ConstIterator End() const
            {
                return ConstIterator(nullptr, this);
            }

            pair<Iterator, bool> Insert(const T& data)
            {
                KeyOfT kot;
                Iterator it = Find(kot(data));
                if(it != End())
                {
                    return {it, false};
                }

                hash transfer;

                if(_n == _tables.size())
                {
                    vector<Node*> newtables(getNextPrime(_tables.size() + 1));
                    for(int i = 0; i < _tables.size(); i++)
                    {
                        Node* cur = _tables[i];
                        while(cur)
                        {
                            Node* next = cur->_next;
                            size_t hashi = transfer(kot(cur->_data)) % newtables.size();
                            cur->_next = newtables[hashi];
                            newtables[hashi] = cur;

                            cur = next;
                        }
                        _tables[i] = nullptr;
                    }
                    _tables.swap(newtables);
                }

                size_t hashi = transfer(kot(data)) % _tables.size();
                Node* newnode = new Node(data);
                newnode->_next = _tables[hashi];
                _tables[hashi] = newnode;
                ++_n;

                return {Iterator(newnode, this), true};
            }

            Iterator Find(const K& key)
            {
                hash transfer;
                KeyOfT kot;
                size_t hashi = transfer(key) % _tables.size();
                Node* cur = _tables[hashi];
                while(cur)
                {
                    if(kot(cur->_data) == key)
                    {
                        return Iterator(cur, this);
                    }
                    cur = cur->_next;
                }
                return End();
            }

            bool Erase(const K& key)
            {
                
                hash transfer;
                KeyOfT kot;
                size_t hashi = transfer(key) % _tables.size();
                Node* cur = _tables[hashi];
                Node* prev = nullptr;
                while(cur)
                {
                    if(kot(cur->_data) == key)
                    {
                        if(prev == nullptr)
                        {
                            _tables[hashi] = cur->_next;
                        }
                        else
                        {
                            prev->_next = cur->_next;
                        }
                        delete cur;
                        --_n;
                        return true;
                    }
                    prev = cur;
                    cur = cur->_next;
                }
                return false;
            }

        private:
            vector<Node*> _tables;
            size_t _n;
        };
    }

}