//415 Add Strings
// Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

// You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

// Example 1:

// Input: num1 = "11", num2 = "123"
// Output: "134"
// Example 2:

// Input: num1 = "456", num2 = "77"
// Output: "533"
// Example 3:

// Input: num1 = "0", num2 = "0"
// Output: "0"
#include<iostream>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        int single_sum = 0;
        string ret_string;
        string::reverse_iterator it1 = num1.rbegin();
        string::reverse_iterator it2 = num2.rbegin();
        while(it1 != num1.rend() && it2 != num2.rend())
        {
            single_sum = (*it1 + *it2 + carry - 2*'0') % 10;
            carry = (*it1 + *it2 + carry - 2*'0') / 10;
            ret_string += to_string(single_sum);
            it1++;
            it2++;
        }
        while(it1 != num1.rend())
        {
            single_sum = (*it1 + carry - '0') % 10;
            carry = (*it1 + carry - '0') / 10;
            ret_string += to_string(single_sum);
            it1++;
        }
        while(it2 != num2.rend())
        {
            single_sum = (*it2 + carry - '0') % 10;
            carry = (*it2 + carry - '0') / 10;
            ret_string += to_string(single_sum);
            it2++;
        }
        if(carry == 1)
        {
            ret_string += '1';
        }

        reverse(ret_string.begin(), ret_string.end());
        return ret_string;
    }
};