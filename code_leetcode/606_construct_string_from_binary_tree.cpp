// leetcode606 Construct String From Binary Tree  mid

// Given the root node of a binary tree, your task is to create a string representation of the tree following a specific set of formatting rules. The representation should be based on a preorder traversal of the binary tree and must adhere to the following guidelines:

// Node Representation: Each node in the tree should be represented by its integer value.

// Parentheses for Children: If a node has at least one child (either left or right), its children should be represented inside parentheses. Specifically:

// If a node has a left child, the value of the left child should be enclosed in parentheses immediately following the node's value.
// If a node has a right child, the value of the right child should also be enclosed in parentheses. The parentheses for the right child should follow those of the left child.
// Omitting Empty Parentheses: Any empty parentheses pairs (i.e., ()) should be omitted from the final string representation of the tree, with one specific exception: when a node has a right child but no left child. In such cases, you must include an empty pair of parentheses to indicate the absence of the left child. This ensures that the one-to-one mapping between the string representation and the original binary tree structure is maintained.

// In summary, empty parentheses pairs should be omitted when a node has only a left child or no children. However, when a node has a right child but no left child, an empty pair of parentheses must precede the representation of the right child to reflect the tree's structure accurately.
// example 1
// Input: root = [1,2,3,4]
// Output: "1(2(4))(3)"
// example 2 
// Input: root = [1,2,3,null,4]
// Output: "1(2()(4))(3)"


#include<iostream>
#include<string>
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
    string tree2str(TreeNode* root) {
        string s;
        recursive(s, root);
        return s;
    }

    void recursive(string& s, TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        s += to_string(root->val);
        if(root->left == nullptr && root->right == nullptr)
        {
            return;
        }
        s.push_back('(');
        recursive(s, root->left);
        s.push_back(')');
        if(root->right == nullptr)
        {
            return;
        }
        s.push_back('(');
        recursive(s, root->right);
        s.push_back(')');
    }    
};