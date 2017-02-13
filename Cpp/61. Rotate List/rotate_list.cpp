
// Source : https://leetcode.com/problems/search-for-a-range
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference: 
// Idea: 

/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;
        ListNode * p1 = head;
        int n = 1;
        while(p1->next != NULL) {
            n++;
            p1 = p1->next;
        }//now p1 is the last element
        if (k > n) k = k % n;
        p1->next = head;
        for (int i = 0; i < n - k; i++) {
            p1 = p1->next;
        }
        ListNode *p2 = p1->next;
        p1->next = NULL;
        return p2;
    }
};
