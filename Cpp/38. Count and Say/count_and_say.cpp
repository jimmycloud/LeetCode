// Source : https://leetcode.com/problems/count-and-say/
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference: 
// Idea: 

/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

class Solution {
public:
    string countAndSay(int n) {
        string start = "1";
        if (n == 1) return start;
        string res = "";
        for (int i = 1; i <= n - 1; i++) {
            int ind1 = 0, ind2 = 0;
            //get the 1st seq of same numbers 
            while(ind1 <= ind2 && ind2 < start.length()) {
                if (start[ind1] == start[ind2]) { 
                    ind2++;
                    if (ind2 == start.length()) {
                        res += to_string(ind2 - 1 - ind1 + 1);
                        res += start[ind1];
                    }
                } else {
                    res += to_string(ind2 - 1 - ind1 + 1);
                    res += start[ind1];
                    ind1 = ind2;
                    ind2 = ind1;
                }
            }
            start = res;
            res="";
        }
        return start;
    }
};
