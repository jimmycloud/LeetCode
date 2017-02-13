
// Source : https://leetcode.com/problems/powx-n/
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference:
// Idea: 

/*
Implement pow(x, n).
*/

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        double t = myPow(x, n / 2);
        if (n%2 == 0) { 
            return t * t; 
        } else {
            if (n < 0) return 1 / x * t * t;
            if (n > 0) return x * t * t;
        }
    }
};
