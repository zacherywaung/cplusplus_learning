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

    namespace open_addressing
    {
        enum class State
        {
            EXIST,
            DELETE,
            EMPTY
        };

        template<class K, class V>
        class HashData
        {
        public:
            pair<K, V> _kv;
            State _state = State::EMPTY;
        };
        
        template<class K, class V, class hash = defaulthash<K>>
        class HashTable
        {
        public:
            HashTable()
                :_tables(getNextPrime(0))
                ,_n(0)
            {}

            bool Insert(const pair<K, V>& kv)
            {
                if(Find(kv.first))
                {
                    return false;
                }
                if(10* _n / _tables.size() > 7)
                {
                    HashTable<K, V> newht;
                    newht._tables.resize(getNextPrime(_tables.size() + 1));
                    for(auto& data : _tables)
                    {
                        if(data._state == State::EXIST)
                        {
                            newht.Insert(data._kv);
                        }
                    }
                    _tables.swap(newht._tables);
                }
                hash transfer;
                size_t hash0 = transfer(kv.first) % _tables.size();
                size_t hashi = hash0;
                size_t i = 1;
                while(_tables[hashi]._state == State::EXIST)
                {
                    hashi = (hash0 + i) % _tables.size();
                    ++i;
                }
                _tables[hashi]._kv = kv;
                _tables[hashi]._state = State::EXIST;
                ++_n;
                return true;
            }

            HashData<K, V>* Find(const K& key)
            {
                hash transfer;
                size_t hash0 = transfer(key) % _tables.size();
                size_t hashi = hash0;
                size_t i = 1;
                while(_tables[hashi]._state != State::EMPTY)
                {
                    if(_tables[hashi]._state == State::EXIST &&
                    _tables[hashi]._kv.first == key)
                    {
                        return &(_tables[hashi]);
                    }
                    hashi = (hash0 + i) % _tables.size();
                    ++i;
                }
                return nullptr;
            }

            bool Erase(const K& key)
            {
                HashData<K, V>* ret = Find(key);
                if(ret == nullptr)
                {
                    return false;
                }
                ret->_state = State::DELETE;
                --_n;
                return true;
            }


        private:
            vector<HashData<K, V>> _tables;
            size_t _n;
        };
    }

    namespace separate_chaining
    {
        template<class K, class V>
        class HashNode
        {
        public:
            pair<K, V> _kv;
            HashNode<K, V>* _next = nullptr;

            HashNode(const pair<K, V>& kv)
                :_kv(kv)
                ,_next(nullptr)
            {}
        };

        template<class K, class V, class hash = defaulthash<K>>
        class HashTable
        {
        public:
            using Node = HashNode<K, V>;

            HashTable()
                :_tables(getNextPrime(0))
                ,_n(0)
            {}

            bool Insert(const pair<K, V>& kv)
            {
                if(Find(kv.first))
                {
                    return false;
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
                            size_t hashi = transfer(cur->_kv.first) % newtables.size();
                            cur->_next = newtables[hashi];
                            newtables[hashi] = cur;

                            cur = cur->_next;
                        }
                        _tables[i] = nullptr;
                    }
                    _tables.swap(newtables);
                }

                size_t hashi = transfer(kv.first) % _tables.size();
                Node* newnode = new Node(kv);
                newnode->_next = _tables[hashi];
                _tables[hashi] = newnode;
                ++_n;

                return true;
            }

            HashNode<K, V>* Find(const K& key)
            {
                hash transfer;
                size_t hashi = transfer(key) % _tables.size();
                Node* cur = _tables[hashi];
                while(cur)
                {
                    if(cur->_kv.first == key)
                    {
                        return cur;
                    }
                    cur = cur->_next;
                }
                return nullptr;
            }

            bool Erase(const K& key)
            {
                
                hash transfer;
                size_t hashi = transfer(key) % _tables.size();
                Node* cur = _tables[hashi];
                Node* prev = nullptr;
                while(cur)
                {
                    if(cur->_kv.first == key)
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