// Source : https://leetcode.com/problems/divide-two-integers
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference: https://discuss.leetcode.com/topic/15568/detailed-explained-8ms-c-solution
// Idea: example: 17/3. 17=3*2^2+3*2^0+2, the last 2 can be ignored. Answer is (2^2+2^0). Only works for positive numbers.

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        if (divisor == -1 && dividend == INT_MIN) return INT_MAX;
        int sign = (dividend < 0)^(divisor < 0) ? -1 : 1;
        long long dividendP = labs(dividend);
        long long divisorP = labs(divisor);
        long long resu = 0, reminder = dividendP;
        while(reminder>=divisorP) {
            long long temp = divisorP, power = 1; //this will handle overflow
            while(temp <= reminder) {
                temp = temp<<1;
                power = power<<1;
            }
            temp = temp>>1;
            power = power>>1;
            resu = resu + power;
            reminder = reminder - temp;
        }
        return (sign < 0) ? (-resu) : resu;
    }
};
