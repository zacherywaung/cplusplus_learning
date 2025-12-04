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

void Test6_find_insert_erase()
{
    zw::string s("hello world");
    cout << s.find('l', 5) << endl; // 9
    cout << s.find('l') << endl; // 2
    cout << s.find("rld", 5) << endl; // 8
    cout << s.find("hello", 5) << endl; // npos
    s.insert(5, 'x');
    cout << s.c_str() << endl; // hellox world
    s.insert(5, "&&&&&");
    cout << s.c_str() << endl; // hello&&&&&x world
    s.erase(5, 5);
    cout << s.c_str() << endl; // hellox world
    s.erase(5, 100);
    cout << s.c_str() << endl; // hello
    zw::string sub_1 = s.substr(2);
    zw::string sub_2 = s.substr(2, 2);
    cout << sub_1.c_str() << endl; // llo
    cout << sub_2.c_str() << endl; // ll

    
}

void Test7_iostream()
{
    zw::string s1("hello world");
    zw::string s2;
    cout << s1 << endl;
    cin >> s1 >> s2;
    cout << s1 << endl;
    cout << s2 << endl;

}

void Test8_operator()
{
    zw::string s1("abcdefg");
    zw::string s2("abddefg");
    cout << (s1 < s2) << endl;
}

int main()
{
    //Test1_create();
    //Test2_capacity();
    //Test3_access();
    //Test4_iterator();
    //Test5_modify();
    //Test6_find_insert_erase();
    //Test7_iostream();
    Test8_operator();
    return 0;
}