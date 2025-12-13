// leetcode 17  Letter Combinations Of A Phone Number
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
//  0   1     2      3      4      5      6     7        8       9
// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = "2"
// Output: ["a","b","c"]

//structure:
// void backtrack(parameters)
// {
//     //base case
//     if(end condition)
//     {
//         store result;
//         return;
//     }
//     // traverse current row in decision tree
//     for(...)
//     {
//         deal with the current node;
//         backtrack(...);
//         undo step;
//     }
// }




#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string path;
        size_t index = 0;
        backtracking(ret, digits, path, index, dict);
        return ret;
    }

    void backtracking(vector<string>& ret, string digits, string path, size_t index, vector<string>& dict)
    {
        // base case
        if(index == digits.size())
        {
            ret.push_back(path);
            return;
        }
        // traverse current row
        for(int i = 0; i < dict[digits[index] - '0'].size(); i++)
        {
            path += dict[digits[index] - '0'][i];
            backtracking(ret, digits, path, ++index, dict);
            // undo
            --index;
            path.pop_back();
        }
    }
    
};

int main()
{
    string digits("23");
    vector<string> answer = Solution().letterCombinations(digits);
    return 0;
}