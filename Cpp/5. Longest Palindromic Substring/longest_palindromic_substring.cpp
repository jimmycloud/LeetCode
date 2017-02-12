// Source : https://leetcode.com/problems/longest-palindromic-substring/
// Author : Jimmy Liu
// Date   : 2017-02-11
// Reference: http://www.cnblogs.com/TenosDoIt/p/3675788.html
// Idea: start from each element as center, check its left and right. Odd and Even cases are considered seperately.

/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;
        int n = s.length();
        int maxLen = 0, minInd = 0, maxInd = n;
    
        for (int i = 0; i < n; i++) {
            //use i as center, check i-j to i+j
            int j = 0;
            while(j <= i && j <= n - 1 - i) {
                if (s[i - j] == s[i + j]) {
                    j++;
                } else {
                    break;
                }
            }
            j--;
            if (2 * j + 1 > maxLen) {
                minInd = i - j;
                maxInd = i + j;
                maxLen = 2 * j + 1;//forgot to update maxLen
            }
            //use i as center, check i-j+1 to i+j
            int k = 0;
            while(k <= i && i + k + 1 <= n - 1) {
                if (s[i - k]==s[i + k + 1]) {
                    k++;
                } else {
                    break;
                }
            }
            k--;
            if (2 * k + 2 > maxLen) {
                minInd = i - k;
                maxInd = i + k + 1;
                maxLen = 2 * k + 2; //forgot to update maxLen
            }
        }
        return s.substr(minInd, maxInd - minInd + 1);
    }
};
