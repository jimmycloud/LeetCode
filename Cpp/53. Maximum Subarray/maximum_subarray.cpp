// Source : https://leetcode.com/problems/maximum-subarray/
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference: 
// Idea: 

/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        
        int currentMax=nums[0];
        int maxSum=nums[0];
        for (int i=1; i< nums.size(); i++)
        {
            currentMax = max(nums[i], nums[i]+currentMax);
            maxSum=max(maxSum, currentMax);
        }
        return maxSum;
    }
};
