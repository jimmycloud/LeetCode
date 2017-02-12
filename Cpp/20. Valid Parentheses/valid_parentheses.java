// Source : https://leetcode.com/problems/valid-parentheses/
// Author : Jimmy Liu
// Date   : 2017-02-11
// Reference: java stack //http://docs.oracle.com/javase/7/docs/api/java/util/Stack.html
// Idea: using stack

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

import java.util.*;
public class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();// Stack stack saves strings instead of char.!!
        if (s.length()==0) return true;
        for (int i=0;i<s.length();i++)
        {
            if (s.charAt(i)=='('||s.charAt(i)=='{'||s.charAt(i)=='[')
            {
                stack.push(s.charAt(i));
            } else {
                if (stack.empty()) return false;
                if (s.charAt(i)==')'&&stack.peek()!='(') return false;
                if (s.charAt(i)=='}'&&stack.peek()!='{') return false;
                if (s.charAt(i)==']'&&stack.peek()!='[') return false;
                stack.pop();
            }
        }
        if (stack.empty()==true) return true;
        return false;
    }
}
