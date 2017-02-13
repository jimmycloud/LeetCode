// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference: 
// Idea: 

/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p=head;
        if (head==NULL) return head;
        while(p!=NULL && p->next !=NULL) //forgot to check if p!=NULL
        {
            if (p->next->val==p->val)
            {
                ListNode* temp=p->next;
                p->next=p->next->next;
                delete temp;
            } else { p=p->next;} //pay attention to the else. Test case can be [1, 1, 1], and therefor p is not moved to next every time.
        }
        return head;
    }
};
