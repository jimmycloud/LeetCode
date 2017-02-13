// Source : https://leetcode.com/problems/valid-sudoku/
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference: https://leetcode.com/discuss/56681/simple-clear-java-solution
//            https://leetcode.com/discuss/17990/sharing-my-easy-understand-java-solution-using-set
// Idea: 

/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules (http://sudoku.com.au/TheRules.aspx)
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/

import java.util.*;

public class Solution {
    public boolean isValidSudoku(char[][] board) {
        //check rows and columns
        for (int i=0;i<9;i++) {
            if (checksquare(board, i, i, 0, 8) == false) return false;
            if (checksquare(board, 0, 8, i, i) == false) return false;
        }
        //check squares
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (checksquare(board, i * 3, i * 3 + 2, j * 3, j * 3 + 2 ) == false) 
                    return false;
            }
        }
        return true;
    }
    
    public boolean checksquare(char[][] board, int x1, int x2, int y1, int y2) {
        HashSet set = new HashSet();
        for (int i = x1; i <= x2; i++) {
            for (int j=y1;j<=y2;j++) {
                if (board[i][j] == '.') continue;
                if (set.add(board[i][j]) == false) return false;
            }
        }
        return true;
    }
}
