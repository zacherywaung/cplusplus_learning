#include<iostream>
#include"../include/Set.h"
#include"../include/Map.h"

void Test1()
{
    zw::set<int> s1;
    s1.Insert(3);
    s1.Insert(6);
    s1.Insert(1);
    s1.Insert(2);
    s1.Insert(9);
    zw::set<int>::iterator it = s1.begin();
    while(it != s1.end())
    {
        cout << *it << endl;
        ++it;
    }
    cout << endl;

    for(auto& i : s1)
    {
        cout << i << endl;
    }
    cout << endl;
}

void Test2()
{
    zw::map<int, int> m1;
    m1.Insert({3, 3});
    m1.Insert({6, 6});
    m1.Insert({1, 1});
    m1.Insert({2, 2});
    m1.Insert({9, 9});
    zw::map<int, int>::iterator it = m1.begin();
    while(it != m1.end())
    {
        it->second += 10;
        cout << it->first << ":" << it->second << endl;
        ++it;
    }
    cout << endl;

}



int main()
{
    Test1();
    Test2();
    return 0;
}