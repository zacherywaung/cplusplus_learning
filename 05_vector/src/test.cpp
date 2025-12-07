#include<iostream>
#include<vector>
#include"../include/vector.h"
using namespace std;

void Test1()
{
    vector<int> v0;
    cout << v0.capacity() << endl;
    v0.reserve(10);
    cout << v0.capacity() << endl;
    v0.resize(15, 2);
    cout << v0.capacity() << endl;
    cout << v0.size() << endl;
    v0.resize(5);
    cout << v0.capacity() << endl;
    cout << v0.size() << endl;
    v0.insert(v0.begin() + 1, 100);
    v0.erase(v0.begin());
    vector<int> v1(10, 1);
    vector<int>::iterator it = v1.begin();
    while(it != v1.end())
    {
        cout << *it << ",";
        it++;
    }
    cout << endl;
    for(auto& e : v1)
    {
        cout << e << ",";
    }
    cout << endl;
    vector<int> v2(10);
    for(auto& e : v2)
    {
        cout << e << ",";
    }
    cout << endl;
}

void Test2()
{
    zw::vector<int> v1;
    zw::vector<int> v2(10,1);
    string s1("hello world");
    zw::vector<char> v3(s1.begin() + 2, s1.end());
    zw::vector<char> v4(v3);
}

void Test3()
{
    zw::vector<int> v1(10,1);
    cout << v1.size() << ":" << v1.capacity() << endl;
    v1.reserve(15);
    cout << v1.size() << ":" << v1.capacity() << endl;
    v1.resize(5);
    cout << v1.size() << ":" << v1.capacity() << endl;
    v1.resize(20,2);
    cout << v1.size() << ":" << v1.capacity() << endl;
    zw::vector<int>::iterator it = v1.begin();
    while(it != v1.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;
    for(auto i : v1)
    {
        cout << i << " ";
    }
    cout << endl;
}

void Test4()
{
    zw::vector<int> v1(10,1);
    v1[5] = 10;
    for(size_t i = 0; i < 10; i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
}

void Test5()
{
    string s1("hello world");
    zw::vector<char> v1(s1.begin(), s1.end());
    v1.push_back('&');
    v1.print_vector();
    v1.push_back('*');
    v1.print_vector();
    v1.pop_back();
    v1.print_vector();
    v1.insert(v1.begin() + 5, '&');
    v1.print_vector();
    v1.erase(v1.begin());
    v1.print_vector();

}

int main()
{
    Test1();
    //Test2();
    //Test3();
    //Test4();
    //Test5();
    return 0;
}