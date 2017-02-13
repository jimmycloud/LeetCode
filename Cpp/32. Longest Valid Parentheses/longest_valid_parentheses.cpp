// Source : https://leetcode.com/problems/merge-k-sorted-lists/
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference: http://leetcodenotes.wordpress.com/2013/10/19/leetcode-longest-valid-parentheses
// Idea: 
// The question looks for valid sequences: (()) is also valid
// v1: idea -  save the valid parentheses into a new int vector
// v2: motivated by http://leetcodenotes.wordpress.com/2013/10/19/leetcode-longest-valid-parentheses-%E8%BF%99%E7%A7%8D%E6%8B%AC%E5%8F%B7%E7%BB%84%E5%90%88%EF%BC%8C%E6%9C%80%E9%95%BF%E7%9A%84valid%E6%8B%AC%E5%8F%B7%E7%BB%84%E5%90%88%E6%9C%89%E5%A4%9A/
// Original Post's idea: d(i) is the number of longest seq beginning with i-th parenthese
// My idea: d(i) is the number of longest seq ending at i-th parenthese
// if s[i] == '(', set d(i) = 0;
// esle if s[i] == ')': 
//                  if s[i-1]==(, ok, d[i]=d[i-2]+1;
//                  if s[i-1]==), need to check one element ahead of d[i-1] , if it is (, i.e. redundent (((((, then d[i]=d[i-1]+1  

/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

class Solution {
public:
    int longestValidParentheses(string s) 
    {
        if(s.size()<=1) {
            return 0;
        } else {
            int i;
            vector<int> d(s.size());
            d[0] = 0;
            for (i = 1; i < s.size(); i++) {
                if (s[i] == '(') {
                    d[i] = 0;
                } else {
                    //i.e. s[i]==')'
                    if (s[i-1] == '(') {
                        if (i >= 2) {
                            d[i] = d[i - 2] + 2;
                        } else {
                            d[i] = 0 + 2;
                        }
                    } else {
                        //s[i-1]==')', check redundent (((
                        //2 cases: d[i-1] start from s[0];
                        //         d[i-1] start not from s[0];  check if there is ( in front or not. and check if connects with existing sequence
                        if (d[i - 1] == i || d[i - 1] == 0) {
                            d[i] = 0;
                        } else {
                            //d[i-1]'s sequence starts from s[i-1-d[i-1]+1], one element ahead is s[i-1-d[i-1]], and
                            // need to add d[i-1-d[i-1]-1]
                            // made a mistake in test case	"()(())", forgot to count in the beginning ()
                            if (s[i-1-d[i-1]]=='(') {
                                // one more pair with redundent (
                                d[i] = d[i - 1] + 2;
                                if (i - 1 - d[i - 1] - 1 >= 0) {
                                    d[i] = d[i] + d[i - 1 - d[i - 1] - 1];
                                }
                            } else {
                                d[i] = 0;
                            }
                        }
                    }
                }
            }
            return (*max_element(d.begin(),d.end()));
        }
    }
};
