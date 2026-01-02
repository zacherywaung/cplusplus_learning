#include"../include/hash_table.h"

void Test1()
{
    zw::HashTable<int, int> ht;
    int arr[] = {2, 3, 5, 1, 8, 9, 3, 1, 5, 7};
    for(auto i : arr)
    {
        ht.Insert({i, i});
    }
    cout << ht.Erase(6) << endl; // 0
    cout << ht.Erase(1) << endl; // 1
    
}

int main()
{
    Test1();
    return 0;
}