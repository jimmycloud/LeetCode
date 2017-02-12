// Source : https://leetcode.com/problems/palindrome-number/
// Author : Jimmy Liu
// Date   : 2017-02-11
// Reference: https://discuss.leetcode.com/topic/12820/an-easy-c-8-lines-code-only-reversing-till-half-and-then-compare/2
// Idea: 

/*
Determine whether an integer is a palindrome. Do this without extra space.
*/

class Solution {
public:
     bool isPalindrome(int x) {
        if (x == INT_MIN || x == INT_MAX || x < 0) return false;
        if (x < 10) return true;
        int temp = 0, tempx = x;
        while(x > 0) {
            temp = temp * 10 + x % 10;
            x = x / 10;
        }
        return temp == tempx;
    }
};
