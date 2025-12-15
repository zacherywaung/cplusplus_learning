//Leetcode102 Binary Tree Level Order Traversal

// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]

// Example 2:
// Input: root = [1]
// Output: [[1]]

// Example 3:
// Input: root = []
// Output: []



#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == nullptr)
        {
            return ret;
        }
        vector<int> v;
        int level_size = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            while(level_size != 0)
            {
                TreeNode* pfront = q.front();
                v.push_back(pfront->val);
                q.pop();
                if(pfront->left)
                {
                    q.push(pfront->left);
                }
                if(pfront->right)
                {
                    q.push(pfront->right);
                }
                level_size--;
            }
            level_size = q.size();
            ret.push_back(v);
            v.clear();
        }
        return ret; 
    }
};