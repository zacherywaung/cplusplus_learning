// leetcode137 Single Number 2       medium
// Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

// You must implement a solution with a linear runtime complexity and use only constant extra space.
// Example 1:

// Input: nums = [2,2,3,2]
// Output: 3
// Example 2:

// Input: nums = [0,1,0,1,0,1,99]
// Output: 99
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(size_t k = 0; k < 32; k++)
        {
            int n = 0;
            for(size_t i = 0; i < nums.size(); i++)
            {
                n += (nums[i] >> k) & 1;
            }
            ret += (n % 3) * (1 << k);
        }
        return ret;
    }
};

int main()
{
    vector<int> v{2, 2, 3, 2};
    int ret = Solution().singleNumber(v);
    return 0;
}