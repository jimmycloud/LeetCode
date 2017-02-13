// Source : https://leetcode.com/problems/search-insert-position/
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference: 
// Idea: 

/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m = (l + r) / 2;
        if (target <= nums[l]) return l;
        if (nums[r] < target) return r + 1;
        
        //now deal with the case nums[l]<target<nums[r]
        while(l <= r) {
            if (nums[m] == target) return m;
            if (nums[m] < target) {
                l = m + 1;
            }
            if (nums[m] > target) {
                r = m - 1;
            }
            m = (l + r) / 2;
        }
        return l;
    }
};
