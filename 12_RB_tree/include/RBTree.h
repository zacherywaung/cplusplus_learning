#pragma once
#include<map>
using namespace std;

namespace zw
{
    enum class Color
    {
        RED,
        Black
    };

    template<class K, class V>
    class RBTreeNode
    {
    public:
        pair<K, V> _kv;
        RBTreeNode<K, V>* _left;
        RBTreeNode<K, V>* _right;
        RBTreeNode<K, V>* _parent;
        Color _color;

        RBTreeNode(const pair<K, V>& kv)
            :_kv(kv)
            ,_left(nullptr)
            ,_right(nullptr)
            ,_parent(nullptr)
        {}
    };

    template<class K, class V>
    class RBTree
    {
        using Node = RBTreeNode<K, V>;
    public:
        bool Insert(const pair<K, V>& kv)
        {
            if(_root == nullptr)
            {
                _root = new Node(kv);
                _root->_color = Color::Black;
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
            cur->_color = Color::RED;
            cur->_parent = parent;
            if(parent->_kv.first > kv.first)
            {
                parent->_left = cur;
            }
            else{
                parent->_right = cur;
            }
            

            while(parent && parent->_color == Color::RED)
            {
                Node* grandparent = parent->_parent;
                if(parent == grandparent->_left)
                {
                    Node* uncle = grandparent->_right;
                    if(uncle != nullptr && uncle->_color == Color::RED)
                    {
                        grandparent->_color = Color::RED;
                        parent->_color = Color::Black;
                        uncle->_color = Color::Black;
                        cur = grandparent;
                        parent = cur->_parent;
                    }
                    else{
                        if(cur == parent->_left)
                        {
                            rotateR(grandparent);
                            grandparent->_color = Color::RED;
                            parent->_color = Color::Black;
                            break;
                        }
                        else{
                            rotateL(parent);
                            rotateR(grandparent);
                            cur->_color = Color::Black;
                            grandparent->_color = Color::RED;
                            break;
                        }
                    }
                }
                else{
                    Node* uncle = grandparent->_left;
                    if(uncle != nullptr && uncle->_color == Color::RED)
                    {
                        grandparent->_color = Color::RED;
                        parent->_color = Color::Black;
                        uncle->_color = Color::Black;
                        cur = grandparent;
                        parent = cur->_parent;
                    }
                    else{
                        if(cur == parent->_right)
                        {
                            rotateL(grandparent);
                            grandparent->_color = Color::RED;
                            parent->_color = Color::Black;
                            break;
                        }
                        else{
                            rotateR(parent);
                            rotateL(grandparent);
                            cur->_color = Color::Black;
                            grandparent->_color = Color::RED;
                            break;
                        }
                    }
                }
            }
            _root->_color = Color::Black;

            return true;
        }

        void Inorder()
        {
            _Inorder(_root);
        }

        bool IsBalanceTree()
        {
            return _IsBalanceTree();
        }

    private:
        void rotateR(Node* root)
        {
            Node* subL = root->_left;
            Node* subLR = subL->_right;
            Node* pparent = root->_parent;

            root->_left = subLR;
            if(subLR)
            {
                subLR->_parent = root;
            }
            subL->_right = root;
            root->_parent = subL;
            if(root == _root)
            {
                _root = subL;
                subL->_parent = nullptr;
            }
            else{
                if(root == pparent->_left)
                {
                    pparent->_left = subL;
                }
                else{
                    pparent->_right = subL;
                }
                subL->_parent = pparent;
            }
        }

        void rotateL(Node* root)
        {
            Node* subR = root->_right;
            Node* subRL = subR->_left;
            Node* pparent = root->_parent;

            root->_right = subRL;
            if(subRL)
            {
                subRL->_parent = root;
            }
            subR->_left = root;
            root->_parent = subR;
            if(root == _root)
            {
                _root = subR;
                subR->_parent = nullptr;
            }
            else{
                if(root == pparent->_left)
                {
                    pparent->_left = subR;
                }
                else{
                    pparent->_right = subR;
                }
                subR->_parent = pparent;
            }
        }

        void _Inorder(Node* root)
        {
            if(root == nullptr)
            {
                return;
            }
            _Inorder(root->_left);
            cout << root->_kv.first << ":" << root->_kv.second << endl;
            _Inorder(root->_right);
        }

        void _GetBlackNum(Node* root, vector<int>& v, int& count, bool& valid)
        {
            if(root == nullptr)
            {
                v.push_back(count);
                return;
            }
            if(root->_color == Color::Black)
            {
                ++count;
            }
            if(root->_parent && root->_color == root->_parent->_color && root->_color == Color::RED)
            {
                cout << "Error: double red" << endl;
                valid = false;
            }
            _GetBlackNum(root->_left, v, count, valid);
            _GetBlackNum(root->_right, v, count, valid);
            if(root->_color == Color::Black)
            {
                --count;
            }
        }

        bool _IsBalanceTree()
        {
            if(_root == nullptr)
            {
                return true;
            }
            if(_root->_color == Color::RED)
            {
                return false;
            }
            vector<int> v;
            int count = 0;
            bool valid = true;
            _GetBlackNum(_root, v, count, valid);
            if(!valid)
            {
                return false;
            }
            int refnum = v.front();
            for(auto i : v)
            {
                if(i != refnum)
                {
                    return false;
                }
            }
            return true;
        }


    private:
        Node* _root;
    };
}
