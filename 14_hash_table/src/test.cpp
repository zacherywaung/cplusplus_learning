#include"../include/hash_table.h"

void Test1()
{
    zw::open_addressing::HashTable<int, int> ht;
    int arr[] = {2, 3, 5, 1, 8, 9, 3, 1, 5, 7};
    for(auto i : arr)
    {
        ht.Insert({i, i});
    }
    cout << ht.Erase(6) << endl; // 0
    cout << ht.Erase(1) << endl; // 1
    
}

void Test2()
{
    zw::open_addressing::HashTable<string, int> ht;
    ht.Insert({"abcd", 1});
    ht.Insert({"hello", 2});
    ht.Insert({"c++", 3});
    ht.Insert({"hashtable", 4});

    zw::defaulthash<string> transfer;
    cout << transfer("abcd") << endl;
    cout << transfer("hello") << endl;
    cout << transfer("c++") << endl;
    cout << transfer("hashtable") << endl;

}

void Test3()
{
    zw::separate_chaining::HashTable<string, int> ht;
    ht.Insert({"abcd", 1});
    ht.Insert({"hello", 2});
    ht.Insert({"c++", 3});
    ht.Insert({"hashtable", 4});

    zw::defaulthash<string> transfer;
    cout << transfer("abcd") << endl;
    cout << transfer("hello") << endl;
    cout << transfer("c++") << endl;
    cout << transfer("hashtable") << endl;

}

int main()
{
    //Test1();
    //Test2();
    Test3();
    return 0;
}