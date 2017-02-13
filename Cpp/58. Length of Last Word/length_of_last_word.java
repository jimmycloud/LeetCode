// Source : https://leetcode.com/problems/length-of-last-word/
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference:
// Idea: 

/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

public class Solution {
    public int lengthOfLastWord(String s) {
        int n = s.length();
        if (n <= 0) 
            return 0;
        
        int lastDigit = n - 1;
        while(lastDigit >= 0 && s.charAt(lastDigit)==' ') {
            lastDigit--;
        }
        if (lastDigit == -1) 
            return 0;
        int result = 0;
        for (int i = lastDigit; i >= 0; i--) {
            if (s.charAt(i) != ' ') {
                result++;
            } else {
                return result;
            }
        }
        return result;
    }
}
