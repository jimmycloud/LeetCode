// Source : https://leetcode.com/problems/merge-two-sorted-lists/
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference: 
// Idea: 

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Show Company Tags
Show Tags
Show Similar Problems
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * p1 = l1, * p2 = l2;
        if (p1 == NULL) 
            return p2;
        if (p2 == NULL) 
            return p1;
        ListNode *p = new ListNode(0);
        ListNode *dummy = p;
        while(p1 != NULL && p2 != NULL) {
            if (p1->val < p2->val) {
                p->next = p1; 
                p1 = p1->next;
            } else {
                p->next = p2; 
                p2 = p2->next;
            }
            p = p->next;
        }
        //now one of them is NULL
        if (p1 == NULL) {
            p->next=p2;
        } else {
            p->next=p1;
        }
        return dummy->next;
    }
};
