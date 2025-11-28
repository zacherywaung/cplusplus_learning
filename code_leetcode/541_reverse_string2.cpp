// 541 Reverse String 2
// Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

// If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.

 

// Example 1:

// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"
// Example 2:

// Input: s = "abcd", k = 2
// Output: "bacd"
#include<iostream>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 1;
        int j = 1;
        int end = s.size() - 1;
    //[i*k - k, i*k - 1]
    //or
    //[j*2*k - 2*k, j*2*k - k - 1]
    //both is ok
        while(j*2*k - 1 <= end)
        {
            myReverse(s, j*2*k - 2*k, j*2*k - k - 1); // or [i*k - k, i*k - 1]
            i += 2;
            j++;
        }
        end = (i*k - 1) >= end ? end : (i*k - 1); // or j*2*k - k - 1
        myReverse(s, i*k - k, end);
        return s;
    }

    void myReverse(string& s, int left, int right)
    {
        if(left >= right)
            return;
        while(left < right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};