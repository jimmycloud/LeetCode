// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : Jimmy Liu
// Date   : 2017-02-11
// Reference: http://fisherlei.blogspot.com/2012/12/leetcode-longest-substring-without.html
// Idea: Use a bit vector to save the last appearance position of each character. Keep track of left bound of substring. 
//       Iterate over the string (right bound). If a character repeatly appears at i, then left is set to i+1.


/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      if (s.length() <= 1) return s.length();
      int maxLen = -1;
      vector<int> bitArray(256, -1); //map all characters to 0 to 255, and indicate the position last time it appears
      int left = 0;//left bound of the substring
      for (int i = 0; i < s.length(); i++)
      {
        if (bitArray[s[i]] < left) //i.e. current letter is not repeated after left
        {
            maxLen=max(maxLen, i-left+1);
        } else {
            left = bitArray[s[i]] + 1;
        }
        bitArray[s[i]] = i;
      }
      return maxLen;
    }
};
