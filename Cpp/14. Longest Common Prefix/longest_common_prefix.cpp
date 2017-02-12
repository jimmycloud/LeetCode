// Source : https://leetcode.com/problems/longest-common-prefix/
// Author : Jimmy Liu
// Date   : 2017-02-11
// Reference: 
// Idea: brute force

/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        int m = strs.size(), n = strs[0].length();
        string res = "";
        for (int j = 0; j < n; j++) {
            for (int i = 1; i < m; i++) {
                if (j == strs[i].length() || strs[i][j] != strs[0][j]) 
                    return res;
            }
            res += strs[0][j];
        }
        return res;
    }
};
