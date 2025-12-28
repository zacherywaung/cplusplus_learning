#pragma once
#include<iostream>
#include<assert.h>
#include<map>
using namespace std;

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
            ,_parent(nullptr)
            ,_balance_factor(0)
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
            cur = new Node(kv);
            if(parent->_kv.first > kv.first)
            {
                parent->_left = cur;
            }
            else if(parent->_kv.first < kv.first)
            {
                parent->_right = cur;
            }
            cur->_parent = parent;
            
            // deal with _balance_factor
            while(parent)
            {
                if(cur == parent->_left)
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
                    //rotate
                    if(parent->_balance_factor == -2 && cur->_balance_factor == -1)
                    {
                        rotateR(parent);
                    }
                    else if(parent->_balance_factor == 2 && cur->_balance_factor == 1)
                    {
                        rotateL(parent);
                    }
                    else if(parent->_balance_factor == -2 && cur->_balance_factor == 1)
                    {
                        rotateLR(parent);
                    }
                    else if(parent->_balance_factor == 2 && cur->_balance_factor == -1)
                    {
                        rotateRL(parent);
                    }
                    else{
                        assert(false);
                    }

                    break;
                }
                else{
                    assert(false);
                }
            }
            return true;
        }

        void InOrder()
        {
            _InOrder(_root);
        }

        int Height()
        {
            return _Height(_root);
        }

        int Size()
        {
            return _Size(_root);
        }

        bool isBalanceTree()
        {
            return _isBalanceTree(_root);
        }

        Node* Find(const K& key)
        {
            Node* cur = _root;
            while(cur)
            {
                if((cur->_kv).first > key)
                {
                    cur = cur->_left;
                }
                else if((cur->_kv).first < key)
                {
                    cur = cur->_right;
                }
                else{
                    return cur;
                }
            }
            return nullptr;
        }

    private:
        void rotateR(Node* parent)
        {
            Node* subL = parent->_left;
            Node* subLR = subL->_right;
            Node* pparent = parent->_parent;
            parent->_left = subLR;
            if(subLR)
            {
                subLR->_parent = parent;
            }
            subL->_right = parent;
            parent->_parent = subL;
            if(parent == _root)
            {
                _root = subL;
                subL->_parent = nullptr;
            }
            else{
                subL->_parent = pparent;
                if(pparent->_left == parent)
                {
                    pparent->_left = subL;
                }
                else{
                    pparent->_right = subL;
                }
            }
            parent->_balance_factor = 0;
            subL->_balance_factor = 0;
        }

        void rotateL(Node* parent)
        {
            Node* subR = parent->_right;
            Node* subRL = subR->_left;
            Node* pparent = parent->_parent;
            parent->_right = subRL;
            if(subRL)
            {
                subRL->_parent = parent;
            }
            subR->_left = parent;
            parent->_parent = subR;
            if(parent == _root)
            {
                _root = subR;
                subR->_parent = nullptr;
            }
            else{
                subR->_parent = pparent;
                if(pparent->_left == parent)
                {
                    pparent->_left = subR;
                }
                else{
                    pparent->_right = subR;
                }
            }
            parent->_balance_factor = 0;
            subR->_balance_factor = 0;
        }

        void rotateLR(Node* parent)
        {
            Node* subL = parent->_left;
            Node* subLR = subL->_right;
            int bf = subLR->_balance_factor;

            rotateL(subL);
            rotateR(parent);

            if(bf == 1)
            {
                subL->_balance_factor = -1;
            }
            else if(bf == -1)
            {
                parent->_balance_factor = 1;
            }
            else if(bf == 0)
            {
                ;
            }
            else{
                assert(false);
            }
        }

        void rotateRL(Node* parent)
        {
            Node* subR = parent->_right;
            Node* subRL = subR->_left;
            int bf = subRL->_balance_factor;

            rotateR(subR);
            rotateL(parent);

            if(bf == 1)
            {
                parent->_balance_factor = -1;
            }
            else if(bf == -1)
            {
                subR->_balance_factor = 1;
            }
            else if(bf == 0)
            {
                ;
            }
            else{
                assert(false);
            }
        }

        void _InOrder(Node* root)
        {
            if(root == nullptr)
            {
                return;
            }
            _InOrder(root->_left);
            cout << (root->_kv).first << ":" <<(root->_kv).second << endl;
            _InOrder(root->_right);
        }

        int _Height(Node* root)
        {
            if(root == nullptr)
            {
                return 0;
            }
            int left_height = _Height(root->_left);
            int right_height = _Height(root->_right);
            return left_height > right_height? left_height + 1 : right_height + 1;
        }

        int _Size(Node* root)
        {
            if(root == nullptr)
            {
                return 0;
            }
            return _Size(root->_left) + _Size(root->_right) + 1;
        }

        bool _isBalanceTree(Node* root)
        {
            if(root == nullptr)
            {
                return true;
            }
            int left_height = _Height(root->_left);
            int right_height = _Height(root->_right);
            int diff = right_height - left_height;
            if(abs(diff) >= 2)
            {
                cout << "height difference error" << endl;
                return false;
            }
            if(root->_balance_factor != diff)
            {
                cout << "balance factor error" << endl;
                return false;
            }
            return _isBalanceTree(root->_left) && _isBalanceTree(root->_right);
        }

    private:
        Node* _root = nullptr;
    };

}