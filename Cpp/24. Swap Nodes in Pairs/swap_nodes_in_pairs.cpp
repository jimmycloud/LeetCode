// Source : https://leetcode.com/problems/merge-k-sorted-lists/
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference: https://leetcode.com/problems/swap-nodes-in-pairs/
// Idea: 

/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *p1 = head, *p2 = p1->next;
        ListNode *dummy = new ListNode(0);
        dummy->next = p2;
        ListNode* current = dummy;
        while(p1 != NULL) {
            if (p2 != NULL) {
                ListNode* temp = p2->next;
                p1->next = temp;
                p2->next = p1;
                current->next = p2;
                p1 = temp;
                p2 = (p1 != NULL) ? p1->next : NULL; //initially set p2=p1->next but p1 might be null
                current = current->next->next;
            } else {
                current->next = p1;
                return dummy->next;
            }
        }
        return dummy->next;
    }
};
