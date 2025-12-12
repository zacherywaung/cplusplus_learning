// leetcode26 Remove Duplicate From Sorted Array
// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

// Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.
// The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.
// Custom Judge:
// The judge will test your solution with the following code:

// int[] nums = [...]; // Input array
// int[] expectedNums = [...]; // The expected answer with correct length

// int k = removeDuplicates(nums); // Calls your implementation

// assert k == expectedNums.length;
// for (int i = 0; i < k; i++) {
//     assert nums[i] == expectedNums[i];
// }
// If all assertions pass, then your solution will be accepted.

// Example 1:

// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).
// Example 2:

// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

#include<iostream>
#include<vector>
using namespace std;

// not recommmended
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int cur = nums[0];
//         int i = 1;
//         if(nums.size() == 1)
//         {
//             return 1;
//         }
//         int stop_sign = nums.back();
//         if(nums[0] == stop_sign)
//         {
//             return 1;
//         }
//         while(nums[i] != stop_sign)
//         {
//             if(nums[i] == cur)
//             {
//                 int tmp = nums[i];
//                 nums.erase(nums.begin() + i);
//                 nums.push_back(tmp);
//             }
//             else{
//                 cur = nums[i];
//                 i++;
//             }
//         }
//         return i+1;
//     }
// };

// int main()
// {
//     vector<int> nums{1,2};
//     cout << Solution().removeDuplicates(nums) << endl;
//     return 0;
// }

// use double pointer
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while(fast < nums.size())
        {
            if(nums[slow] == nums[fast])
            {
                fast++;
            }
            else{
                nums[++slow] = nums[fast++];
            }
        }
        return slow + 1;
    }
};