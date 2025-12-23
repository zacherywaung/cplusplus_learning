#include<iostream>
#include<vector>
using namespace std;

namespace key
{
    template<class K>
    class BSTNode
    {
    public:
        BSTNode(const K& key)
            :_key(key)
            ,_left(nullptr)
            ,_right(nullptr)
        {}
    public:
        K _key;
        BSTNode<K>* _left = nullptr;
        BSTNode<K>* _right = nullptr;
    };

    template<class K>
    class BSTree
    {
        using Node = BSTNode<K>;
    public:
        BSTree() = default;

        bool Insert(const K& key)
        {
            if(_root == nullptr)
            {
                _root = new Node(key);
                return true;
            }
            Node* parent = _root;
            Node* cur = _root;
            while(cur)
            {
                if(cur->_key < key)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else if(cur->_key > key)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else{
                    return false;
                }
            }
            cur = new Node(key);
            if(parent->_key < key)
            {
                parent->_right = cur;
            }
            else{
                parent->_left = cur;
            }
            return true;
        }

        bool Find(const K& key)
        {
            Node* cur = _root;
            while(cur)
            {
                if(cur->_key < key)
                {
                    cur = cur->_right;
                }
                else if(cur->_key > key)
                {
                    cur = cur->_left;
                }
                else{
                    return true;
                }
            }
            return false;
        }

        bool Erase(const K& key)
        {
            Node* parent = nullptr;
            Node* cur = _root;
            while(cur)
            {
                if(cur->_key < key)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else if(cur->_key > key)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else{
                    // only remain right child or have no child
                    if(cur->_left == nullptr)
                    {
                        if(cur == _root)
                        {
                            _root = cur->_right;
                        }
                        else{
                            if(parent->_left == cur)
                            {
                                parent->_left = cur->_right;
                            }
                            else
                            {
                                parent->_right = cur->_right;
                            }
                        }
                        delete cur;
                        return true;
                    }
                    // only remain left child
                    else if(cur->_right == nullptr)
                    {
                        if(cur == _root)
                        {
                            _root = cur->_left;
                        }
                        else{
                            if(parent->_left == cur)
                            {
                                parent->_left = cur->_left;
                            }
                            else
                            {
                                parent->_right = cur->_left;
                            }
                        }
                        delete cur;
                        return true;
                    }
                    //remain both left and right child
                    else{
                        Node* rightminP = cur;
                        Node* rightmin = cur->_right;
                        while(rightmin->_left)
                        {
                            rightminP = rightmin;
                            rightmin = rightmin->_left;
                        }
                        cur->_key = rightmin->_key;
                        if(rightminP->_left == rightmin)
                        {
                            rightminP->_left = rightmin->_right;
                        }
                        else{
                            cur->_right = rightmin->_right;
                        }
                        delete rightmin;
                        return true;
                    }
                }
            }
            return false;
        }


        void Inorder()
        {
            _Inorder(_root);
            cout << endl;
        }

    private:
        void _Inorder(Node* root)
        {
            if(root == nullptr)
            {
                return;
            }
            _Inorder(root->_left);
            cout << root->_key << " ";
            _Inorder(root->_right);
        }
    private:
        Node* _root = nullptr;
    };
}

namespace key_value
{
    template<class K, class V>
    class BSTNode
    {
    public:
        BSTNode(const K& key, const V& value)
            :_key(key)
            ,_val(value)
            ,_left(nullptr)
            ,_right(nullptr)
        {}
    public:
        K _key;
        V _val;
        BSTNode<K, V>* _left = nullptr;
        BSTNode<K, V>* _right = nullptr;
    };

    template<class K, class V>
    class BSTree
    {
        using Node = BSTNode<K, V>;
    public:
        BSTree() = default;

        bool Insert(const K& key, const V& value)
        {
            if(_root == nullptr)
            {
                _root = new Node(key, value);
                return true;
            }
            Node* parent = _root;
            Node* cur = _root;
            while(cur)
            {
                if(cur->_key < key)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else if(cur->_key > key)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else{
                    return false;
                }
            }
            cur = new Node(key, value);
            if(parent->_key < key)
            {
                parent->_right = cur;
            }
            else{
                parent->_left = cur;
            }
            return true;
        }

        Node* Find(const K& key)
        {
            Node* cur = _root;
            while(cur)
            {
                if(cur->_key < key)
                {
                    cur = cur->_right;
                }
                else if(cur->_key > key)
                {
                    cur = cur->_left;
                }
                else{
                    return cur;
                }
            }
            return nullptr;
        }

        bool Erase(const K& key)
        {
            Node* parent = nullptr;
            Node* cur = _root;
            while(cur)
            {
                if(cur->_key < key)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else if(cur->_key > key)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else{
                    // only remain right child or have no child
                    if(cur->_left == nullptr)
                    {
                        if(cur == _root)
                        {
                            _root = cur->_right;
                        }
                        else{
                            if(parent->_left == cur)
                            {
                                parent->_left = cur->_right;
                            }
                            else
                            {
                                parent->_right = cur->_right;
                            }
                        }
                        delete cur;
                        return true;
                    }
                    // only remain left child
                    else if(cur->_right == nullptr)
                    {
                        if(cur == _root)
                        {
                            _root = cur->_left;
                        }
                        else{
                            if(parent->_left == cur)
                            {
                                parent->_left = cur->_left;
                            }
                            else
                            {
                                parent->_right = cur->_left;
                            }
                        }
                        delete cur;
                        return true;
                    }
                    //remain both left and right child
                    else{
                        Node* rightminP = cur;
                        Node* rightmin = cur->_right;
                        while(rightmin->_left)
                        {
                            rightminP = rightmin;
                            rightmin = rightmin->_left;
                        }
                        cur->_key = rightmin->_key;
                        if(rightminP->_left == rightmin)
                        {
                            rightminP->_left = rightmin->_right;
                        }
                        else{
                            cur->_right = rightmin->_right;
                        }
                        delete rightmin;
                        return true;
                    }
                }
            }
            return false;
        }


        void Inorder()
        {
            _Inorder(_root);
            cout << endl;
        }

    private:
        void _Inorder(Node* root)
        {
            if(root == nullptr)
            {
                return;
            }
            _Inorder(root->_left);
            cout << root->_key << ":" << root->_val << endl;
            _Inorder(root->_right);
        }
    private:
        Node* _root = nullptr;
    };
}