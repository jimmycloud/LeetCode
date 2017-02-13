// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference: http://bangbingsyb.blogspot.com/2014/11/leetcode-merge-k-sorted-lists.html
// Idea: 

/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

// Note: pay attention to the condition - sorted array
public class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length <= 1) {
            return nums.length;
        }
        int i = 0, j = i + 1; //i point to numbers to keep, j point to numbers to check
        while(j<nums.length) {
            if (nums[j]==nums[i]) { 
                j++; 
            } else {
                i++;
                nums[i]=nums[j];
                j++;
            }
        }
        return i+1;
    }
}
