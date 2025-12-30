#include<iostream>
#include<vector>
#include"../include/RBTree.h"

void Test1()
{
    zw::RBTree<int, int> t;
    vector<int> v({16, 3, 7, 11, 9, 26, 18, 14, 15});
    for(auto i : v)
    {
        t.Insert({i, i});
        t.Inorder();
        cout << "-----------" << endl;
    }
    t.Inorder();
    cout << t.IsBalanceTree() << endl;
}


int main()
{
    Test1();
    return 0;
}