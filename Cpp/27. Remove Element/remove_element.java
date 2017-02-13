// Source : https://leetcode.com/problems/merge-k-sorted-lists/
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference: https://leetcode.com/discuss/60493/beat-90%25-fast-java-simple-solution-with-explanation
// Idea: 

/*
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.
*/

public class Solution {
    public int removeElement(int[] nums, int val) {
        int N = nums.length, M = nums.length;
        if (N == 0) return 0;
        if (N == 1) return (nums[0] == val ? 0 : 1);
        int i = 0, j = 0; //j is the pointer iterate over, i points to the place of putting !=val values
        for (j = 0; j < N; j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
}
