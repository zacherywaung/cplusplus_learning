#pragma once
#include"RBTree.h"

namespace zw
{
    template<class K, class V>
    class map
    {
    private:
        struct KeyOfT
        {
            const K& operator()(const pair<K, V>& kv)
            {
                return kv.first;
            }
        };

    public:
        typedef typename RBTree<K, pair<const K, V>, KeyOfT>::Iterator iterator;
        typedef typename RBTree<K, pair<const K, V>, KeyOfT>::ConstIterator const_iterator;

        iterator begin()
        {
            return _t.Begin();
        }

        iterator end()
        {
            return _t.End();
        }

        const_iterator begin() const
        {
            return _t.Begin();
        }

        const_iterator end() const
        {
            return _t.End();
        }

        bool Insert(const pair<K, V>& kv)
        {
            return _t.Insert(kv);
        }


    private:
        RBTree<K, pair<const K, V>, KeyOfT> _t;
    };
}