// 125 Valid Palindrome
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:

// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.

#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int key = 0;
        string ss;
        for(key = 0; key < s.size(); key++)
        {
            if((s[key] >= 'A' && s[key] <= 'Z')
            || s[key] >= 'a' && s[key] <= 'z'
            || s[key] >= '0' && s[key] <= '9')
                ss += s[key];
        }
        if(ss.size() == 0)
            return true;
        for(auto& ch : ss)
        {
            if(ch >= 'A' && ch <= 'Z')
            {
                ch += 32;
            }
        }
        int begin = 0;
        int end = ss.size() - 1;
        while(ss[begin++] == ss[end--] && begin < end)
        {
            ;
        }
        if(ss[--begin] != ss[++end])
            return false;
        return true;
    }
};

int main()
{
    string s("A man, a plan, a canal: Panama");
    cout << Solution().isPalindrome(s) << endl;

    return 0;
}