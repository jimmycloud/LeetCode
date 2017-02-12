// Source : https://leetcode.com/problems/intersection-of-two-linked-lists/
// Author : Jimmy Liu
// Date   : 2017-01-21
// Reference
// Idea: check the max index that can be reached from current position.

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int max_reach = 0; //max_reach indicates the max index that can be jumped from current position, base 0
        for (int i = 0; i < len; i++)
        {
            max_reach = max(max_reach, i + nums[i]);//max_reach = max(max_reach, (max_reach>=i)?(i+nums[i]):i);
            if (max_reach >= len-1) return true;
            if (max_reach < i+1) return false;
        }
    }
};
