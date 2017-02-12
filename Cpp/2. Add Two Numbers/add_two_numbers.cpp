
// Source : https://leetcode.com/problems/add-two-numbers/
// Author : Jimmy Liu
// Date   : 2017-02-11
// Reference:
// Idea: 

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode *pp = new ListNode(0);//p is dummy, p-> next is the head
      ListNode *p = pp;
      int carry=0;
      while(l1 != NULL || l2 != NULL)
      {
        int v1 = (l1 == NULL) ? 0 : l1->val;
        int v2 = (l2 == NULL) ? 0 : l2->val;
        int tempv = v1+v2+carry;
        p->next = new ListNode(tempv%10);
        carry = (tempv-tempv%10)/10; //forgot to divide by 10
        p = p->next;
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
      }
      if (carry!=0) p->next = new ListNode(carry); //forgot to check carry
      return pp->next;
   }
};
