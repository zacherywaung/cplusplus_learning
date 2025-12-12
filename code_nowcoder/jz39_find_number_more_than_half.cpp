// JZ39 数组中出现次数超过一半的数字
// 给一个长度为 n 的数组，数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
// 例如输入一个长度为9的数组[1,2,3,2,2,2,5,4,2]。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
// 空间复杂度：O(1)，时间复杂度 O(n)
// 输入：
// [1,2,3,2,2,2,5,4,2]
// 返回值：
// 2

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        int cur_number = numbers[0];
        size_t count = 1;
        int i = 0;
        for(i = 1; i < numbers.size(); i++)
        {
            if(numbers[i] == cur_number)
            {
                count++;
            }
            else if(count > 0)
            {
                count--;
            }
            else {
                count++;
                cur_number = numbers[i];
            }
        }
        return cur_number;
    }
};