#include"../include/unordered_set.h"
#include"../include/unordered_map.h"



void Test1()
{
    zw::unordered_map<int, int> my_map;
}


void test_set1()
{
	zw::unordered_set<int> my_set;
    int arr[] = { 3,1,6,7,8,2,1,1,5,6,7,6 };
	for(auto e : arr)
    {
        my_set.Insert(e);
    }
    zw::unordered_set<int>::iterator it = my_set.begin();
    while(it != my_set.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

}

void test_map1()
{
    zw::unordered_map<string, string> dict;
    dict.Insert({"sort" , "1234"});
    dict.Insert({"string" , "5678"});
    for(auto& kv : dict)
    {
        cout << kv.first << ":" << kv.second << endl;
    }
}

int main()
{
    //Test1();
    test_set1();
    test_map1();
    return 0;
}