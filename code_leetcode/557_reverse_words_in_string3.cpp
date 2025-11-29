// 557 Reverse Words in String 3
// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

// Example 1:

// Input: s = "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
// Example 2:

// Input: s = "Mr Ding"
// Output: "rM gniD"

// Constraints:

// 1 <= s.length <= 5 * 104
// s contains printable ASCII characters.
// s does not contain any leading or trailing spaces.
// There is at least one word in s.
// All the words in s are separated by a single space.

#include<iostream>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int prev = 0;
        int cur = 0;
        int i = 0;
        for(i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                cur = i;
                reverse(s.begin() + prev, s.begin() + cur);
                prev = i + 1;
            }
        }
        if(prev != cur)
        {
            reverse(s.begin() + prev, s.end());
        }
        if(cur == 0)
        {
            reverse(s.begin(), s.end());
        }
        return s;
    }
};

int main()
{
    string s("Let's take LeetCode contest");
    cout << Solution().reverseWords(s) << endl;
}