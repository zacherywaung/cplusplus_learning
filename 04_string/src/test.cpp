#include"../include/string.h"

void Test1_create()
{
    zw::string s1 = "hello world";
    zw::string s2("hello world");
    zw::string s3(s2);
    zw::string s4;
    s4 = s3;
}

void Test2_capacity()
{
    zw::string s1 = "hello world";
    zw::string s2;
    cout << s1.capacity() << endl;
    cout << s1.size() << endl;
    cout << s1.empty() << endl;
    cout << s2.empty() << endl;
    s1.resize(5);
    s2.resize(10, '#');
    s2.reserve(30);
    cout<< s2.size() << endl;
    cout<< s2.capacity() << endl;
}

void Test3_access()
{
    zw::string s("hello world");
    cout << s[4] << endl;
    s[4] = 'x';
    cout << s[4] << endl;
    for(int i = 0; i < s.size(); i++)
    {
        cout << s[i] << ' ';
    }
    cout << endl;

}

void Test4_iterator()
{
    zw::string s("hello world");
    zw::string::iterator it = s.begin();
    while(it != s.end())
    {
        cout << *it << ' ';
        it++;
    }
    cout << endl;
}

void Test5_modify()
{
    zw::string s1("hello world");
    s1.push_back('#');
    cout << s1.c_str() << endl;
    s1 += '*';
    cout << s1.c_str() << endl;
    s1.append("%%%%%%");
    cout << s1.c_str() << endl;
    s1 += "hello world";
    cout << s1.c_str() << endl;
    zw::string s2("xxxxxxxxxxx");
    s1.swap(s2);
    cout << "s1:" << s1.c_str() << endl;
    cout << "s2:" << s2.c_str() << endl;
    s1.clear();
    cout << s1.c_str() << endl;
    cout << "-----------" << endl;
}

int main()
{
    //Test1_create();
    //Test2_capacity();
    // Test3_access();
    // Test4_iterator();
    Test5_modify();
    return 0;
}