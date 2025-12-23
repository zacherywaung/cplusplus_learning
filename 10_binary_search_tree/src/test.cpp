#include"../include/binary_search_tree.h"
    


void TestBSTree()
{
    // key_value::BSTree<string, string> dict;
    // dict.Insert("insert", "插入");
    // dict.Insert("erase", "删除");
    // dict.Insert("left", "左边");
    // dict.Insert("string", "字符串");

    // string str;
    // while (cin>>str)
    // {
    //     auto ret = dict.Find(str);
    //     if (ret)
    //     {
    //         cout << str << ":" << ret->_val << endl;
    //     }
    //     else
    //     {
    //         cout << "单词拼写错误" << endl;
    //     }
    // }

    string strs[] = { "apple", "watermellon", "apple", "cheery", "apple", "cheery", "pineapple", "watermellon", "apple" };
    // calculate fruit frequency
    key_value::BSTree<string, int> countTree;
    for (auto str : strs)
    {
        auto ret = countTree.Find(str);
        if (ret == NULL)
        {
            countTree.Insert(str, 1);
        }
        else
        {
            ret->_val++;
        }
    }
    countTree.Inorder();
}

int main()
{
    key::BSTree<int> bst;
    bst.Insert(5);
    bst.Insert(8);
    bst.Insert(12);
    bst.Insert(3);
    bst.Insert(1);
    bst.Insert(7);
    cout << bst.Find(9) << endl;
    cout << bst.Find(8) << endl;
    bst.Inorder();
    vector<int> v = {5, 8, 12, 3, 1, 7};
    for(int i = 0; i < v.size(); i++)
    {
        bst.Erase(v[i]);
        bst.Inorder();
    }
    TestBSTree();

}