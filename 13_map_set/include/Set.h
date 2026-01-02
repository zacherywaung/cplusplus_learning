#pragma once
#include"RBTree.h"

namespace zw
{
    template<class K>
    class set
    {
    private:
        struct KeyOfT
        {
            const K& operator()(const K& key)
            {
                return key;
            }
        };
    
    public:
        typedef typename RBTree<K, const K, KeyOfT>::Iterator iterator;
        typedef typename RBTree<K, const K, KeyOfT>::ConstIterator const_iterator;

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

        pair<iterator, bool> Insert(const K& key)
        {
            return _t.Insert(key);
        }

    private:
        RBTree<K, const K, KeyOfT> _t;
    };
}