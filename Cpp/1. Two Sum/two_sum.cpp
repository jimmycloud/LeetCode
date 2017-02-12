// Source : https://leetcode.com/problems/two-sum/
// Author : Jimmy Liu
// Date   : 2017-02-11
// Reference: 
// Idea: classicical hash table problem. 


/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
public:
vector<int> twoSum(vector<int> &numbers, int target) 
{
    unordered_map <int, int> table;
    vector<int> resu;
    int i, N = numbers.size();
    for (i = 0; i < N; i++)
    {
        table[numbers[i]] = i;
    }
    int temp;
    for (i = 0; i < N; i++)
    {
        temp = target-numbers[i];
       
        if (table.find(temp) != table.end() && table[temp] != i) //find
        {
            resu.push_back(i);
            resu.push_back(table[temp]);
            return resu;
        }
    }
    return resu;
}
};
