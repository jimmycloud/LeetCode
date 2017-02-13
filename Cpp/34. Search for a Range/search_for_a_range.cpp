// Source : https://leetcode.com/problems/search-for-a-range
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference: 
// Idea: 

/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        if (nums.size() == 0) return res;
        res[0] = searchRangeBinaryLeft(nums, target, 0, nums.size() - 1);
        res[1] = searchRangeBinaryRight(nums, target, 0, nums.size() - 1);
        return res;
    }
    //look for the left position
    int searchRangeBinaryLeft(vector<int> & nums, int target, int left, int right) {
        if (right < left || left == right && nums[left] != target) return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            return searchRangeBinaryLeft(nums, target, mid + 1, right); //!!! important!!! error!!!! need to search from [mid+1, right], not [mid, right]
        } else if (nums[mid] > target) {
            return searchRangeBinaryLeft(nums, target, left, mid - 1);
        } else {
            //nums[mid] == target
            int temp = searchRangeBinaryLeft(nums, target, left, mid - 1);
            return (temp != -1) ? temp : mid;
        }
    }
    //look for the left position
    int searchRangeBinaryRight(vector<int> & nums, int target, int left, int right) {
        if (right < left || (left == right && nums[left] != target)) return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            int temp = searchRangeBinaryRight(nums, target, mid + 1, right);
            return temp;
        } else if (nums[mid] > target) {
            return searchRangeBinaryRight(nums, target, left, mid - 1);
        } else {//nums[mid]==target
            int temp = searchRangeBinaryRight(nums, target, mid + 1, right);
            return (temp != -1) ? temp : mid;
        }
    }
};
