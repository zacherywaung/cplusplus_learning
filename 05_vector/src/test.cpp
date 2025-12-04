#include<iostream>
#include<vector>
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
}

int main()
{
    Test1();
    return 0;
}