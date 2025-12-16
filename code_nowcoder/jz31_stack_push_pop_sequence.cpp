// jz31 栈的压入弹出序列
// 描述
// 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
// 1. 0<=pushV.length == popV.length <=1000
// 2. -1000<=pushV[i]<=1000
// 3. pushV 的所有数字均不相同

// [1,2,3,4,5],[4,5,3,2,1] true
// [1,2,3,4,5],[4,3,5,1,2] false


#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pushV int整型vector 
     * @param popV int整型vector 
     * @return bool布尔型
     */
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        vector<int>::iterator it = pushV.begin();
        stack<int> st;
        size_t index = 0;
        while(index < popV.size() && it != pushV.end())
        {
            int val = *it;
            st.push(val);
            it++;
            while((!st.empty()) && st.top() == popV[index])
            {
                st.pop();
                index++;
            }
        }
        return index == popV.size();
    }
};