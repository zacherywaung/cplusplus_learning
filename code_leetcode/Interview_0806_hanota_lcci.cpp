// leetcode Interview 0806 Hanota LCCI

// In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of different sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending order of size from top to bottom (i.e., each disk sits on top of an even larger one). You have the following constraints:

// (1) Only one disk can be moved at a time.
// (2) A disk is slid off the top of one tower onto another tower.
// (3) A disk cannot be placed on top of a smaller disk.

// Write a program to move the disks from the first tower to the last using stacks.

// Example1:

//  Input: A = [2, 1, 0], B = [], C = []
//  Output: C = [2, 1, 0]

// Example2:

//  Input: A = [1, 0], B = [], C = []
//  Output: C = [1, 0]

#include<vector>
using namespace std;
class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        int n = A.size();
        dfs(A, B, C, n);
    }

    void dfs(vector<int>& A, vector<int>& B, vector<int>& C, int n)
    {
        if(n == 0)
        {
            return;
        }
        dfs(A, C, B, n-1);
        int num = A.back();
        A.pop_back();
        C.push_back(num);
        dfs(B, A, C, n-1);
    }
};