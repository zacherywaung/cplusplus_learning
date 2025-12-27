#pragma once
#include<assert.h>

namespace zw
{
    template<class K, class V>
    class AVLTreeNode
    {
    public:
        pair<K, V> _kv;
        AVLTreeNode<K, V>* _left = nullptr;
        AVLTreeNode<K, V>* _right = nullptr;
        AVLTreeNode<K, V>* _parent = nullptr;
        int _balance_factor = 0;

        AVLTreeNode(const pair<K, V>& kv)
            :_kv(kv)
            ,_left(nullptr)
            ,_right(nullptr)
            ,_balance_factor(nullptr)
        {}
    };


    template<class K, class V>
    class AVLTree
    {
        using Node = AVLTreeNode<K, V>;
    public:
        bool Insert(const pair<K, V>& kv)
        {
            if(_root == nullptr)
            {
                _root = new Node(kv);
                return true;
            }
            Node* cur = _root;
            Node* parent = nullptr;
            while(cur)
            {
                if(cur->_kv.first > kv.first)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else if(cur->_kv.first < kv.first)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else{
                    return false;
                }
            }
            cur = new Node(kv)
            if(parent->_kv.first > kv.first)
            {
                parent->left = cur;
            }
            else if(parent->_kv.first < kv.first)
            {
                parent->right = cur;
            }
            cur->_parent = parent;
            
            // deal with _balance_factor
            while(parent)
            {
                if(cur = parent->left)
                {
                    parent->_balance_factor--;
                }
                else{
                    parent->_balance_factor++;
                }
                if(parent->_balance_factor == 0)
                {
                    break;
                }
                else if(parent->_balance_factor == 1 || parent->_balance_factor == -1)
                {
                    cur = cur->_parent;
                    parent = parent->_parent;
                }
                else if(parent->_balance_factor == 2 || parent->_balance_factor == -2)
                {
                    ;//rotate
                }
                else{
                    assert(false);
                }
            }
            

        }

    private:
        Node* _root = nullptr;
    }

}