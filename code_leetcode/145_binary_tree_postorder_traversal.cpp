//leetcode145 Binary Tree Postorder Traversal
// Given the root of a binary tree, return the postorder traversal of its nodes' values.

// Example 1:

// Input: root = [1,null,2,3]

// Output: [3,2,1]

// Example 2:

// Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

// Output: [4,6,7,5,2,9,8,3,1]

// Follow up: Recursive solution is trivial, could you do it iteratively?
#include<vector>
#include<stack>
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ret;
        if(root == nullptr)
        {
            return ret;
        }
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            if(node->left)
            {
                st.push(node->left);
            }
            if(node->right)
            {
                st.push(node->right);
            }
            ret.push_back(node->val);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};