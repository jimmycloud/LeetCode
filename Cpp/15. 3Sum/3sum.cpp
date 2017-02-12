// Source : https://leetcode.com/problems/3sum/
// Author : Jimmy Liu
// Date   : 2017-02-11
// Reference: 
// Idea: extension of 2 sum, need to pay attention to duplicates

/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
Show Company Tags
Show Tags
Show Similar Problems
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            vector<int> temp;
            if (i > 0 && nums[i-1] == nums[i]) continue;
            int j = i + 1, k = n - 1, target = -nums[i];
            while(j < k) {
                if (nums[j] + nums[k] == target) {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    res.push_back(temp);
                    temp.clear();
                    j++;
                    k--;
                    while (j < nums.size() && nums[j] == nums[j-1]) j++;
                    while (k > j && nums[k+1] == nums[k]) k--;
                } else if (nums[j] + nums[k] < target) {
                    j++;                       //We dont need while loop to skip dup
                } else {                       //because dups are not satisfactory.
                    k--;                       //
                }
            }
        }
        return res;
    }
};
