// Source : https://leetcode.com/problems/jump-game-ii
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference: 
// Idea: check the max position can be reached from current position, 
//       check if max position is the last element, count the number of jumps to go the max position

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/
 
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) 
            return 0;
        int maxPos = 0, count = 0, preMaxPos = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxPos = max(maxPos, i + nums[i]);
            if (i == preMaxPos) {
                count++;
                preMaxPos = maxPos;
            }
            //if (maxPos >= nums.size()-1) { <-made a mistake here
            if (preMaxPos >= nums.size() - 1) {
                return count;
            }
        }
    }
};
