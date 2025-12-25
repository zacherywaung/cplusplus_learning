//leetcode105 Construct Binary Tree From Preorder and Inorder Traversal  mid
//
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
// Example 1:
// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]

// Example 2:
// Input: preorder = [-1], inorder = [-1]
// Output: [-1]


#include<vector>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* ret = recursive(preorder, 0, inorder, 0, inorder.size() - 1);
        return ret;
    }
    TreeNode* recursive(vector<int>& preorder, int preleft,
                        vector<int>& inorder, int inleft, int inright)
    {
        if(inleft > inright)
        {
            return nullptr;
        }
        TreeNode* newnode = new TreeNode(preorder[preleft]);
        int pindex = inleft;
        while(inorder[pindex] != preorder[preleft])
        {
            pindex++;
        }

        newnode->left = recursive(preorder, preleft + 1, inorder, inleft, pindex - 1);
        newnode->right = recursive(preorder, preleft + pindex - inleft + 1, inorder, pindex + 1, inright);
        return newnode;
    }
};