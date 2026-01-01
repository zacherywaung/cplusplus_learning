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

    template<class T>
    class RBTreeNode
    {
    public:
        T _data;
        RBTreeNode<T>* _left;
        RBTreeNode<T>* _right;
        RBTreeNode<T>* _parent;
        Color _color;

        RBTreeNode(const T& data)
            :_data(data)
            ,_left(nullptr)
            ,_right(nullptr)
            ,_parent(nullptr)
        {}
    };

    template<class T, class Ref, class Ptr>
    class RBTreeIterator
    {
    typedef RBTreeNode<T> Node;
    typedef RBTreeIterator<T, Ref, Ptr> Self;
    public:
        Node* _node;
        Node* _root;

    public:
        RBTreeIterator(Node* node, Node* root)
            :_node(node)
            ,_root(root)
        {}

        Self& operator++()
        {
            if(_node->_right)
            {
                _node = _node->_right;
                while(_node->_left)
                {
                    _node = _node->_left;
                }
            }
            else{
                Node* cur = _node;
                Node* parent = cur->_parent;
                while(parent && cur == parent->_right)
                {
                    cur = parent;
                    parent = cur->_parent;
                }
                _node = parent;
            }
            return *this;
        }

        Self& operator--()
        {
            if(_node == nullptr) //end()
            {
                _node = _root;
                while(_node && _node->_right)
                {
                    _node = _node->_right;
                }
            }
            else if(_node->_left)
            {
                _node = _node->_left;
                while(_node->_right)
                {
                    _node = _node->_right;
                }
            }
            else{
                Node* cur = _node;
                Node* parent = cur->_parent;
                while(parent && cur == parent->_left)
                {
                    cur = parent;
                    parent = cur->_parent;
                }
                _node = parent;
            }
            return *this;
        }

        Ref operator*()
        {
            return _node->_data;
        }

        Ptr operator->()
        {
            return &(_node->_data);
        }

        bool operator!=(const Self& it) const
        {
            return _node != it._node;
        }

        bool operator==(const Self& it) const
        {
            return _node == it._node;
        }

    };

    template<class K, class T, class KeyOfT>
    class RBTree
    {
        using Node = RBTreeNode<T>;
    public:
        typedef RBTreeIterator<T, T&, T*> Iterator;
        typedef RBTreeIterator<T, const T&, const T*> ConstIterator;

        Iterator Begin()
        {
            Node* cur = _root;
            while(cur && cur->_left)
            {
                cur = cur->_left;
            }
            return Iterator(cur, _root);
        }

        Iterator End()
        {
            return Iterator(nullptr, _root);
        }

        ConstIterator Begin() const
        {
            Node* cur = _root;
            while(cur && cur->_left)
            {
                cur = cur->_left;
            }
            return ConstIterator(cur, _root);
        }

        ConstIterator End() const
        {
            return ConstIterator(nullptr, _root);
        }

        bool Insert(const T& data)
        {
            if(_root == nullptr)
            {
                _root = new Node(data);
                _root->_color = Color::Black;
                return true;
            }
            KeyOfT kot;
            Node* cur = _root;
            Node* parent = nullptr;
            while(cur)
            {
                if(kot(cur->_data) > kot(data))
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else if(kot(cur->_data) < kot(data))
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else{
                    return false;
                }
            }
            cur = new Node(data);
            cur->_color = Color::RED;
            cur->_parent = parent;
            if(kot(parent->_data) > kot(data))
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

        // void Inorder()
        // {
        //     _Inorder(_root);
        // }

        

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

        // void _Inorder(Node* root)
        // {
        //     if(root == nullptr)
        //     {
        //         return;
        //     }
        //     _Inorder(root->_left);
        //     cout << root->_kv.first << ":" << root->_kv.second << endl;
        //     _Inorder(root->_right);
        // }



    private:
        Node* _root = nullptr;
    };
}
