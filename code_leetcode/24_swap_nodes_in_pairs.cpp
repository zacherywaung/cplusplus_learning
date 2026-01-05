// leetcode24 Swap Nodes In Pairs  mid
// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
// Example 1:
// Input: head = [1,2,3,4]
// Output: [2,1,4,3]

// Example 2:
// Input: head = []
// Output: []

// Example 3:
// Input: head = [1]
// Output: [1]

// Example 4:
// Input: head = [1,2,3]
// Output: [2,1,3]


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
    ListNode* swapPairs(ListNode* head) {
        return dfs(head);
    }

    ListNode* dfs(ListNode* head)
    {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;

        ListNode* nexthead = dfs(head->next->next);
        ListNode* ret = head->next;
        ret->next = head;
        head->next = nexthead;
        return ret;
    }
};
