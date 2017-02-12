// Source : https://leetcode.com/problems/generate-parentheses/
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference: http://www.programering.com/a/MjN1ATMwATM.html
// Idea: Recursive. Keep track of the number of left parentheses and right parentheses. 
//       Strictly more left => can add either left or right. Same left and right => can add left. 

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n == 0) {    
            return result;
        } else {
            string cur;
            helper(result, 0, 0, n, cur);   
        }
        return result;
    }
    void helper(vector<string> &res, int leftP, int rightP, int N, string current) {
        //recursive
        //4 cases:  (1) current number of left'(' == right')' but not enough
        //          (2) current left'(' > right')' but left( < N
        //          (3) current left( > right), but left( =N
        //          (4) all matched and both are N.
        if (leftP == N && rightP == N) {
            res.push_back(current);
            return;
        } else if (leftP == rightP) {
            current.push_back('(');
            helper(res, leftP+1, rightP, N, current);
        } else if (leftP > rightP && leftP < N) {
            string current1 = current, current2 = current;
            current1.push_back('(');
            current2.push_back(')');
            helper(res, leftP+1, rightP, N, current1);
            helper(res, leftP, rightP+1, N, current2);
        } else {
            current.push_back(')');
            helper(res, leftP, rightP+1, N, current);
        }
    }
};
