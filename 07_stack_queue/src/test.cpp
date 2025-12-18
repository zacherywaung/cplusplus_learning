#include<iostream>
#include"../include/stack.h"
#include"../include/queue.h"
#include"../include/priority_queue.h"
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

void Test_queue()
{
    zw::queue<int> qe;
    qe.push(1);
    qe.push(2);
    qe.push(3);
    qe.push(4);
    qe.pop();
    qe.push(5);
    qe.push(6);
    qe.pop();
    cout << qe.top() << endl;
    cout << qe.size() << endl;
    cout << qe.empty() << endl;
    qe.pop();
    qe.pop();
    qe.pop();
    qe.pop();
    cout << qe.empty() << endl;
}

void Test_priority_queue()
{
    vector<int> v = {2, 5, 8, 1, 2, 7, 4, 6};
    zw::priority_queue<int> maxHeap(v.begin(), v.end());
    zw::priority_queue<int, vector<int>, greater<int>> minHeap(v.begin(), v.end());
    maxHeap.push(10);
    maxHeap.push(1);
    maxHeap.pop();
    maxHeap.pop();
    cout << maxHeap.top() << endl;
    minHeap.push(10);
    minHeap.push(1);
    minHeap.pop();
    minHeap.pop();
    cout << minHeap.top() << endl;
}

int main()
{
    // Test_stack();
    // Test_queue();
    Test_priority_queue();
    return 0;
}