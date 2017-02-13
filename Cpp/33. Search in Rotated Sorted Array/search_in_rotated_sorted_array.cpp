// Source : https://leetcode.com/problems/search-in-rotated-sorted-array/
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference: http://blog.csdn.net/linhuanmars/article/details/20525681
// Idea: 

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m = (l + r) / 2;
        while(l <= r)
        {
            if (nums[m] == target) return m;
            if (nums[l] <= nums[m]) { //left half sorted  <--- wrong if nums[l] < nums[m]
                if (target >= nums[l] && target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else { //right half sorted
                if (target > nums[m] && target <= nums[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            m = (l + r) / 2;
        }
        return -1;
    }
};

