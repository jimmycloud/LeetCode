// Source : https://leetcode.com/problems/intersection-of-two-linked-lists/
// Author : Jimmy Liu
// Date   : 2017-01-22
// Reference
// Idea: keep a record of previous max position that can be reached, when iterator touches this pre max pos, update it as well as count

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
*/


class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size()<=1) return 0;
        int maxPos = 0, count = 0, preMaxPos = 0;
        for (int i=0; i<nums.size(); i++)
        {
            maxPos = max (maxPos, i+nums[i]);
            if (i==preMaxPos) {
                count++;
                preMaxPos=maxPos;
            }
            //if (maxPos >= nums.size()-1) { <-made a mistake here
            if (preMaxPos>=nums.size()-1) {
                return count;
            }
        }
    }
};
