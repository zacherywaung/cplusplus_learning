#pragma once

#include"hash_table.h"

namespace zw
{
    template<class K, class Hash = defaulthash<K>>
    class unordered_set
    {
        struct KeyOfT
        {
            const K& operator()(const K& key)
            {
                return key;
            }
        };
    public:
        typedef typename separate_chaining::HashTable<K, const K, KeyOfT, Hash>::Iterator iterator;
        typedef typename separate_chaining::HashTable<K, const K, KeyOfT, Hash>::ConstIterator const_iterator;

        iterator begin()
        {
            return _ht.Begin();
        }

        iterator end()
        {
            return _ht.End();
        }

        const_iterator begin() const
        {
            return _ht.Begin();
        }

        const_iterator end() const
        {
            return _ht.End();
        }

        pair<iterator, bool> Insert(const K& key)
        {
            return _ht.Insert(key);
        }

        iterator Find(const K& key)
        {
            return _ht.Find(key);
        }

        bool Erase(const K& key)
        {
            return _ht.Erase(key);
        }

    private:
        separate_chaining::HashTable<K, const K, KeyOfT, Hash> _ht;
    };
}