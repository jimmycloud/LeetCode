// Source : https://leetcode.com/problems/add-binary
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference: 
// Idea:

/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int m = a.size(), n = b.size();
        int k = 0, carry = 0;
        while(k < max(m,n) || carry > 0) {
            int i = (k < m) ? (a[m - 1 -k] - '0') : 0;
            int j = (k < n) ? (b[n - 1 - k] - '0') : 0;
            res.insert(res.begin(),char('0' + ((i + j + carry) % 2)));
            carry = (i + j + carry) / 2;//carry should be updated after res is updated
            k++;
        }
        return res;
    }
};
