// Source : https://leetcode.com/problems/permutations/
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference: 
// Idea: some backtracking solutions to this problem with boolean indicator are unnecessarily complicated in structure.

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0) 
            return res;
        vector<int> current(0);
        vector<bool> used(nums.size(), false);
        permuteBackTrack(res, nums, current, used);
        return res;
    }
    void permuteBackTrack(vector<vector<int>> & res, vector<int> & nums, vector<int> & current, vector<bool> & used) {
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == false) {
                current.push_back(nums[i]);
                if (current.size() == nums.size()) { 
                    res.push_back(current); 
                }
                used[i] = true;
                permuteBackTrack(res, nums, current, used);
                used[i] = false;
                current.pop_back();
            }
        }
    }
};
