#include"../include/avl_tree.h"
#include<vector>

void Test1()
{
    zw::AVLTree<int, int> t;
    //vector<int> v({16, 3, 7, 11, 9, 26, 18, 14, 15});
    vector<int> v({4, 2, 6, 1, 3, 5, 15, 7, 16, 14});

    vector<int>::iterator it = v.begin();
    while(it != v.end())
    {
        t.Insert({*it, 0});
        ++it;
    }
    t.InOrder();
    if(t.Find(16) && ((t.Find(16))->_kv).first == 16)
    {
        cout << "Found Succeed" << endl;
    }
    else{
        cout << "Found error" << endl;
    }
}

void Test2()
{
    int N = 100000;
    vector<int> v;
    v.reserve(N);
    srand(time(0));
    for(int i = 0; i < N; i++)
    {
        v.push_back(rand() + i);
    }
    // insert time
    size_t begin1 = clock();
    zw::AVLTree<int, int> t;
    for(auto& i : v)
    {
        t.Insert({i, i});
    }
    size_t end1 = clock();
    
    cout << "insert time: " <<  end1 - begin1 << endl;
    cout << "is balance? " << t.isBalanceTree() << endl;
    cout << "tree depth: " << t.Height() << endl;
    cout << "tree size: " << t.Size() << endl;

    size_t begin2 = clock();
    for(auto& i : v)
    {
        t.Find(i);
    }
    size_t end2 = clock();
    cout << "find time: " <<  end2 - begin2 << endl;

}


int main()
{
    Test1();
    Test2();

    return 0;
}
