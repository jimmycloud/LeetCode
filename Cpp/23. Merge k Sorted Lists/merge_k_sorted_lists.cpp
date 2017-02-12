// Source : https://leetcode.com/problems/merge-k-sorted-lists/
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference: http://bangbingsyb.blogspot.com/2014/11/leetcode-merge-k-sorted-lists.html
// Idea: 

/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i = 0, j = lists.size() - 1;
        if (j == -1) return nullptr;
        while(j > 0) {
            i = 0;
            while(i < j) {//made a mistake here, i and j may cross, so i!=j is not equivalent to i<j
                lists[i] = merge2Lists(lists[i], lists[j]);
                i++;
                j--;
            }
        }
        return lists[0];
    }
    ListNode* merge2Lists(ListNode* p1, ListNode*p2) {
        if (p1 == nullptr) return p2;
        if (p2 == nullptr) return p1;
        ListNode *p = new ListNode(0);
        ListNode *dummy = p;
        while(p1 != NULL && p2 != NULL) {
            if (p1->val < p2->val) {
                p->next = p1; p1 = p1->next;
            } else {
                p->next = p2; 
                p2 = p2->next;
            }
            p = p->next;
        }
        //one of two pointers is NULL
        if (p1 == NULL) {
            p->next = p2;
        } else {
            p->next = p1;
        }
        return dummy->next;
    }
};
