#pragma once

#include"hash_table.h"

namespace zw
{
    template<class K, class V, class Hash = defaulthash<K>>
    class unordered_map
    {
        struct KeyOfT
        {
            const K& operator()(const pair<const K, V>& kv)
            {
                return kv.first;
            }
        };
    
    public:
        typedef typename separate_chaining::HashTable<K, pair<const K, V>, KeyOfT, Hash>::Iterator iterator;
        typedef typename separate_chaining::HashTable<K, pair<const K, V>, KeyOfT, Hash>::ConstIterator const_iterator;

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

        pair<iterator, bool> Insert(const pair<K, V>& kv)
        {
            return _ht.Insert(kv);
        }

        iterator Find(const K& key)
        {
            return _ht.Find(key);
        }

        bool Erase(const K& key)
        {
            return _ht.Erase(key);
        }

        V& operator[](const K& key)
        {
            pair<iterator, bool> ret = Insert({key, V()});
            return ret.first->second;
        }

    private:
        separate_chaining::HashTable<K, pair<const K, V>, KeyOfT, Hash> _ht;
    };
}