// Source : https://leetcode.com/problems/3sum-closest/
// Author : Jimmy Liu
// Date   : 2017-02-11
// Reference: 
// Idea: 

/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
          sort(nums.begin(), nums.end());
          int diff = abs(target - nums[0] - nums[1] - nums[2]);
          int res = nums[0] + nums[1] + nums[2];
          for (int i = 0; i < nums.size() - 2; i++) {
             int j = i + 1, k = nums.size()-1;
             while(j < k) {
               if (abs(nums[j] + nums[k] + nums[i] - target)<diff) {
                  diff = abs(target - nums[i] - nums[j] - nums[k]);
                  res=nums[i]+nums[j]+nums[k];
               }
               if (nums[i]+nums[j]+nums[k]<=target) {
                  j++;
               } else { 
                  k--;
               }
             }
          }
          return res;
        }
};
