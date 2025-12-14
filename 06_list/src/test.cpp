#include"../include/list.h"

void Test1()
{
    zw::list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    zw::list<int>::iterator it = l1.begin();
    while(it != l1.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout <<  endl;

    zw::list<string> l2;
    l2.push_back("11111");
    l2.push_back("22222");
    l2.push_back("33333");
    l2.push_back("44444");
    l2.push_back("55555");
    for(auto& s : l2)
    {
        cout << s << endl;
    }
    zw::list<string>::iterator e = l2.begin();
    int k = 2;
    while(k != 0)
    {
        ++e;
        k--;
    }
    l2.erase(e);
    for(auto& s : l2)
    {
        cout << s << endl;
    }

}


int main()
{
    Test1();
    return 0;
}