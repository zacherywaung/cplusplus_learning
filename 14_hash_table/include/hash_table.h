#pragma once
#include<iostream>
#include<vector>
using namespace std;

namespace zw
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

    template<class K, class V>
    class HashTable
    {
    public:
        HashTable()
            :_tables(getNextPrime(0))
            ,_n(0)
        {}

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
            
            size_t hash0 = kv.first % _tables.size();
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
            size_t hash0 = key % _tables.size();
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