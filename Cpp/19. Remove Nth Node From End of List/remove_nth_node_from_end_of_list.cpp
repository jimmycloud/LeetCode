// Source : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author : Jimmy Liu
// Date   : 2017-02-11
// Reference: 
// Idea: two pointers/indices, one is n step faster than the other.
//       special case is to remove the first element. For this case, fast pointer already moves to the null.

/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode fast = head, slow = head;
        for (int k = 0; k < n; k++) {
            fast = fast.next;
        }
        
        // deal with the case that slow is the last node
        if (fast == null) {
            return head.next; // Do I need to delete first head node ???
        }
        
        // general case
        // attnetion: if fast!=null instead, wrong
        while(fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }
        // now slow.next points to the node to skip
        slow.next = slow.next.next;
        return head;
    }
}
