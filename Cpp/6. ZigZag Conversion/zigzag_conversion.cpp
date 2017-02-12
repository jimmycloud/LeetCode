// Source : https://leetcode.com/problems/zigzag-conversion/
// Author : Jimmy Liu
// Date   : 2017-02-11
// Reference: 
// Idea: 

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

class Solution {
public:
    string convert(string s, int numRows) {
        int k = numRows, n = s.length();
        if (k == 1) return s;
        if (k == 2) {
            string res = "";
            for (int i = 0; i < n; i = i + 2) {
                res += s[i];
            }
            for (int i = 1; i < n; i = i + 2) {
                res += s[i];
            }
            return res;
        }
        //k>2 below
        string res = "";
        //add first row
        for (int j = 0; j < n; j = j + 2 * k - 2) {
            res += s[j];
        }
        for (int i = 1; i < k - 1; i++) {
            int j = i, step1 = 2 * k - 2 * (i + 1);/*<-- made a mistake here*/
            int step2 = 2 * k - 2 - step1;
            bool flag = true;
            while(j < n)
            {
                res += s[j];
                if (flag) { j = j + step1; } else {j = j + step2;}
                flag =! flag;
            }
        }
        for (int j = k - 1; j < n; j = j + 2 * k - 2) {
            res += s[j];
        }
        return res;
    }
};
