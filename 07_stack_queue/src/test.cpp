#include<iostream>
#include"../include/stack.h"
using namespace std;

void Test_stack()
{
    zw::stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.pop();
    st.push(5);
    st.push(6);
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;
    cout << st.empty() << endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout << st.empty() << endl;
}


int main()
{
    Test_stack();
    return 0;
}