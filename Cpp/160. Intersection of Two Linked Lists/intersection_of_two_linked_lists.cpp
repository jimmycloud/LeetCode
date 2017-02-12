// Source : https://leetcode.com/problems/intersection-of-two-linked-lists/
// Author : Jimmy Liu
// Date   : 2017-01-21
// Reference: https://discuss.leetcode.com/topic/5527/my-accepted-simple-and-shortest-c-code-with-comments-explaining-the-algorithm-any-comments-or-improvements
// Ideas: idea 1. p1 iterates over list1 & list2, p2 iterates over list2 & list1, if any intersecton, p1 and p2 will meet.
//        idea 2. find lengths of list1 and list2, get the difference, and let p1 move k steps first before p2 moves.
/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        if (p1 == NULL || p2 == NULL) return NULL;
        while(p1 != NULL && p2 != NULL && p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
            if (p1 == p2) return p1;
            if (p1 == NULL) p1 = headB;
            if (p2 == NULL) p2 = headA;
        }
        return p1;
    }
};
