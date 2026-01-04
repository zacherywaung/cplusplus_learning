// leetcode21 Merge Two Sorted Lists
// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

// Example 1:
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:
// Input: list1 = [], list2 = []
// Output: []

// Example 3:
// Input: list1 = [], list2 = [0]
// Output: [0]


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
   ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return dfs(list1, list2);
    }

    ListNode* dfs(ListNode* l1, ListNode* l2)
    {
        if(l1 == nullptr)
        {
            return l2;
        }
        else if(l2 == nullptr)
        {
            return l1;
        }
        if(l1->val < l2->val)
        {
            l1->next = dfs(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = dfs(l1, l2->next);
            return l2;
        }
    }
};