// Source : https://leetcode.com/problems/reverse-integer/
// Author : Jimmy Liu
// Date   : 2017-02-11
// Reference: 
// Idea: use long long int to avoid overflow.

/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
*/

class Solution {
public:
    int reverse(int x) {
        long long int temp=0;
        while (x!=0) {
            temp=10*temp+x%10;
            x=x/10;
        }
        if (temp<INT_MIN || temp>INT_MAX) return 0;
        return temp;
    }
};
